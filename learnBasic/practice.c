/*
 * days -> years, months, weeks, days converter
 * Assumptions:
 *  - 1 year = 365 days
 *  - 1 month = 30 days
 *  - 1 week = 7 days
 * The program reads a non-negative integer number of days from stdin
 * and prints the decomposition.
 */

#include <stdio.h>
#include <stdlib.h>

void convert_days(long long total_days,
				  long long *years,
				  long long *months,
				  long long *weeks,
				  long long *days)
{
	const long long DAYS_PER_YEAR = 365;
	const long long DAYS_PER_MONTH = 30;
	const long long DAYS_PER_WEEK = 7;

	*years = total_days / DAYS_PER_YEAR;
	total_days %= DAYS_PER_YEAR;

	*months = total_days / DAYS_PER_MONTH;
	total_days %= DAYS_PER_MONTH;

	*weeks = total_days / DAYS_PER_WEEK;
	*days = total_days % DAYS_PER_WEEK;
}

int main(void)
{
	long long total;
	printf("Enter number of days: ");
	if (scanf("%lld", &total) != 1) {
		fprintf(stderr, "Error: invalid input. Please enter an integer number of days.\n");
		return 1;
	}


	if (total < 0) {
		fprintf(stderr, "Error: please enter a non-negative number of days.\n");
		return 1;
	}

	long long years, months, weeks, days;
	convert_days(total, &years, &months, &weeks, &days);

	printf("%lld days = %lld year(s), %lld month(s), %lld week(s), %lld day(s)\n",
		   total, years, months, weeks, days);

	return 0;
}

