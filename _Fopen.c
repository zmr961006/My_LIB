/*************************************************************************
	> File Name: _Fopen.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月01日 星期二 21时43分55秒
 ************************************************************************/

int _Open(const char *,int ,int);

int _Fopen(const char *path,unsigned int smod,const char *mods){
    
    unsigned int acc;
    acc = (smode & (_MOPENR | _MOPENW)) == (_MOPENR | _MOPENW) ? 2: smode &
           _MOPENW ? 1: 0;
    if(smode & _MOPENA)
        acc |= 010;
    if(smode & _MTRUNC)
        acc |= 02000;
    if(smode & _MCREAT)
        acc |= 01000;
    return (_Open(path,acc,0666));
}

