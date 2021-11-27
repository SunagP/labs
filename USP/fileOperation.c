#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
void getFileCreationTime(char *path) {
    struct stat attr;
    stat(path, &attr);
    printf("Last modified time: %s", ctime(&attr.st_mtime));
}
void printFileProperties(struct stat stats)
{
    printf("\nFile access: ");
    if (stats.st_mode & R_OK)
        printf("read ");
    if (stats.st_mode & W_OK)
        printf("write ");
    if (stats.st_mode & X_OK)
        printf("execute");
     printf("\n");
  }
int main(int argc, char *argv[]){
        const char *filename;
   	int st,i;  
  struct stat stats;
  if (stat(argv[1], &stats) == 0)
    {
        
	for (i = 1; i < argc; ++i) {
	
        filename = argv[i];
    	st = stat(filename,&stats);
    	if( S_ISREG(stats.st_mode) )
        	printf(" '%s' is regular file\n",filename);
    	else
        	printf(" '%s' is not a regular file\n",filename);
	printf("%s has %ld hard links\n", argv[i], stats.st_nlink);
	 printFileProperties(stats);
	 getFileCreationTime(argv[1]); 
	
     }
    }
    else
    {
        printf("Unable to get file properties.\n");
      //  printf("Please check whether '%s' file exists.\n", path);
    }
}

