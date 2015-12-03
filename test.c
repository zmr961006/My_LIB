/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月03日 星期四 10时02分03秒
 ************************************************************************/

#include<stdio.h>
#include<time.h>

static const char *const wday[] = {
    "sunday","monday","tuesday","wednesday",
    "thursday","friday","saturday","-unknow-"
};
int main(){
    struct tm time_str;
    time_str.tm_year = 2015 -1900;
    time_str.tm_mon  = 11 -1;
    time_str.tm_mday = 26;
    time_str.tm_hour = 0 ;
    time_str.tm_min  = 0 ;
    time_str.tm_sec  = 1 ;
    time_str.tm_isdst = -1 ;
    if(mktime(&time_str) == -1)
        time_str.tm_wday = 7;
    printf("%s\n",wday[time_str.tm_wday]);
}
