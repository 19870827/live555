#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
 FILE *fp1,*fp2;
int fd=-1;
 int i;
	int len;
    char buffer[1024];
	int write_already=0;
	printf("%s %d\n",__FUNCTION__,__LINE__);
 if((fd=open("1.264",O_WRONLY|O_NONBLOCK))<=0)
 {
  exit(0);
 }
	printf("%s %d\n",__FUNCTION__,__LINE__);
 if((fp2=fopen("test.264","r"))==NULL)
 {
  exit(0);
 }


    while(1)
     {
		printf("%s %d\n",__FUNCTION__,__LINE__);
		len=fread(buffer,1,sizeof(buffer),fp2);
		printf("read len=%d\n",len);

		if(len>0){
			do{
				write_already=0;
				printf("%s %d\n",__FUNCTION__,__LINE__);
				write_already+=write(fd,buffer,len-write_already);
			    printf("write len=%d\n",write_already);
			}while(write_already<len);
				printf("%s %d\n",__FUNCTION__,__LINE__);
			}else{
				printf("%s %d\n",__FUNCTION__,__LINE__);
				break;
			}
			printf("%s %d\n",__FUNCTION__,__LINE__);
     }
	printf("%s %d\n",__FUNCTION__,__LINE__);
 //fclose(fp1);
    fclose(fp2);
}
