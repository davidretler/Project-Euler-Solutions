/*
Problem 19
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.


How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <stdio.h>
#include "months.h"

void increment_day(void);


int main(void)
{
	#ifdef DEBUG
	printf("Day\tMonth\tYear\tDay of Week\tDay of Month\n");
	#endif
	
	int count = 0;
	while(year < 2001)
	{
		#ifdef DEBUG
		printf("%d\t%d\t%d\t%d\t\t%d\n", day, month, year, day_of_week, day_in_month);
		#endif
		
		if(day_in_month == 1 && day_of_week == Sunday && (year >= 1901 && year <= 2000))
		{
			count++;
		} 
		increment_day();
	}
	
	printf("%d days in the 20th century were Sundays on the first of the month.\n", count);
	


	return 0;
}






