/*************************************************************************
	> File Name: fopen.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月01日 星期二 20时44分35秒
 ************************************************************************/

#include "stdio.h"

FILE *(fopen)(const char *name,const char *mods)
{
    FILE *str;          //首先FILE 指针
    size_t i;

    for(i = 0; i < FOPEN_MAX;++i){    //查找还有没有可以打开的文件数目
        if(_Files[i] == NULL){
            str = malloc(sizeof(FILE));
            if(str == NULL)
                return NULL;
            _Files[i] = str;
            str->_Mode = _MALFIL;
            break;
        }else if(_Files[i]->_Mode == 0){
            str = _Files[i];
            break;
        }
        if(FOPEN_MAX <= i)
            return NULL;
        return (_Foprep(name,mods,str));

    }
}

