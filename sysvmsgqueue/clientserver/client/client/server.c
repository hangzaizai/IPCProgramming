//
//  server.c
//  client
//
//  Created by xtkj20170918 on 20/10/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#include "server.h"
#include "msg.h"
#include "unixIPC.h"

void server(int readfd,int writefd)
{
    FILE    *fp;
    ssize_t n;
    struct custom_msg msg;
    
    msg.msg_type = 1;
    if ( (n = Msg_recv(readfd, &msg)) == 0 ) {
        err_quit("pathname missing");
    }
    msg.msg_data[n] = '\0';
    
    if ( (fp = fopen(<#const char *restrict __filename#>, <#const char *restrict __mode#>)) ) {
        <#statements#>
    }
    
}
