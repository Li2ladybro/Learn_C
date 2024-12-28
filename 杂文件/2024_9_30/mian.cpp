//////#include <iostream>
//////using namespace std;
//////
//////class Date
//////{
//////public:
//////	Date(int year=0, int month=1,int day=1)
//////		:_year(year),_month(month),_day(day)
//////	{
//////		_num++;
//////		cout << "Date(int year=0, int month=1,int day=1)\n";
//////	}
//////
//////	Date(Date& d)
//////	{
//////		_num++;
//////		_year = (d._year);
//////		_month = (d._month);
//////		_day = (d._day);
//////	}
//////
//////	~Date()
//////	{
//////		//
//////	}
//////	void Func1()
//////	{
//////		this->_month;
//////		//
//////	}
//////
//////	static const int& GetNum()
//////	{
//////		return _num;
//////	}
//////
//////private:
//////	int _year;
//////	int _month;
//////	int _day;
//////	static int _num;
//////};
//////
//////int Date::_num = 0;
//////
//////Date& Func(Date& d)
//////{
//////	return d;
//////}
//////
//////
//////int main()
//////{
//////	//Date d1(2,3,4);
//////	//Date d2;
//////	//Func(d1);
//////	//Func(d2);
//////	////cout << Date::_num;
//////	////cout << d1.num;
//////
//////	//cout << Date::GetNum() << endl;  // 在类域中可以直接访问       
//////	//cout << d1.GetNum()<<endl;       // 也可以对象访问
//////	////cout << GetNum();
//////	////cout << Date::Func1();         // 在类域中可以直接访问 
//////	//// 
//////
//////	//size_t se = 10;
//////	//long long* nb = (long long*)malloc(sizeof(long long) * se * 10e12);
//////	//cout << nb << endl;
//////	// 
//////	////long long* num = new long long (se*10e12);
//////
//////	//while(1)
//////	//{
//////	//	long long* num = new long long(se * 1024e20);
//////	//	cout << num << endl;
//////
//////	//}
//////
//////	Date* p1 = new Date[10];
//////	//p1->Func1
//////
//////	//p1->~Date
//////
//////	delete[] p1;
//////
//////	/*unsigned long long N = (long long )1024* 1024 * 1024 * 1024;
//////
//////	long long* num = new long long[N];*/
//////
//////
//////
//////	try 
//////	{
//////		unsigned long long N = (long long)1024 * 1024 * 1024 * 1024;
//////
//////		long long* p2 = new long long[N];
//////	}
//////
//////	catch (exception& e)
//////	{
//////		cout << e.what();
//////	}
//////
//////
//////	return 0;
//////
////#include<iostream>
////#include<string>
////using namespace std;
////
////
////int main()
////{
////
////
////	/*for (int start = 0; start < s1.size(); start++)
////	{
////		cout << s1[start] << " ";
////	}*/
////
////	/*for (auto& e : s1)
////	{
////		e = '3';
////	}
////
////	for (int start = 0; start < s1.size(); start++)
////		{
////			cout << s1[start] << " ";
////		}*/
////
////
////	string s1 = "123456";
////	int sum = 0;
////	for (auto& e : s1)
////	{
////		sum *= 10;
////		sum += e-'0';
////	}
////	cout << sum;
////	size_t
////
////	return 0; 
////}
//
//#include<iostream>
//using namespace std;
//int main()
//{
//	/*for (int i = 0; i < 256; ++i)
//	{
//		printf("%c ", i);
//	}*/
//
//	/*for (int i = 0; i < 128; ++i)
//	{
//		printf("%c ", i);
//	}*/
//
//	for (char i = 0;i>=0&& i <=127; ++i)
//	{
//		printf("%c ", i);
//	}
//	cout << endl << "____________________________" << endl;
//
//	for (char i = -127;i <=0 ; ++i)
//	{
//		printf("%c ", i);
//	}
//	cout << "____________________________" << endl;
//
//
//	return 0;
//}



#include <iostream>
using namespace std;

#include<string>

//int main()
//{
//    string s;
//    getline(cin, s);
//    int start_post = s.rfind(' ');
//    int last_post = s.size() - 1;
//    cout<< last_post - start_post;
//    return 0;
//}

class Solution 
{
public:
    void convert_to_short(string& s) {
        for (auto& e : s)
        {
            if ('A' <= e && e <= 'Z') 
            {
                e += ('a' - 'A');
            }
        }
        return;
    }
    bool isPalindrome(string s) {
        convert_to_short(s);
        int begin = 0, end = s.size() - 1;
        while (begin < end) {
            while (!('a' <= s[begin] && s[begin] <= 'z') && begin < end) {
                ++begin;
            }
            while (!('a' <= s[end] && s[end] <= 'z') && begin < end) {
                --end;
            }
            if (s[end] != s[begin])
                return false;
            else
            {
                ++begin; --end;
            }
        }
        return true;
    }
};

int main()
{
    string s("A man, a plan, a canal: Panama");
    Solution s1;
    s1.isPalindrome(s);
    return 0;

    int end1 = end2 = 0
}