/*************************************************************************
	> File Name: div.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月02日 星期三 18时48分05秒
 ************************************************************************/

#include "stdlib.h"

div_t div(int number, int denom){
    div_t val;
    val.quot = number / denom;
    val.rem  = number - denom * val.quot;
    if(val.quot < 0 && 0 < val.rem){
        val.quot += 1;
        val.rem -= denom;
    }

    return (val);
}



