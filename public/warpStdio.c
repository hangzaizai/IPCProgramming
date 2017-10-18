//
//  warpStdio.c
//  mainPipe
//
//  Created by xtkj20170918 on 18/10/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#include "warpStdio.h"
#include "unixIPC.h"

char *Fgets(char *ptr,int n,FILE *stream)
{
    char *rptr;
    
    if ( ( rptr = fgets(ptr, n, stream))==NULL && ferror(stream) ) {
        err_sys("fgets error");
    }
    
    return (rptr);
}

FILE *Fopen(const char *pathname,const char *mode)
{
    FILE *fp;
    if ( (fp = fopen(pathname, mode)) ==NULL ) {
        err_sys("fopen error");
    }
    
    return (fp);
}
