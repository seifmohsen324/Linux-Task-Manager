#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* task(void* arg) {
     int id = *(int*)arg;
     for (int i = 0; i < 3; i++) {
	 printf("Thread %d time slice %d\n", id, i+1);
	 sleep(1);
     }
     return NULL;
}
int main() {
    pthread_t t1, t2;
    int a = 1, b = 2;

    pthread_create(&t1, NULL, task, &a);
    pthread_create(&t2, NULL, task, &b);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
