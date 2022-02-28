#include<cstdio>
#include<cstring>
#include<algorithm>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
int main(){
    char read_file_path[1010];
    char write_file_path[1010];
    printf(" please input read file name: ");
    scanf("%s",read_file_path);

    int read_file_fd, write_file_fd = -1;
    read_file_fd = open(read_file_path, O_RDONLY);
    if(read_file_fd == -1){
        printf("open read file: %s failed. \n",read_file_path);
        return 0;
    }else{
        printf("open read file: %s success. \n",read_file_path);
    }

    printf("please input write file name: ");
    scanf("%s", write_file_path);

    write_file_fd = creat(write_file_path, 0777);
    if(write_file_fd == -1){
        printf("open write file : %s failed.\n",write_file_path);
        return 0;
    }else{
        printf("open write file: %s success.\n",write_file_path);
    }

    char buf[20];
    size_t nbytes;
    ssize_t bytes_read, bytes_write;
    nbytes = sizeof(buf);
    bytes_read = nbytes;
    while(bytes_read ==  nbytes){
        bytes_read = read(read_file_fd, buf, nbytes);
        printf("read  %ld bytes data   %s  bytes_read  %ld \n",nbytes, buf, bytes_read);
        bytes_write = write(write_file_fd, buf, bytes_read);
        printf("write  %ld bytes data  %s  bytes_write  %ld \n",bytes_read, buf, bytes_write);
    }
    if (close(read_file_fd) == -1){
        printf("close read file :%s  failed. \n", read_file_path);
    }else{
        printf("close read file:%s  success.\n", read_file_path);
    }

  if (close(write_file_fd) == -1){
        printf("close write file :%s  failed. \n", read_file_path);
    }else{
        printf("close write file:%s  success.\n", read_file_path);
    }

}