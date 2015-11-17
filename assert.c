/*************************************************************************
	> File Name: assert.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月17日 星期二 17时25分56秒
 ************************************************************************/



#ifdef NODEBUG
    #define assert(test)    ((void)-1)
#else
    void _Assert(char *);
    #define _STR(x) _VAL(x)
    #define _VAL(x) #x
    #define assert(test)  ((test) ? (void) 0 :_Assert(__FILE__ ":" __STR(__LINE__)" "#test))
#endif

void _Assert(char *msg){
    fputs(mesg,stderr);
    fputs("--assertion failed\n",stderr);
    abort();
}


