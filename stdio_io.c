/*************************************************************************
	> File Name: stdio_io.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月01日 星期二 20时56分50秒
 ************************************************************************/

static unsigned char ebuf[80];

static FILE sin = {
    _MOPENR ,0,NULL,NULL,
    &sin._Cbuf,&sin._Cbuf,NULL,&sin._Cbuf
};

static FILE sout = {
    _MOPENW,1,NULL,NULL,
    &sout._Cbuf,&sout._Cbuf,NULL,
    &sout._Cbuf
};

static FILE serr = {
    _MOPENW | _MNBF ,2 ,ebuf,ebuf + sizeof(ebuf),ebuf,
    ebuf,NULL,ebuf
};

FILE * _Files[FOPEN_MAX] = {&sin, &sout,&serr};

