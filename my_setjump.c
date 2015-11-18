/*************************************************************************
	> File Name: my_setjump.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月18日 星期三 19时12分32秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>


#define  _JBFP    1
#define  _JBMOV   60
#define  _JBOFF   4
#define  _NSETJMP 17

typedef int jmp_buff[_NSETJMP];


static int getfp(void){
        int arg;
    return (int)(&arg + _JBFP);
}

int setjmp(jmp_buff env){
    

    env[1] = getfp();

    return 0;
}

static void setfp(int fp){
    int arg;
    (&arg)[_JBFP] = fp;
}

static int dojmp(jmp_buff env)
{

    setfp(env[1]);
    return (env[0]);
}

void longjmp(jmp_buff env,int val)
{
    
    env[0] = val?val:1;
    dojmp(env);
}

static char *stackptr(void){
    char ch;
    return (&ch);
}

jmp_buff env;
int main(){
    char *sp = stackptr();
    if(sp == stackptr()){
        printf("stack is ok\n");
    }else{
        printf("the statk is change\n");
    }
    setjmp(env);
    int i = 0;
    if(i == 0){
        printf("i will jump!!\n");
        longjmp(env,1);
    }else{
        printf("scuess\n");
    }

    
}
