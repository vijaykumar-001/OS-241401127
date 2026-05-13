#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    } 
    else if (pid == 0) {
        // Child process
        printf("Child process executing 'ls' command using execvp...\n");
        char *args[] = {"ls", "-F", NULL};
        execvp(args[0], args);
        
        // If execvp returns, it failed
        printf("Exec failed\n");
    } 
    else {
        // Parent process
        wait(NULL);
        printf("\nChild process completed. Parent exiting.\n");
    }

    return 0;
}
