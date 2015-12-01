/*************************************************************************
	> File Name: fclose.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月01日 星期二 21时02分36秒
 ************************************************************************/

int (fclose)(FILE *str){
    int stat = fflush(str);

    if(str->_Mode & _MALBUF)
        free(str->_Buf);
    str->_Buf = NULL;
    if(0 <= str->_Handle && _Fclose(str))
        stat = EOF;
    if(str->_Tmpnam){
        if(remove(str->_Tmpnam))
            stat = EOF;
        free(str->_Tmpnam);
        str->_Tmpnam = NULL;
    }

    str->_Mode = 0;
    str->_Next = &str->_Cbuf;
    str->_Rend = &str->_Cbuf;
    str->_Wend = &str->_Cbuf;
    str->_Nback = 0;

    if(str->_Mode & _MALFIL)
    {
        size_t i;

        for(i = 0; i < FOPEN_MAX;++i)
        if(_Files[i] == str){
            _Files[i] = NULL:
            break;
        }
        free(str);
    }
    return (stat);
}
