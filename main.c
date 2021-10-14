#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "shifter.h"
#include <errno.h>

int main(int argsc, char** argsv) {
  

	if (argsc<3||argsc>=4){
		printf("Incorrect number of args\n");
		exit(-1);
	}
	if (access("../File-reader-and-Case-shifter",W_OK)<0){
		printf("You do not have write permissions for this directory");
	}
	int inPtr = open(argsv[1], O_RDONLY);
	if (errno!=0){
		printf("oops, bad input. \n"); 
    exit(-1); 
	}

	int outPtr = open(argsv[2], O_CREAT|O_EXCL|O_APPEND|O_WRONLY, 0777);

	if (errno!=0)  {  
    printf("oops, file can't be already exists\n"); 
    exit(-1); 
  }
	

	char buf[65];
	buf[64] = '\0';
	int count = 1;
	int test = 0;
	
	while (count>0)
	{
	  count = read(inPtr,buf,64);
		buf[count]='\0';
		
		for (int i = 0; i<strlen(buf);i++){
			buf[i] = shifter(buf[i]);
			
		}

		test = write(outPtr, buf, strlen(buf));
		
	}
	
}