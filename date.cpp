#include <string>

#include "date.h"
using namespace std;

Date::Date()	{
	year = 0;
	month = 0;
	day = 0;
}

Date::Date(int y, int m, int d)	{
	year = y;
	month = m;
	day = d;
}

// setters
void Date::set_year(int y)	{
	year = y;
}

void Date::set_month(int m)	{
	month = m;
}

void Date::set_day(int d)	{
	day = d;
}

// getters
int Date::get_year()	{
	return year;
}

int Date::get_month()	{
	return month;
}

int Date::get_day()	{
	return day;
}

// return date information formated similar to the example 
// provided in the supplementary material file in the format
// 
string Date::date_string()	{
	string completeDate;

	completeDate = to_string(month) + '/' + to_string(day) + '/' + to_string(year);
	return completeDate;
}

