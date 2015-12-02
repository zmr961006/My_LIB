/*************************************************************************
	> File Name: rand.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月02日 星期三 18时54分11秒
 ************************************************************************/

unsigned long _Randseed = 1;

int rand(void){
    _Randseed = _Randseed * 1103515245 + 12345;
    return ((unsigned int )(_Randseed >> 16) & RAND_MAX);
}

void srand(unsigned int seed){
    _Randseed = seed;
}

