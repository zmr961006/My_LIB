/*************************************************************************
	> File Name: atexit.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月02日 星期三 19时00分49秒
 ************************************************************************/

extern void (*_Atfuns[])(void);
extern size_t _Atcount ;

int (atexit)(void (*func)(void))
{
    if(_Atcount == 0)
        return -1;
    _Atfuns[--_Atcount] = func;
    return 0;
}
