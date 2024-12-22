#include"contact.h"
int main()
{
	int input = 0;
    //con就是通讯录可以存放1000人信息，size记录当前人数
	Contact con;
	//初始化通讯录
	Init_Contact(&con);
	do
	{
		menu();
		printf("请选择:>");
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
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
    return 0;
}