#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void handle_sigterm(int sig) {
     printf("Child received SIGTERM. Exiting..\n");
     exit(0);
}
int main() {
    pid_t pid = fork();
    if (pid < 0) { perror("Fork faild"); return 1; }
    if (pid == 0) {
	signal(SIGTERM, handle_sigterm);
	printf("Child running (PID = %d), waiting for SIGTERM..\n", getpid());
	while(1) sleep(1);
    } else {
	printf("Parent PID: %d\n", getpid());
	sleep(3);
	printf("Parent sending SIGTERM to child PID %d\n", pid);
	kill(pid, SIGTERM);
	sleep(1);
	printf("Parent exiting\n");
    }
    return 0;
}
