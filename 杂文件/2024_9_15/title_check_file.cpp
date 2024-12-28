#include"title_check_file.h"
#include "2024_9_15Dlg.h"
//��������inint_file_data
//������File_data*
//�������ͣ�void 
//Function����ʼ���ļ�����
void inint_file_data(File_data* ps)
{
	ps->_breadth = 100;               // һ��100�ֽ�
	ps->_capacity = 500;              // ��ʼ�ļ�����Ĭ������Ϊ500��
	ps->_titles = (char(*)[100])malloc(sizeof(char) * ps->_capacity * ps->_breadth);    //����������ڴ�
	if (ps->_titles == NULL)
	{
		printf("����ռ�ʧ�ܣ��˳�����\n");
		exit(1);
	}
	else
	{
		memset(ps->_titles, 0, sizeof(char) * ps->_capacity * ps->_breadth);
		ps->_current_line_count = 0;
	}
}

//��������write_file_to_array
//��������ַ���ļ�����ַ����ŵ�ַ
//�������ͣ�int
//Function������Ŀд�����鲢�����ļ�����
void write_file_to_array(FILE* f, File_data* ps)
{
	int rank = 0;
	int forcecasting = 0;
	while ((forcecasting = fgetc(f)) != EOF)
	{
		if (forcecasting == '\n')
		{
			ps->_current_line_count++;
		}

	}
	rewind(f);
	if (ps->_capacity <=ps->_current_line_count++)
	{
		ps->_capacity = 1.5* ps->_current_line_count;
		free(ps->_titles);    // �ͷžɿռ�
		ps->_titles = (char(*)[100])malloc(sizeof(char) * ps->_capacity * ps->_breadth);    //����������ڴ�
		memset(ps->_titles, 0, sizeof(char) * ps->_capacity * ps->_breadth);
		//malloc(ps->_titles, sizeof(char) * ps->_capacity * ps->_breadth);    //����������ڴ�
		//printf("���ڴ濪�ٳɹ�\n");
	}
	for (rank = 0; rank < ps->_current_line_count; rank++)
	{
		fgets(ps->_titles[rank],100, f);
	}
	//return ps->_Current_line_count;
}

//��������bk_caluate
//��������ַ������
//����ֵ������
//Function��ͳ�ƿհ���
int bk_caluate(File_data* ps)
{
	char reset_arry[2] = "\n";
	int count = 0;
	int bk_count = 0;
	for (count = 0; count < ps->_current_line_count; count++)
	{
		if (strcmp((ps->_titles)[count], reset_arry) == 0)
			bk_count++;
	}
	return bk_count;
}

//����ͬһ�ļ��µ��ظ���
// �������� se_file_caluatesimilarity
//������File_data* ����Ŀ��ַ; int���հ�����Ŀ
//�������ͣ�int
//Function������ͬһ�ļ��ظ���
int se_file_caluatesimilarity(File_data* ps, int bk_count)
{
	int count1 = 0;      //�����һ����Ŀ��
	int count2 = 0;      //�ұ�һ����Ŀһһ�Ƚ�
	int similarity = 0;
	int sm_count = 0;
	char reset_arry[2] = "\n";//�ĵ�����
	for (count1 = 0; count1 < ps->_current_line_count; count1++)
	{
		if (strcmp((ps->_titles)[count1], reset_arry) == 0)
			continue;          //�������Ϊ�հ���������������һ����Ŀ
		for (count2 = 0; count2 < ps->_current_line_count; count2++)
		{
			//����������ĿҲΪ�հ�������������������һ����Ŀ||�����Ŀͬ�еĲ����Ƚ�->û����
			if ((strcmp((ps->_titles)[count1], reset_arry) == 0) || (count1 == count2))
				continue;
			//ֻҪ�ҵ�һ����֮��ͬ����Ŀֱ���˳�ѭ����������һ����Ŀ����
			if (strcmp((ps->_titles)[count1], (ps->_titles)[count2]) == 0)   // ����������Ŀ���бȽϣ�����һ�����ַ�
			{
				sm_count++;
				break;
			}
		}
	}
	return  sm_count * 100 / (ps->_current_line_count - bk_count);   //һ������Ŀ/�ܵ���Ŀ��Ŀ���������հ��У�
}

//��������dt_file_caluatesimilarity
//��������ַ
//�������ͣ�int
//Function�����㲻ͬ�ļ��ظ���
int dt_file_caluatesimilarity(char oldtitle[], char newtitle[])
{
	int old_title_current, new_title_current, old_title_length, new_title_length;
	int similar_count = 0;
	old_title_length = strlen(oldtitle) - 1;
	new_title_length= strlen(newtitle)- 1;
	for (new_title_current = 0; new_title_current < new_title_length; )
	{
		if (newtitle[new_title_current] & 0x80)//����һ�α������ַ�
		{
			for (old_title_current = 0; old_title_current < old_title_length; )
			{
				if ((newtitle[new_title_current] == oldtitle[old_title_current]) && (newtitle[new_title_current + 1] == oldtitle[old_title_current + 1]))
				{
					similar_count += 2;
					break;
				}
				old_title_current += 2;
			}
			new_title_current += 2;
		}
		else //�Ǻ���һ�α�һ���ַ�
		{
			for (old_title_current = 0; old_title_current < old_title_length; old_title_current++)
			{
				if (newtitle[new_title_current] == oldtitle[old_title_current])
				{
					similar_count++;
					break;
				}
			}
			new_title_current++;
		}
	}
	return similar_count * 100 / new_title_length;
}

//��������obtaine_check_result_and_write_to_file
//������File_data* ������Ŀ��ַ;File_data* ������Ŀ��ַ;FILE* ��Ҫд���ļ��ĵ�ַ��int������ظ���
//�������ͣ�void
//Function���ó����ؽ�����ѽ��д��Output_file.txt�ļ�
void obtaine_check_result_and_write_to_file
(
	File_data* oldtitle,
	File_data* newtitle,
	FILE* pi, 
	int max_repetition,
	int old_bk_count,
	int old_se_file_similarity,
	int new_bk_count,
	int new_se_file_similarity
)
{
	int new_title_count = 0;
	int old_title_count = 0;
	char reset_arry[2] = "\n";                   //�ĵ�����
	char fprint_new_tile_flag = 0;               //���ڱ������Ŀ�Ƿ�д�����
	int similarity = 0;                          //����ظ���
	int count = 0;                               //����ַ�λ
	int old_title_length = 0;                    //����ַ�����

	//��д�������Ϣ
	fprintf(pi, "���ļ���Ŀһ����%d�У��հ�����%d��,�ظ�����:%d%%��\n",oldtitle->_current_line_count,old_bk_count,old_se_file_similarity);
	fprintf(pi, "���ļ���Ŀһ����%d�У��հ�����%d��,�ظ�����:%d%%��\n",newtitle->_current_line_count,new_bk_count,new_se_file_similarity);
	fprintf(pi, "****************************************************\n");

	for (new_title_count = 0; new_title_count < newtitle->_current_line_count; new_title_count++)
	{

		if (strcmp((newtitle->_titles)[new_title_count], reset_arry) == 0)
			continue;        //�����հ���
		fprint_new_tile_flag = 1;
		for (old_title_count = 0; old_title_count < oldtitle->_current_line_count; old_title_count++)
		{
			if (strcmp((oldtitle->_titles)[new_title_count], reset_arry) == 0)
				continue;    //�����հ���
			similarity = dt_file_caluatesimilarity((oldtitle->_titles)[old_title_count], (newtitle->_titles)[new_title_count]);//�õ��ظ���
			old_title_length = strlen((oldtitle->_titles)[old_title_count]) - 1;
			if (similarity > max_repetition)
			{
				//�����Ŀ�ظ�������Ŀֻ��ӡһ��
				if (1 == fprint_new_tile_flag)
				{
					fprintf(pi, "\n%d������Ŀ:%s", new_title_count + 1, (newtitle->_titles)[new_title_count]);
					fprint_new_tile_flag = 0;
				}
				fprintf(pi, "%d�ž���Ŀ:", old_title_count + 1);
				for (count = 0; count < old_title_length; count++)
				{
					fputc((oldtitle->_titles)[old_title_count][count], pi);
				}
				fprintf(pi, "------�ظ��ʣ�%d%%\n", similarity);
			}
		}
	}
}