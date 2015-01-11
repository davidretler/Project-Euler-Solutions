#include <stdbool.h>

typedef enum Month
{
	January = 1,
	February = 2,
	March = 3,
	April = 4,
	May = 5,
	June = 6,
	July = 7,
	August = 8,
	September = 9,
	October = 10,
	November = 11,
	December = 12

} Month;

typedef enum Day
{
	Sunday = 1,
	Monday = 2,
	Tuesday = 3,
	Wednesday = 4,
	Thursday = 5,
	Friday = 6,
	Saturday = 7
} Day;

//Initial date
static int day = 1;
static Month month = January;
static int year = 1900;
static Day day_of_week = Monday;
static int day_in_month = 1;

int days_in(Month month, int year);
bool is_leap_year(int year);
void increment_day(void);

//true if the year is a leap year
bool is_leap_year(int year)
{
	//if dividable by four and not century or if dividable by 400
	return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0) ? true : false;
}

//returns the number of days in a given month
int days_in(Month month, int year)
{
	if(month == September || month == April || month == June || month == November)
	{
		return 30;
	}
	else if(month != February)
	{
		return 31;
	}
	else if(month == February)
	{
		if(is_leap_year(year))
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
	else
	{
		return -1;
	}
}

//increments the current day by one
void increment_day(void)
{
	day++;
	day_in_month++;
	//if it's past the last day of the year
	if((day == 366 && !is_leap_year(year)) || day == 367)
	{
		//go to the next year
		day = 1;
		year++;
		month = January;
		day_in_month = 1;
	}
	//if we're past the last day of the month
	else if(day_in_month > days_in(month, year))
	{
		//it's safe to naively increment without checking because it can't be the last month
		//because the previous block would have run in that case
		month++;
		day_in_month = 1;
	}
	//if it's past Saturday
	if(day_of_week == 7)
	{
		//go back to Sunday
		day_of_week = 1;
	}
	else
	{
		//otherwise increment the day (could be done by modular arithmetic)
		day_of_week++;
	}
}