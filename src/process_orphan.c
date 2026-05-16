#include <stdio.h>
#include <unistd.h>
int main() {
    pid_t pid = fork();
    if (pid < 0) { perror("Fork faild"); return 1; }
    if (pid == 0) {
	sleep(3);
	printf("Child is now orphan (PID = %d, parent PID = %d)\n", getpid(), getppid());
    } else {
	printf("Parent exiting immediately (PID = %d)\n", getpid());
    }
    return 0;
}
