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
    int length;
    char *filepath;
    key_t key;
    
    //获取当前程序路径
    length = sizeof(buffer);
    if ( getcwd(buffer, length) == NULL ) {
        err_sys("get cwd error");
    }
    
    printf("当前程序目录路径为:%s\n",buffer);
    filepath =  strcat(buffer, "/control");
    printf("当前文件路径为:%s\n",filepath);
    
    key = Ftok(filepath, 2048);
    
    msqid = Msgget(key,  IPC_R|IPC_W|IPC_M|IPC_CREAT);
    
    buf.mtype = 1;
    buf.mtext[0] = 1;
    
    Msgsnd(msqid, &buf, 1, 0);
    
    Msgctl(msqid, IPC_STAT, &info);
    printf("read-write %03o,cbytes = %lu,qnum=%lu,qbytes=%lu\n",info.msg_perm.mode & 777,(unsigned long)info.msg_cbytes,(unsigned long)info.msg_qnum,(unsigned long)info.msg_qbytes);
   
    system("ipcs -q");
    
    Msgctl(msqid, IPC_RMID, NULL);
    
    return 0;
}
