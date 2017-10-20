//
//  msg.c
//  client
//
//  Created by xtkj20170918 on 20/10/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#include "msg.h"
#include "unixIPC.h"

ssize_t msg_send(int id,struct custom_msg *mptr)
{
    return (msgsnd(id, &(mptr->msg_type),mptr->msg_len ,0 ));
}

void Msg_send(int id,struct custom_msg *mptr)
{
    ssize_t n;
    if ( ( n = msg_send(id, mptr)) == -1 ) {
        err_sys("mesg_send error");
    }
}

ssize_t msg_recv(int id,struct custom_msg *mptr)
{
    ssize_t n;
    
    n = msgrcv(id, &(mptr->msg_type), MAXMSGDATA, mptr->msg_type, 0);
    
    mptr->msg_len = n;
    
    return  (n);
}

ssize_t Msg_recv(int id,struct custom_msg *mptr)
{
    ssize_t n;
    if ( (n = msg_recv(id, mptr) ) == -1 ) {
        err_sys("msg_recv error");
    }
    
    return (n);
}
