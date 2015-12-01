/*************************************************************************
	> File Name: stdio.h
	> Author: 
	> Mail: 
	> Created Time: 2015年12月01日 星期二 19时57分46秒
 ************************************************************************/

#ifndef _STDIO_H
#define _STDIO_H




#define _NULL   (void *)0

#define _FNAMAX   64    

#define _FOPMAX   32

#define _TNAMAX   16

#define NULL   _NULL

#define _IOFBF   0

#define _IOLBF   1

#define _IONBF   2

#define BUFSIZE   512

#define EOF     -1

#define FILENAME_MAX    _FNAMAX

#define FOPEN_MAX      _FOPMAX

#define L_tmpnam       _TNAMAX

#define  TMP_MAX       32

#define  SEEK_SET     0

#define  SEEK_CUR     1

#define  SEEK_END     2

#define  stdin       _Files[0]

#define  stdout      _Files[1]

#define  stderr      _Files[2]

typedef _Sizet  size_t

typedef struct {
    unsigned long _off;
}fpos_t;

typedef struct {
    unsigned short _Mode;
    short _Handle;
    unsigned char *_Buf,*_Bend ,*_Next;
    unsigned char *_Rend, *_Rsave, *_Wend;
    unsigned char _Back[2],_Cbuf,_Nback;
    char * _Tmpnam;
}FILE;


void clearerr(FILE *);
int fclose(FILE *);
int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
int fgetc(FILE *);
int fgetpos(FILE *,fpos_t *);
char *fgets(char *,int ,FILE *);
FILE *fopen(const char *,const char *);
int fputc(int,FILE *);
int fputs(const char *,FILE *);
size_t fread(void *,size_t ,size_t ,FILE *);
FILE *freopen(const char *,const char *,FILE *);
int fscanf(FILE *, const char *,...);

int fseek(FILE *,long ,int);
int fsetpos(FILE *,const fpos_t *);
long ftell(FILE *);
size_t fwrite(const void *,size_t ,size_t,FILE *);
int getc(FILE *);
int getchar(void);
char *gets(char *);
void perror(const char *);

int printf(const char *,...);
int putc(int ,FILE *);
int putchar(int);
int puts(const char *);
int remove(const char *);
int rename(const char *,const char *);
void rewind(FILE *);

int scanf(const char *,...);
void setbuf(FILE *,char *);
int setvbuf(FILE *,char *,int ,size_t);
int sprintf(char *,const char *,...);
int sscanf(const char *,const char *,...);
FILE *tmpfile(void);
char *tmpnam(char *);
int ungetc(int ,FILE *);
int vfprintf(FILE *,const char *,char *);
int vprintf(const char *,char *);
int vsprintf(char *,const char *,char *);
long _Fgpos(FILE * ,fpos_t *);
int _Fspos(FILE *,const fpos_t *,long ,int);
FILE * _Files[FOPEN_MAX];

#define fgetpos(str,ptr)  (int)_Fgpos(str,ptr)
#define fseek(str,off,way)  _Fspos(str,_NULL,off,way)
#define fsetpos(str,ptr)    _Fspos(str,ptr,0L,0)
#define ftell(str)  _Fgpos(str,_NULL)
#define getc(str)  ((str)->_Next < (str)->_Rend    \
                    ? *(str)->_Next++:(getc)(str))

#define getchar()  (_Files[0]->_Next < _Files[0]->_Rend \
                    ? *_Files[0]->_Next++ : (getc)(str))

#define putc(c,str) ((str)->_Next < (str)->_Wend \
                    ?(*(str)->_Next++ = c) : (putc)(c,str))

#define putchar(c)  (_Files[1]->_Next < _Files[1]->_Wend \
                    ? (*_Files[1]->_Next++ = c):(putchar)(c))












#endif
