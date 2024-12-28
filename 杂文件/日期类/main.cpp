#include"Date.h"

int main()
{

	//Date d1(24567890, 5, 9);

	//Date d4(24567890, 5, 1);

	//cout << (d1 - d4) << endl;
	//Date d2 = d1; // 拷贝构造
	//Date d3(d2);  // 拷贝构造
	//d3 = d1;	  // 赋值 
	//d3.Print();
	//d1.Print();
	//d2.Print();
	//cout << "____________________________________" << endl;
	//(d3 - 10).Print();
	//(d3 += 20).Print();
	//d3.Print();
	//cout << "____________________________________" << endl;
	//d3 = d2 = d1;
	//d3 += -20;
	//d3.Print();
	//cout << "____________________________________" << endl;
	//d3--;
	//d3++;
	//d3.Print();
	//++d3;

	Date d1;
	Date d2;
	cin >> d1 >> d2;  // operator>>((operator>>(cin,d1)),d2);
	cout << d1 <<endl<< d2; // operator<<((operatir<<(cout,d1)),d2)


	return 0;
}