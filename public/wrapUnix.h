//
//  wrapUnix.h
//  mainPipe
//
//  Created by xtkj20170918 on 17/10/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#ifndef wrapUnix_h
#define wrapUnix_h

#include <stdio.h>
#include <sys/msg.h>

/****************FILES**************/
//关闭文件
void Close(int fd);
//打开文件
int Open(const char *pathname,int oflag,...);
//写入
void Write(int fd,void *ptr,size_t nbytes);
ssize_t Read(int fd,void *ptr,ssize_t nbytes);

/*******************Fork****************/
pid_t Wait(int *iptr);
pid_t Waitpid(pid_t pid,int *iptr,int options);
pid_t Fork(void);


void Pipe (int *fds);

/* system v msg queue */

/*创建一个消息队列*/

key_t Ftok(const char *pathname,int id);

int Msgget( key_t key,int flag );

/*消息队列的控制*/
void Msgctl(int id,int cmd,struct msqid_ds *buf);

void Msgsnd(int id,const void *ptr,size_t len,int flag);

#endif /* wrapUnix_h */

