#include <iostream>
#include <string>
using namespace std;

void main ()
{
	int all_count = 10;
	int start = 1;
	const char* arr[] =
	{
		"���ڵ�Ƭ����������Ȼ������뱨��ϵͳ���",
		"���ڵ�Ƭ�����������¿���ϵͳ�����",
		"�С�С����ҵ���پ������������	",
		"ͼ�����λԤ��ϵͳ�����",
		"��C���Գ�����ơ��γ���վ�������ʵ��",
		"����У԰����SAN�洢ϵͳ���",
		"����Java��ҽԺ�Һ�����ϵͳ�������ʵ��",
		"����STC89C52��Ƭ���Ķ๦�����ܴ�ͷСҹ�����",
		 "һ�ּ�ͥ����ҩ��ϵͳ�����",
		"����ع���ϵͳ�������ʵ��",
		"����������Ϸ�������ʵ��",
		"ѧ������ϵͳ�������ʵ��",
		"����Java�Ľ�����ֲ�����ϵͳ�������ʵ��",
		"���ڵ�Ƭ���Ķ๦���¹����",
		"����Java��ATM��������Ϣϵͳ�ķ��������"
	};
	
	while (start <= all_count)
	{


		///*std::string str = "xiao";
		//CString cstr(str.c_str());*/

		//// CStringת��Ϊstring
		///*string str_img_path =
		//	(LPCSTR)(CStringA)(m_str_new);*/

		//file_resulet_print_edit = (arr[start].c_str());
		//file_resulet_print_edit.SetWind(file_output_str);
		/*printf(arr[start]);*/
		start++;
		printf("%s\n",arr[0]);
	}

}