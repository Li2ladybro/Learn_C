#include"contact.h"
int main()
{
	int input = 0;
    //con����ͨѶ¼���Դ��1000����Ϣ��size��¼��ǰ����
	Contact con;
	//��ʼ��ͨѶ¼
	Init_Contact(&con);
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			Add_Contact(&con);
			break;
		case del:
			Del_Contact(&con);
			break;
		case search:
			/*exit = 0,
			add = 1,
			del = 2,
			search = 3,
			 = 4,
			show = 5:*/
			Search_Contact(&con);
			break;
		case modify:
			Modify(&con);
			break;
		case show :
			Show_Contact(&con);
			break;
		case 0:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (input);
    return 0;
}