/*************************************************************************
	> File Name: signall.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月19日 星期四 16时41分42秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>

typedef int sig_atomic_t ;
typedef void _sigfun(int);

_sigfun *_sigtable[_NSIG] = {0};

int (raise)(int sig){
    _sigfun *s;
    if(sig <= 0 || _NSIG <= sig)
        return (-1);
    if((s = _sigtable[sig]) != SIG_IGN && s != SIG_DFL)
    {
        _sigtable[sig] = SIG_DFL;
        (*s)(sig);
    }else if(s == SIG_DFL){
        char ac[10],*p;
        switch(sig){
            case SIGABRT:
                p = "abort";
                break;
            case SIGFPE:
                p = "arithmetic error";
                break;
            case SIGILL:
                p = "invaild executable code";
                break;
            case SIGSEGV:
                p = "termination request";
                break;
            default :
                *(p = &ac[(sizeof ac)-1]) = '\0';
            do{
                *--p = sig %10 + '0';

            }while((sig /= 10) != 0);
            fputs("signal #",stderr);
        }
        fputs(p,stderr);
        fputs("----terminating \n",stderr);
        exit(EXIT_FAILURE);
    }
    return 0;
}

_sigfun * (signal)(int sig,_sigfun *fun)
{
    _sigfun *s;
    if(sig <= 0 || _NSIG <= sig || fun == SIG_ERR)
        return (SIG_ERR);
    s = _sigtable[sig];
    _sigtable[sig] = fun;
    fun(sig);
    return (s);
}

void signalfun(int sig){
    printf("I get the signal and take it\n");
    return ;
}


int main(){
    signal(SIGINT,signalfun);
    kill(getpid(),SIGINT);

}
