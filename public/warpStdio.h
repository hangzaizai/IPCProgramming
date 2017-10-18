//
//  warpStdio.h
//  mainPipe
//
//  Created by xtkj20170918 on 18/10/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#ifndef warpStdio_h
#define warpStdio_h

#include <stdio.h>

FILE *Fopen(const char *pathname,const char *mode);

char *Fgets(char *ptr,int n,FILE *stream);

#endif /* warpStdio_h */
