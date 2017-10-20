//
//  main.c
//  client
//
//  Created by xtkj20170918 on 20/10/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#include <stdio.h>
#include "unixIPC.h"


int main(int argc, const char * argv[]) {
    
    int     readid,writeid;
    
    /* 创建两条队列，一个读队列，一个写队列 */
    readid = Msgget(MQ_KEY1, IPC_R|IPC_W|IPC_CREAT);
    writeid = Msgget(MQ_KEY2, IPC_R|IPC_W|IPC_CREAT);
    
    return 0;
}
