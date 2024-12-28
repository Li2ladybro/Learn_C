#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	int& GetMonthDay(const int& year, const int& month) const;
	 
	// 构造函数
	Date(const int& year = 0, const int& month = 1, const int& day = 1);

	// 拷贝构造
	Date(const Date& d);
	 
	// 析构函数
	~Date();
	 
	// 赋值重载
	// d1=d2
	Date& operator=(const Date& d);

	// 取地址重载
	Date* operator &();

    // const 取地址重载
	const Date* operator &( ) const;
 
	// 运算符之重载
	// d1+100
	Date operator+(const int& day) const;
	 

	// d1+=100
	Date& operator+=(const int& day);
	 

	// d2-100
	Date operator-(const int& day)const;


	// d1-d2
	int operator-(const Date& d)const;


	// d2-=100
	Date& operator-=(const int& day);
	 

	// ++d2
	Date& operator++();
	 

	// d2++
	Date operator++(int);
	 
	// --d2
	Date& operator--();
	 

	// d2--
	Date operator--(int);
	 

	// 比较运算符之运算符重载

	// d1==d2
	bool operator==(const Date d)const;
	 

	// d1!=d2
	bool operator!=(const Date d)const;
	 
	// d1>d2
	bool operator>(const Date& d)const;
	 

	// d1>=d2
	bool operator>=(const Date& d)const;
	 

	// d1<d2
	bool operator<(const Date d)const;
	 

	// d1<=d2
	bool operator<=(const Date& d)const;
	 

	// 输入输出重载

	friend istream& operator>>(istream& in ,Date& d);
	friend ostream& operator<<(ostream& out,const Date& d);

	void Print()const;
	 

private:
	int _year;
	int _month;
	int _day;

};
