//
//  main.c
//  mainPipe
//
//  Created by xtkj20170918 on 17/10/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#include <stdio.h>
#include "unixIPC.h"
#include "server.h"
#include "client.h"

int main(int argc, const char * argv[]) {
    
    int         pipe1[2],pipe2[2];
    pid_t       childpid;
    
    Pipe(pipe1);
    Pipe(pipe2);
    
    if ( (childpid = Fork())==0 ) {
        
        Close(pipe1[1]);
        Close(pipe2[0]);
        
        server(pipe1[0], pipe2[1]);
        exit(0);
    }
    
    Close(pipe1[0]);
    Close(pipe2[1]);
    
    client(pipe2[0], pipe1[1]);
    
    Waitpid(childpid, NULL, 0);
    exit(0);
    return 0;
}
