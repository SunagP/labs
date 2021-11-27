#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char *argv[])
 {
   int f1, f2;
   char buff[50];
   long int n;

 
    f1 = open(argv[1], O_RDONLY);
    f2=open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0700);

 while((n=read(f1, buff, 50))>0)

     if(write(f2, buff, n)!=n)
        {
           perror("problem in writing");
           exit(3);
        }


       close(f2);
       exit(0);
 }

