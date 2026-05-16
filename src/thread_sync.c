#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

pthread_mutex_t lock;
sem_t sem;
int shared_counter = 0;
void* worker(void* arg) {
    sem_wait(&sem);
    pthread_mutex_lock(&lock);

    shared_counter++;
    printf("Worker thread updated counter to %d\n", shared_counter);
    pthread_mutex_unlock(&lock);
    sem_post(&sem);
    return NULL;
}
int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);
    sem_init(&sem, 0, 1);
    pthread_create(&t1, NULL, worker, NULL);
    pthread_create(&t2, NULL, worker, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Final counter value: %d\n", shared_counter);
    pthread_mutex_destroy(&lock);
    sem_destroy(&sem);
    return 0;
}
