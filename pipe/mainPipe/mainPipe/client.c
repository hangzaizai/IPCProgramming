//
//  client.c
//  mainPipe
//
//  Created by xtkj20170918 on 18/10/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#include "client.h"
#include "unixIPC.h"

void client( int readfd,int writefd)
{
    size_t len;
    size_t n;
    char buff[MAXLINE];
    
    Fgets(buff, MAXLINE, stdin);
    len = strlen(buff);
    if ( buff[len-1] == '\n' ) {
        len--;
    }
    
    Write(writefd, buff, len);
    
    while ( (n = Read(readfd, buff, MAXLINE)) > 0 ) {
        Write(STDOUT_FILENO, buff, n);
    }
}
