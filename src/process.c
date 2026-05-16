#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    pid_t pid = fork();
    if (pid < 0) { perror("Fork faild"); return 1; }
    if (pid == 0) {
	printf("Child running (PID = %d)\n", getpid());
	sleep(2);
	printf("Child exiting\n");
    } else {
	printf("Parent running (PID = %d)\n", getpid());
	sleep(5);
	wait(NULL);
	printf("Parent cleaned zombie\n");
    }
    return 0;
}
