#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "epoll_server.h"

int main(int argc, const char* argv[])
{
    if(argc < 3)
    {
        printf("eg: ./a.out port path\n");
        exit(1);
    }

    // 端口 字符串转整数函数
    int port = atoi(argv[1]);
    // 修改进程的工作目录, 方便后续操作
    int ret = chdir(argv[2]);
	// 操作成功返回0，失败返回-1
    if(ret == -1)
    {
        perror("chdir error");
        exit(1);
    }
    
    // 启动epoll模型 
    epoll_run(port);

    return 0;
}
