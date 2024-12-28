#include <iostream>
#include <string>
using namespace std;

void main ()
{
	int all_count = 10;
	int start = 1;
	const char* arr[] =
	{
		"基于单片机的智能天然气检测与报警系统设计",
		"基于单片机的智能晾衣控制系统的设计",
		"中、小型企业高速局域网方案设计	",
		"图书馆座位预定系统的设计",
		"《C语言程序设计》课程网站的设计与实现",
		"基于校园网络SAN存储系统设计",
		"基于Java的医院挂号诊疗系统的设计与实现",
		"基于STC89C52单片机的多功能智能床头小夜灯设计",
		 "一种家庭智能药箱系统的设计",
		"田间监控管理系统的设计与实现",
		"数字跳棋游戏的设计与实现",
		"学生考勤系统的设计与实现",
		"基于Java的健身俱乐部管理系统的设计与实现",
		"基于单片机的多功能衣柜设计",
		"基于Java的ATM机管理信息系统的分析与设计"
	};
	
	while (start <= all_count)
	{


		///*std::string str = "xiao";
		//CString cstr(str.c_str());*/

		//// CString转化为string
		///*string str_img_path =
		//	(LPCSTR)(CStringA)(m_str_new);*/

		//file_resulet_print_edit = (arr[start].c_str());
		//file_resulet_print_edit.SetWind(file_output_str);
		/*printf(arr[start]);*/
		start++;
		printf("%s\n",arr[0]);
	}

}