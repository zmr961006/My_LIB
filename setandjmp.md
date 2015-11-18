##setjump && longjump

    
        这个两个函数就是用来执行函数间调转的。
举个例子

```
#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>
#include<string.h>

void fun1(void);
void fun2(void);

jmp_buf jmpbuffer;

int main(){
    int i = 0;
    int j = 0;
    i = setjmp(jmpbuffer);
    if(i == 0){
        printf("first run \n");
        fun1();
        fun2();
    }else{
        switch(i){
            case 1:
                printf("in fun1 \n");
                break;
            case 2:
                printf("in fun2 \n");
                break;
            default:
                printf("unknow error\n");
                break;
        }
                exit(0);
    }
    return 1;
}

void fun1(void){
    char *s = "hello";
    char *s1 = "Hello";
    if(strcmp(s,s1) != 0)
        longjmp(jmpbuffer,1);
}

void fun2(void){
    char *s = "world";
    if(strcmp(s,"wporld") == 0)
        longjmp(jmpbuffer,2);
}
```
运行结果是：
first run
in fun1

不出所料，很简单。
