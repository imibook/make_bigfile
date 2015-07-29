#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#define CAPCITY 1.5*1024*1024*1024
#define Location SEEK_CUR
int main(int argc,char *argv[])
{
int fd;
char msg[]="This is a 1.5G file";
fd=open("creat_big_file",O_CREAT|O_RDWR);
if(fd<0)
perror("lseek\n");

write(fd,msg,strlen(msg));
lseek(fd,CAPCITY,Location);
write(fd,msg,strlen(msg));
lseek(fd,0,SEEK_END);
if(close(handle)==0)
printf("close successfully\n");
return 0;
}
