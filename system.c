/*************************************************************************
	> File Name: system.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月02日 星期三 21时24分31秒
 ************************************************************************/

int _Execl(const char *,const char *,...);

int _Fork(void);

int _Wait(int *);

int system(const char *s){
    if(s){
        int pid = _Fork();
        if(pid < 0){
            return NULL;
        }else if(pid == 0){
            _Execl("/bin/sh","sh","-C",s,NULL);
            exit(EXIT_FAILURE);
        }else{
            while(_Wait(NULL) != pid);
            ;   
        }
    }
}
