#include"Date.h"

int& Date::GetMonthDay(const int& year, const int& month) const
{
	// 获取日
	static int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		// 四年一闰，百年不闰，400年一闰
		arr[2] = 29;
	}
	else
	{
		arr[2] = 28;
	}
	return arr[month];
}

Date::Date(const int& year , const int& month  , const int& day)
	:_year(year), _month(month), _day(day)

{
	// 构造函数
	if (year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "请输入合法日期\n";
	}
	return;
}

Date::Date(const Date& d)
{
	// 拷贝构造
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return;
}

Date::~Date()
{
	// 析构函数
}

Date& Date::operator=(const Date& d)
{
	// 赋值函数
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

// 取地址重载
Date* Date::operator &()
{
	return this;
}

// 取地址重载
const Date* Date::operator &() const
{
	return this;
}

Date Date::operator+(const int& day) const
{
	if (day < 0)
	{
		// d1-100
		Date temp = *this - (-day);
		return temp;
	}

	Date temp(*this);
	temp._day += day;
	while (temp._day > GetMonthDay(temp._year, temp._month))
	{
		temp._day -= GetMonthDay(temp._year, temp._month);
		temp._month++;
		if (temp._month == 13)
		{
			temp._month = 1;
			temp._year++;
		}
	}
	return temp;
}

// d1+=100
Date& Date::operator+=(const int& day)
{
	*this = (*this + day);
	return *this;
}

// d2-100
Date Date::operator-(const int& day) const
{
	if (day < 0)
	{
		// d2+100
		Date temp(*this);
		temp._day += -day;
		return temp;
	}

	Date temp(*this);
	temp._day -= day;

	while (temp._day <= 0)
	{
		temp._month--;

		if (temp._month == 0)
		{
			temp._month = 12;
			temp._year--;
		}

		temp._day += GetMonthDay(temp._year, temp._month);
	}

	return temp;
}

// d1-d2
int Date::operator-(const Date& d)const
{
	Date max = *this;
	Date min = d;

	int flag = 1;
	if (max < min)
	{
		flag = -1;
		max = d;
		min = *this;
	}

	int num = 0;

	while (min != max)
	{
		++num;
		++min;
	}

	return num * flag;
}

// d2-=100
Date& Date::operator-=(const int& day)
{
	*this = (*this - day);
	return *this;
}

// ++d2
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// d2++
Date Date::operator++(int)
{
	Date temp = *this;
	*this += 1;
	return temp;
}

// --d2
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// d2--
Date Date::operator--(int)
{
	Date temp = *this;
	*this -= 1;
	return temp;
}

// 比较大小之运算符重载

// d1==d2
bool Date::operator==(const Date d) const
{
	return _year == d._year && _month == d._month && _day == d._day;
}

// d1!=d2
bool Date::operator!=(const Date d)const
{
	return !(*this == d);
}

// d1>d2
bool Date::operator>(const Date& d)const
{
	if (_year > d._year)
	{
		return true;
	}

	if (_year == d._year && _month > d._month)
	{
		return true;
	}

	if (_year == d._year && _month == d._month && _day > d._day)
	{
		return true;
	}

	return false;
}

// d1>=d2
bool Date::operator>=(const Date& d)const
{
	return *this > d || *this == d;
}

// d1<d2
bool Date::operator<(const Date d)const
{
	return !(operator>=(d));
}

// d1<=d2
bool Date::operator<=(const Date& d)const
{
	return *this == d || *this < d;
}

// cin >> d;
istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

// cout<<d
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << '-' << d._month << '-' << d._day;
	return out;
}



void Date::Print()const
{
	cout << _year << '-' << _month << '-' << _day << endl;
	return;
}