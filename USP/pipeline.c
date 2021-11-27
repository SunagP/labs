// ALGORITHM:
// Step 1:call the fork function to create child process
// Step2 :close writing option
// Step 3:copy the old file descriptor
// Step 4:exec the command ls –l(long listing files)
// This process will be executed by child
// Step 5: else
// Close reading option
// Copy old file descriptor
// exec the command wc t count no of lines, words, characters
// step 6: both commands concurrently executed by pipe
// step 7:stop

include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <stdlib.h> 
#include <math.h>
int main()
 { 
int pfd[2],p;
 pipe(pfd); 
p=fork();
 if(p==0)
 { 
close(pfd[0]);
 close(1);
 dup(pfd[1]);
 execlp("ls","ls","-l",(char*)0);
 }
 else
 {
 close(pfd[1]); 
close(0); 
dup(pfd[0]);
 execlp("wc","wc",(char*)0);
 }
return 0;
 }

