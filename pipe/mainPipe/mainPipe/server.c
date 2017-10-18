//
//  server.c
//  mainPipe
//
//  Created by xtkj20170918 on 18/10/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#include "server.h"
#include "unixIPC.h"

void server(int readfd,int writefd)
{
    int         fd;
    ssize_t     n;
    char        buff[MAXLINE+1];
    
    if ( (n=Read(readfd, buff, MAXLINE)) ==0 ) {
        err_quit("end-of-file while reading pathname");
    }
    
    buff[n] = '\n';
    
    if ( (fd = open(buff, O_RDONLY)) < 0 ) {
        snprintf(buff+n, sizeof(buff)-n, "can,t open %s\n",strerror(errno));
    }else{
        while ( (n = Read(fd, buff, MAXLINE)) > 0  ) {
            Write(writefd, buff, n);
        }
        Close(fd);
    }
}
