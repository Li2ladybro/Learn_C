//��������dt_file_caluatesimilarity
//��������ַ
//�������ͣ�int
//Function�����㲻ͬ�ļ��ظ���
//int dt_file_caluatesimilarity(char oldtitle[], char newtitle[])
//{
//	int old_title_current, new_title_current, old_title_length, new_title_length;
//	int similar_count = 0;
//	old_title_length = strlen(oldtitle) - 1;
//	new_title_length = strlen(newtitle) - 1;
//	for (new_title_current = 0; new_title_current < new_title_length; )
//	{
//		if (newtitle[new_title_current] & 0x80)//����һ�α������ַ�
//		{
//			for (old_title_current = 0; old_title_current < old_title_length; )
//			{
//				if ((newtitle[new_title_current] == oldtitle[old_title_current]) && (newtitle[new_title_current + 1] == oldtitle[old_title_current + 1]))
//				{
//					similar_count += 2;
//					break;
//				}
//				old_title_current += 2;
//			}
//			new_title_current += 2;
//		}
//		else //�Ǻ���һ�α�һ���ַ�
//		{
//			for (old_title_current = 0; old_title_current < old_title_length; old_title_current++)
//			{
//				if (newtitle[new_title_current] == oldtitle[old_title_current])
//				{
//					similar_count++;
//					break;
//				}
//			}
//			new_title_current++;
//		}
//	}
//	return similar_count * 100 / new_title_length;
//}

#include<stdio.h>
#include"string.h"

int main()
{
	

	char arr[200] = " ���ļ���Ŀһ����11�У��հ�����3�����ļ���Ŀһ����11�У��հ�����3��*********************************";
}