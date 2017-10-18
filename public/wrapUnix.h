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

//关闭文件
void Close(int fd);

//打开文件
int Open(const char *pathname,int oflag,...);

//写入
void Write(int fd,void *ptr,size_t nbytes);

pid_t Waitpid(pid_t pid,int *iptr,int options);

pid_t Wait(int *iptr);

ssize_t Read(int fd,void *ptr,ssize_t nbytes);

#endif /* wrapUnix_h */

