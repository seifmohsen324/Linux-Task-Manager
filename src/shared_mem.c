#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    int shmid;
    int *shared_value;

   shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
   if (shmid < 0) {
	perror("shmget failed");
	return 1;
   }

   shared_value = (int *)shmat(shmid, NULL, 0);
   if (shared_value == (void *) -1) {
	perror("shmat failed");
	return 1;
   }

   *shared_value = 10;
   printf("parent: Wrote %d to shared memory\n", *shared_value);

   pid_t pid = fork();

   if (pid == 0) {
	printf("Child: read %d from shared memory\n", *shared_value);
	*shared_value += 5;
	printf("Child: updated value to %d\n", *shared_value);
	shmdt(shared_value);
	exit(0);
   } else {
	sleep(2);
	printf("Parent: after child update, value = %d\n", *shared_value);
	shmdt(shared_value);
	shmctl(shmid, IPC_RMID, NULL);
   }
   return 0;
}
