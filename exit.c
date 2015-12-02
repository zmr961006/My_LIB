/*************************************************************************
	> File Name: exit.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月02日 星期三 19时02分48秒
 ************************************************************************/

#define NATS   32

void (* _Atfuns[NATS])(void) = {0};
size_t _Atcount = {NATS};

void exit(int status){
    while(_Atcount < NATS)
        (*_Atfuns[_Atcount++])();
    {
        size_t i;
        for(i = 0;i < FOPEN_MAX ;++i)
            if(_Files[i])
                fclose(_Files[i]);
    }
    _Exit(status);
}

/*在源码中这个函数调用全部"at_exit" 与 "on_exit" 注册过的函数并且反向调用他们，并且会设置状态*/
