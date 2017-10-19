//
//  unixIPC.h
//  mainPipe
//
//  Created by xtkj20170918 on 17/10/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#ifndef unixIPC_h
#define unixIPC_h

#include "wrapUnix.h"
#include "errorCustom.h"
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "warpStdio.h"
#include <errno.h>




#define MAXLINE 1024

#ifdef __bsdi__
#define va_mode_t int
#else
#define va_mode_t mode_t
#endif

#endif /* unixIPC_h */
