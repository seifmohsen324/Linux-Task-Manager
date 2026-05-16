#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void handle_sigusr1(int sig) {
     printf("\n[Signal Handler ] Received SIGUSR1!\n");
     fflush(stdout);
}
int main() {
    signal(SIGUSR1, handle_sigusr1);
    printf("Process PID: %d\n", getpid());
    printf("Send SIGUSR1 using: Kill -USR1 %d\n", getpid());
    for (int i = 1; i <= 10; i++) {
	printf("Running... %d\n", i);
	sleep(1);
    }
    printf("Exiting signal\n");
    return 0;
}
