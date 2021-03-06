#include "main.h"


/*
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		cout << "Time()" << endl;
		_hour = 0;
		_mintue = 0;
		_second = 0;
	}
private:
	int _hour;
	int _mintue;
	int _second;
};

class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

class String
{
public:
	String(const char *str)
	{
		_str = (char *)malloc(strlen(str) + 1);
		assert(_str);
		strcpy(_str, str);
	}
	~String()
	{
		free(_str);
	}
private:
	char *_str;
};

void TestClass()
{
	Date d1(2020, 9, 18);
	Date d2 = d1;
}
*/

/*
class Date
{
public:
	Date(int year = 2020, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "拷贝构造函数" << "---" << this << endl;
	}
	~Date()
	{
		cout << "析构函数" << "---" << this <<  endl;
 	}
	//Date DateAdd(int days)
	//{
	//	Date temp(*this);
	//	temp._day += days;
	//	return temp;
	//}
	//Date operator+(int days)
	//{
	//	Date temp(*this);
	//	temp._day += days;
	//	return temp;
	//}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	//运算符+=重载
	Date& operator+=(int days)
	{
		_day += days;
		return *this;
	}

	//运算符+重载
	Date operator+(int days)
	{
		Date temp(*this);
		temp._day += days;
		return temp;
	}

	//运算符-=重载
	Date& operator-=(int days)
	{
		_day -= days;
		return *this;
	}

	//运算符-重载
	Date operator-(int days)
	{
		Date temp(*this);
		temp._day -= days;
		return temp;
	}

	// 前置++
	Date& operator++()
	{
		_day++;
		return *this;
	}

	//后置++
	Date operator++(int)//必须要加int，语法规定
	{
		Date temp(*this);
		_day++;
		return temp;
	}

	// 前置--
	Date& operator--()
	{
		_day--;
		return *this;
	}

	//后置--
	Date operator--(int)//必须要加int，语法规定
	{
		Date temp(*this);
		_day--;
		return temp;
	}

	//运算符>重载
	bool operator>(const Date& d)const//加const，让this指针的成员变量不能被修改
	{
		return (_year < d._year) || 
			(_year == d._year && _month < d._month) || 
			(_year == d._year && _month == d._month && _day < d._day);
	}

	//运算符>=重载
	bool operator>=(const Date& d)const//加const，让this指针的成员变量不能被修改
	{
		return (_year <= d._year) ||
			(_year == d._year && _month <= d._month) ||
			(_year == d._year && _month == d._month && _day <= d._day);
	}

	//运算符<重载
	bool operator<(const Date& d)const//加const，让this指针的成员变量不能被修改
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}

	//运算符<=重载
	bool operator<=(const Date& d)const//加const，让this指针的成员变量不能被修改
	{
		return (_year >= d._year) ||
			(_year == d._year && _month >= d._month) ||
			(_year == d._year && _month == d._month && _day >= d._day);
	}

	//运算符==重载
	bool operator==(const Date& d)const//加const，让this指针的成员变量不能被修改
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	//运算符!=重载
	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}

	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const
	{
		return this;
	}
private:
	int _year;
	int _month;
	int _day;
};

*/

/*
class Time
{
public:
	Time(int hour, int mintue=10, int second=10)
		:_hour(hour)
		,_minute(mintue)
		,_second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};



class Date
{
	friend const void Print(Date& d);//友元函数
	friend ostream&  operator<<(ostream& _cout, Date& d);
public:
	Date(int year, int month, int day)//构造函数
		: _year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout,Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
*/



class Time
{
	friend class Date;
public:
	Time(int hour = 20, int mintue = 10, int second = 10)
		:_hour(hour)
		, _minute(mintue)
		, _second(second)
	{}
	void Print()
	{
		cout << _hour << "-" << _minute << "-" << _second << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year, int month, int day)//构造函数
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	void SetTime(int hour, int minute, int second)
	{
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}
	void Print()
	{
		_t.Print();
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};


void TestClass()
{
	Date d1(2020,10,6);
	Date d2(2020, 10, 1);
	d1.SetTime(21, 13, 5);
	d1.Print();
}


void Func()
{
	static int a = 10;
	a++;
	printf("%d\n", a);
}

int main()
{
	TestClass();
	return 0;
}