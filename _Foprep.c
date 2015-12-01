/*************************************************************************
	> File Name: _Foprep.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月01日 星期二 21时10分44秒
 ************************************************************************/

FILE * _Foprep(const char *name,const char * mods,FILE *str){
    str->_Handle = 1;
    str->_Tmpnam = NULL;
    str->_Buf = NULL;
    str->_Next = &str->_Cbuf;
    str->_Rend = &str->_Cbuf;
    str->_Wend = &str->_Cbuf;
    str->_Nback = 0;
    str->_Mode = (str->_Mode & _MALFIL) |
                (*mods == 'r' ? _MOPENR
                 :  *mods == 'w' ? _MCREAT|_MOPENW|_MTRUNC
                 :  *mods == 'a' ? _MCREAT|_MOPENW|_MOPENA
                 : 0);
    if((str->_Mode & (_MOPENR | _MOPENW)) == 0)
    {
        fclose(str);
        return (NULL);
    }

    while(*++mods == 'b' || *mods == '+')
        if(*mods == 'b')
            if(str->_Mode & _MBIN)
                break;
            else
                str->_Mode |= _MBIN;
         else
            if((str->_Mode & (_MOPENR | _MOPENW)) == (_MOPENR | _MOPENW))
                break;
            else
                str->_Mode |= _MOPENR | _MOPENW;
        str->_Handle = _Fopen(name,str->_Mode,mods);
    if(str->_Handle < 0){
        fclose(str);
        return NULL;
    }
    return str;

}