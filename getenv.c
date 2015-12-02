/*************************************************************************
	> File Name: getenv.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月02日 星期三 21时20分22秒
 ************************************************************************/

char * getenv(const char *name ){
    const char *s;
    size_t n = strlen(name);
    for(s = _Envp;*a; s += strlen(s) + 1)
    {
        if(!strncmp(s,name,n) && s[n] == '=')
            return ((char *)s[n + 1]);
    }
    return (NULL);

}
