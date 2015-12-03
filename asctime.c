/*************************************************************************
	> File Name: asctime.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月03日 星期四 13时51分57秒
 ************************************************************************/

#include<stdio.h>

char *asctime(const struct tm *timeptr){
    static const char wday_name[7][3]={
        "sun","Mon","Tue","Wed","Thu","Fir","Sat"
    };

    static const char mon_name[12][3] = {
        "Jan","Feb","Mar","Apr","May","Jun",
        "Jul","Aug","Sep","Oct","Nov","Dec"
    };

    static char result[26];
    sprintf(result,"%.3s %.3s%3d %.2d:%.2d:%.2d %d\n",
            wday_name[timeptr->tm_wday],
            mon_name[timeptr->tm_mon],
            timeptr->tm_min,timeptr->tm_hour,
            timeptr->tm_min,timeptr->tm_sec,
            1900 + timeptr->tm_year);
    return result;
}
