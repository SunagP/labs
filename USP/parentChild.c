#include <stdio.h>
#include <stdlib.h>
int main(void)
{
int pid;
pid  = fork();
if(pid==0)printf("child");
else printf("parent");
return 0;

}

