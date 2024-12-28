#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	int& GetMonthDay(const int& year, const int& month) const;
	 
	// ���캯��
	Date(const int& year = 0, const int& month = 1, const int& day = 1);

	// ��������
	Date(const Date& d);
	 
	// ��������
	~Date();
	 
	// ��ֵ����
	// d1=d2
	Date& operator=(const Date& d);

	// ȡ��ַ����
	Date* operator &();

    // const ȡ��ַ����
	const Date* operator &( ) const;
 
	// �����֮����
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
	 

	// �Ƚ������֮���������

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
	 

	// �����������

	friend istream& operator>>(istream& in ,Date& d);
	friend ostream& operator<<(ostream& out,const Date& d);

	void Print()const;
	 

private:
	int _year;
	int _month;
	int _day;

};
