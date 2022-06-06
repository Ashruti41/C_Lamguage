#include "date.h"

Date dateUpdate( Date today)
{
	Date tomorrow;

	if(today.day!=numberOfDays(today))
		setDate(tomorrow, today.month, today.day+1,today.year);
	else if(today.month == dec)
		setDate(tomorrow,jan,1,today.year+1);
	else
		setDate(tomorrow,today.month+1,1,today.year);
	return tomorrow;
}
