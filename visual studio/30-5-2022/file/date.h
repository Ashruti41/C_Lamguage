#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
//header file for working with dates
#include<stdbool.h>

//enumerated types

enum kmonth{jan=1,feb,march,april,may,june,july,august,sep,oct,nov,dec};

enum kday{sun,mon,tue,wed,thu,fri,sat};

struct date{
	enum kmonth month;
	enum kday day;
	int year;
};

typedef struct date date;

//function that worj with dates
date dateupdate(date today);
int numberofdays(date d);
bool isleapyear(date d);

//macro to set a date in a structure
#define setdate(s,mm,dd,yy) s=(date) {mm,dd,yy}

//External variable reference
extern Date todaysDate;
