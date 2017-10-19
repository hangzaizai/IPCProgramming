//
//  main.c
//  control
//
//  Created by xtkj20170918 on 19/10/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#include <stdio.h>
#include "unixIPC.h"
#include <sys/msgbuf.h>

int main(int argc, const char * argv[]) {
    
    int                 msqid;
    struct msqid_ds     info;
    struct mymsg       buf;
    char buffer[1024];
    
    //获取当前程序路径
    if ( getcwd(buffer, sizeof(buffer))==NULL ) {
        err_sys("get cwd error");
    }
    
    printf("");
    
    
    msqid = Msgget(IPC_PRIVATE,  IPC_R|IPC_W|IPC_M|IPC_CREAT);
    
    buf.mtype = 1;
    buf.mtext[0] = 1;
    
    Msgsnd(msqid, &buf, 1, 0);
    
    Msgctl(msqid, IPC_SET, &info);
    printf("read-write %03o,cbytes = %lu,qnum=%lu,qbytes=%lu\n",info.msg_perm.mode & 777,(unsigned long)info.msg_cbytes,(unsigned long)info.msg_qnum,(unsigned long)info.msg_qbytes);
   
    system("ipcs -q");
    
    Msgctl(msqid, IPC_RMID, NULL);
    
    return 0;
}
