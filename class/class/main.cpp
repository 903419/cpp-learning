#include <iostream>
#include <cassert>
#pragma warning(disable:4996)
using namespace std;

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

int main()
{
	TestClass();
	return 0;
}