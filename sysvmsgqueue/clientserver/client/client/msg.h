//
//  msg.h
//  client
//
//  Created by xtkj20170918 on 20/10/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#ifndef msg_h
#define msg_h

#include <stdio.h>

//消息数据部分的最大字节数
#define MAXMSGDATA 502
//消息的长度和类型的字节数
#define MSGHDRSIZE (sizeof(strcut custom_msg)-MAXMSGDATA)

//自定义消息结构
struct custom_msg
{
    long msg_len; //msg_data里面的字节数
    long msg_type; //必须大于1
    char msg_data[MAXMSGDATA];
};


ssize_t msg_send(int id,struct custom_msg *mptr);
void Msg_send(int id,struct custom_msg *mptr);


ssize_t msg_recv(int id,struct custom_msg *mptr);
ssize_t Msg_recv(int id,struct custom_msg *mptr);

#endif /* msg_h */
