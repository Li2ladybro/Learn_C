#include"Seq_List.h"
static void Test_Seq_list()
{
	Seq_list* ps = (Seq_list*)malloc(sizeof(Seq_list));
	Inint_Seq_list(ps); 
	Insert_SeqList(ps, 1,54);
	Insert_SeqList(ps, 1,4);
	Insert_SeqList(ps, 1, 44);
	Delete_SeqList(ps,3 );
	Print_Seq_List(ps);
	Find_elem(ps, 44);
	Destory_Seq_List(ps);
	Print_Seq_List(ps);
}
int main()
{
	Test_Seq_list();
	return 0;
}