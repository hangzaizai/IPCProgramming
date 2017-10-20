//
//  wrapUnix.c
//  mainPipe
//
//  Created by xtkj20170918 on 17/10/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#include "wrapUnix.h"
#include "unixIPC.h"

void Close(int fd)
{
    if ( close(fd)==-1 ) {
        err_sys("close error");
    }
}

int Open(const char *pathname,int oflag,...)
{
    int      fd;
    va_list ap;
    mode_t mode;
    
    //只有O_CREAT有值时，open函数的 mode才有效
    if ( oflag & O_CREAT ) {
        va_start(ap,oflag);
        mode = va_arg(ap,va_mode_t);
        if ( (fd = open(pathname,oflag,mode) )==-1 ) {
            err_sys("open error for %s",pathname);
        }
        va_end(ap);
    }else{
        if ( ( fd = open(pathname,oflag) )== -1 ) {
            err_sys( "open error for %s",pathname );
        }
    }
    
    return  (fd);
}





void Write(int fd,void *ptr,size_t nbytes)
{
    if ( write(fd, ptr, nbytes) != nbytes ) {
        err_sys("write error");
    }
}

ssize_t Read(int fd,void *ptr,ssize_t nbytes)
{
    ssize_t     n;
    
    if ( (n = read(fd, ptr, nbytes)) ==-1 ) {
        err_sys("read error");
    }
    
    return (n);
}

pid_t Wait(int *iptr)
{
    pid_t pid;
    
    if ( (pid = wait(iptr) ) == -1 ) {
        err_sys("wait error");
    }
    
    return  (pid);
}

pid_t Waitpid(pid_t pid,int *iptr,int options)
{
    pid_t retpid;
    
    if ( (retpid = waitpid(pid, iptr, options))==-1 ) {
        err_sys("waitpid error");
    }
    
    return (retpid);
}

pid_t Fork(void)
{
    pid_t       pid;
    
    if ( (pid = fork()) == -1 ) {
        err_sys("fork error");
    }
    
    return (pid);
}

/************************************/
void Pipe (int *fds)
{
    if ( pipe(fds) < 0 ) {
        err_sys("pipe error");
    }
}

/* cmd option */
int Getopt(int argc,char *const *argv,const char *str)
{
    int     opt;
    
    //=='?'的逻辑表示最大输入的字符串个数
    if ( (opt = getopt(argc, argv, str)) == '?' ) {
        exit(1);
    }
    
    return (opt);
}

/*posix msg queue */
key_t Ftok(const char *pathname,int id)
{
    key_t       key;
    if ( (key = ftok(pathname, id)) == -1 ) {
        err_sys("ftok error");
    }
    
    return (key);
}

int Msgget( key_t key,int flag )
{
    int rc;
    
    if ( (rc = msgget(key, flag) ) == -1 ) {
        err_sys("msgget error");
    }
    
    return (rc);
}

void Msgctl(int id,int cmd,struct msqid_ds *buf)
{
    if ( msgctl(id, cmd, buf) == -1 ) {
        err_sys("msgctl error");
    }
}

void Msgsnd(int id,const void *ptr,size_t len,int flag)
{
    if ( msgsnd(id, ptr, len, flag) == -1 ) {
        err_sys("msgsnd error");
    }
}
