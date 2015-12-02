/*************************************************************************
	> File Name: ldiv.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月02日 星期三 18时51分32秒
 ************************************************************************/


ldiv_t (ldiv)(long number,long denom){
    ldiv_t val;
    val.quot = number / denom;
    val.rem = number - denom * val.quot;

    if(val.quot < 0 && 0 < val.rem){
        val.quot += 1;
        val.rem  -= denom;

    }
    
    return (val);
}


