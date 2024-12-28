#include "TitleCheckFileOperate.h"

// ��������init_file_data
// ������File_data*
// �������ͣ�void
// Function����ʼ���ļ�����
void init_file_data(file_data* ps) 
{
    ps->_breadth = 100;  // һ��100�ֽ�
    ps->_capacity = 500; // ��ʼ�ļ�����Ĭ������Ϊ500��
    ps->_titles =(char(*)[100])malloc(sizeof(char) * ps->_capacity * ps->_breadth);
    if (ps->_titles == NULL) 
    {
        exit(1);
    }
    else 
    {
        memset(ps->_titles, 0, sizeof(char) * ps->_capacity * ps->_breadth);
        ps->_current_line_count = 0;
    }
    return;
}

// ��������write_file_to_array
// ��������ַ���ļ�����ַ����ŵ�ַ
// �������ͣ�void
// Function������Ŀд�����鲢�����ļ�����
void write_file_to_array(FILE* f, file_data* ps) 
{
    char forcecasting = 0;
    while ((forcecasting = fgetc(f)) != EOF) 
    {
        if (forcecasting == '\n') 
        {
            ps->_current_line_count++;
        }
    }

    ps->_current_line_count++;

    rewind(f);

    if (ps->_capacity <= ps->_current_line_count) 
    {
        ps->_capacity = (int)1.5 * ps->_current_line_count;
        free(ps->_titles); // �ͷžɿռ�
        ps->_titles = (char(*)[100])malloc(sizeof(char) * ps->_capacity *ps->_breadth); // ����������ڴ�
        memset(ps->_titles, 0 , sizeof(char) * ps->_capacity * ps->_breadth);           // ����������ڴ�
    }
    for (int rank = 0; rank < ps->_current_line_count; rank++) 
    {
        fgets(ps->_titles[rank], 100, f);
        if (rank == ps->_current_line_count - 1) 
        {
            // ��֤����һ��������\n����
            if (ps->_titles[rank][0] == '\0') 
            {
                // �����Ŀ�ļ����һ���л��з������һ���Ի��з����棬��ֹ�洢�����һ�����ݿմ�
                ps->_titles[rank][0] = '\n';
                ps->_titles[rank][1] = '\0';
            }

            if (ps->_titles[rank][(strlen(ps->_titles[rank]) - 1)] != '\n') 
            {
                // ���һ���ַ����ǻ��������\n���������ݴ���
                ps->_titles[rank][strlen(ps->_titles[rank])] = '\n';
                ps->_titles[rank][strlen(ps->_titles[rank]) + 1] = '\0';
            }
        }
    }
    return;
}

// ��������bk_caluate
// ��������ַ������
// ����ֵ������
// Function��ͳ�ƿհ���
int bk_caluate(file_data* ps) 
{
    char reset_arry[2] = { '\n', '\0' };
    int count = 0;
    int bk_count = 0;
    for (count = 0; count < ps->_current_line_count; count++) 
    {
        if (strcmp((ps->_titles)[count], reset_arry) == 0)
            bk_count++;
    }
    return bk_count;
}

// ����ͬһ�ļ��µ��ظ���
// �������� se_file_caluatesimilarity
// ������File_data* ����Ŀ��ַ; int���հ�����Ŀ
// �������ͣ�int
// Function������ͬһ�ļ��ظ���
int se_file_caluatesimilarity(file_data* ps, int bk_count) 
{
    int count1 = 0;                         // �����һ����Ŀ��
    int count2 = 0;                         // �ұ�һ����Ŀһһ�Ƚ�
    int sm_count = 0;
    char reset_arry[2] = { '\n', '\0' };    // �ĵ�����
    for (count1 = 0; count1 < ps->_current_line_count; count1++) 
    {
        if (strcmp((ps->_titles)[count1], reset_arry) == 0)
            continue; // �������Ϊ�հ���������������һ����Ŀ
        for (count2 = 0; count2 < ps->_current_line_count; count2++) 
        {
            // ����������ĿҲΪ�հ�������������������һ����Ŀ||�����Ŀͬ�еĲ����Ƚ�->û����
            if ((strcmp((ps->_titles)[count2], reset_arry) == 0) ||
                (count1 == count2))
                continue;
            // ֻҪ�ҵ�һ����֮��ͬ����Ŀֱ���˳�ѭ����������һ����Ŀ����
            if (strcmp((ps->_titles)[count1], (ps->_titles)[count2]) == 0) 
            {
                // ����������Ŀ���бȽϣ�����һ�����ַ�
                sm_count++;
                break;
            }
        }
    }
    // һ������Ŀ/�ܵ���Ŀ��Ŀ���������հ��У�
    return sm_count * 100 /(ps->_current_line_count-bk_count); 
}

// ��������dt_file_caluatesimilarity
// ��������ַ
// �������ͣ�int
// Function�����㲻ͬ�ļ��ظ���
int dt_file_caluatesimilarity(char oldtitle[], char newtitle[]) 
{
    int old_title_current, new_title_current, old_title_length,new_title_length;
    int similar_count = 0;
    old_title_length = strlen(oldtitle);
    new_title_length = strlen(newtitle);
    for (new_title_current = 0;
        new_title_current < new_title_length - 1;) // ���һ��\n�����Ƚ�
    {
        if (newtitle[new_title_current] & 0x80) // ����һ�α������ַ�
        {
            for (old_title_current = 0;
                old_title_current <
                old_title_length - 1;) // ���һ��\n�����Ƚ�
            {
                if ((newtitle[new_title_current] == oldtitle[old_title_current])
                    &&
                    (newtitle[new_title_current + 1] ==oldtitle[old_title_current + 1]))
                {
                    similar_count += 2;
                    break;
                }
                old_title_current += 2;
            }
            new_title_current += 2;
        }
        else // �Ǻ���һ�α�һ���ַ�
        {
            for (old_title_current = 0;
                old_title_current < old_title_length - 1;
                old_title_current++) // ���һ��\n�����Ƚ�
            {
                if (newtitle[new_title_current] ==
                    oldtitle[old_title_current]) 
                {
                    similar_count++;
                    break;
                }
            }
            new_title_current++;
        }
    }

    return similar_count * 100 / ((old_title_length > new_title_length ? old_title_length : new_title_length) - 1);
}

// ��������obtaine_check_result_and_write_to_file
// ������const file_data* ������Ŀ��ַ��const file_data* ������Ŀ��ַ;
//       FILE* ��Ҫд���ļ����ļ�ָ��;
//       const int������ظ���;
//       char* ���Ƿ���Ҫ�����ļ�����;
//       const int������Ŀ�ļ��հ��У�const int������Ŀ�ļ��ظ���;
//       const int������Ŀ�ļ��հ��У�const int������Ŀ�ļ��ظ���;
//
// �������ͣ�void
// Function���ó����ؽ�����ѽ��д��Output_file.txt�ļ�
void obtaine_check_result_and_write_to_file(
    const file_data* oldtitle, const file_data* newtitle, FILE* pi,
    const int& max_repetition, const char* if_self_check,
    const int& old_bk_count, const int& old_se_file_similarity,
    const int& new_bk_count, const int& new_se_file_similarity) 
{
    int new_title_count = 0;
    int old_title_count = 0;
    char reset_arry[2] = { '\n', '\0' };    // �ĵ�����
    char fprint_new_tile_flag = 0;          // ���ڱ������Ŀ�Ƿ�д�����
    int similarity = 0;                     // ����ظ���
    int count = 0;                          // ����ַ�λ
    int old_title_length = 0;               // ����ַ�����
    const char* aim = "��";                 // �Ƿ���Ҫ�����ļ�����
    int if_write_content = 0;               // ����Ƿ�������ļ�д������

    if (strcmp(aim, if_self_check) == 0) 
    {
        // ��д�������Ϣ
        fprintf(pi, "���ļ���Ŀһ����%d�У��հ�����%d��,�ظ�����:%d%%\n",
            oldtitle->_current_line_count, old_bk_count, old_se_file_similarity);
        fprintf(pi, "���ļ���Ŀһ����%d�У��հ�����%d��,�ظ�����:%d%%\n",
            newtitle->_current_line_count, new_bk_count, new_se_file_similarity);
        fprintf(pi, "****************************************************\n");
    }
    else
    {
        fprintf(pi, "���ļ���Ŀһ����%d�У��հ�����%d��\n",
            oldtitle->_current_line_count, old_bk_count);
        fprintf(pi, "���ļ���Ŀһ����%d�У��հ�����%d��\n",
            newtitle->_current_line_count, new_bk_count);
        fprintf(pi, "****************************************************\n");
    }

    for (new_title_count = 0; new_title_count < newtitle->_current_line_count;
        new_title_count++) 
    {

        if (strcmp((newtitle->_titles)[new_title_count], reset_arry) == 0)
            continue; // �����հ���
        fprint_new_tile_flag = 1;
        for (old_title_count = 0;
            old_title_count < oldtitle->_current_line_count;
            old_title_count++) 
        {
            if (strcmp((oldtitle->_titles)[old_title_count], reset_arry) == 0)
                continue; // �����հ���
            similarity = dt_file_caluatesimilarity(
                (oldtitle->_titles)[old_title_count],
                (newtitle->_titles)[new_title_count]); // �õ��ظ���
            old_title_length = strlen((oldtitle->_titles)[old_title_count]);
            if (similarity > max_repetition) 
            {
                if_write_content = 1;

                // �����Ŀ�ظ�������Ŀֻ��ӡһ��
                if (1 == fprint_new_tile_flag) 
                {
                    fprintf(pi, "\n%d������Ŀ:%s", new_title_count + 1,
                        (newtitle->_titles)[new_title_count]);
                    fprint_new_tile_flag = 0;
                }

                fprintf(pi, "%d�ž���Ŀ:", old_title_count + 1);
                for (count = 0; count < old_title_length - 1; count++) 
                {
                    // Ĭ�ϲ���Ҫ�����һ��\n��ӡ��
                    fputc((oldtitle->_titles)[old_title_count][count], pi);
                }

                fprintf(pi, "------�ظ��ʣ�%d%%\n", similarity);
            }
        }
    }

    if (if_write_content == 0) 
    {
        // ���û��д�����ݸ�������
        fprintf(pi, "\n������Ŀ�Կ�ͨ����ǰ���õĲ�����\n");
    }

    return;
}