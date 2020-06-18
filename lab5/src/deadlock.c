#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


pthread_mutex_t mutx1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutx2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutx3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t msd = PTHREAD_MUTEX_INITIALIZER;
int first_num = 0;
int second_num = 0;
int third_num = 0;

void first_task(void* seed)
{
    int ssd = *(int *)seed;
    pthread_mutex_lock(&mutx1);
    while(true)
    {
    if (first_num <= 0)
    {
        pthread_mutex_lock(&mutx2);
        if(second_num != ssd)
        {
            if (second_num < 0) ssd = -1*second_num;
            else ssd = second_num;
        }
        else ssd*=10;
        pthread_mutex_unlock(&mutx2);
        if(ssd == 0) ssd+=10;
        first_num = rand()%ssd - 5;
    }
    else
    {
        printf("first_num = %d\n", first_num);
        break;
    }
    }
    pthread_mutex_unlock(&mutx1);
    
}

void second_task(void* seed)
{
    int ssd = *(int *)seed;
    pthread_mutex_lock(&mutx2);
    while(true)
    {
    if (second_num <= 0)
    {
        pthread_mutex_lock(&mutx3);
        if(third_num != ssd)
        {
            if (third_num < 0) ssd = -1*third_num;
            else ssd = third_num;
        }
        else ssd*= 10;
        pthread_mutex_unlock(&mutx3);
        if(ssd == 0) ssd+=10;
        second_num = rand()%ssd - 5;
    }
    else
    {
        printf("second_num = %d\n", second_num);
        break;
    }
    }
    pthread_mutex_unlock(&mutx2);
}

void third_task(void* seed)
{
    int ssd = *(int *)seed;
    pthread_mutex_lock(&mutx3);
    while(true)
    {
    if (third_num <= 0)
    {
        pthread_mutex_lock(&mutx1);
        if(first_num != ssd)
        {
            if (first_num < 0) ssd = -1*first_num;
            else ssd = first_num;
        }
        else ssd*= 10;
        pthread_mutex_unlock(&mutx1);
        if(ssd == 0) ssd+=10;
        third_num = rand()%ssd - 5;
    }
    else
    {
        printf("third_num = %d\n", third_num);
        break;
    }
    }
    pthread_mutex_unlock(&mutx3);
}

int main(int argc, char **argv)
{
    int seed = atoi(argv[1]);
    if (seed <= 0) {
    printf("seed is a positive number\n");
    return 1;
    }
    srand(seed);
    while(first_num == 0 || second_num == 0 || third_num == 0)
    {
        first_num = rand()%10 - 5;
        second_num = rand()%10 - 5;
        third_num = rand()%10 - 5;
    }

    pthread_t threads[3];
    if(pthread_create(&threads[0], NULL, (void*)first_task, (void*)&seed)!=0)
    {
        printf("thread creation error\n");
        return 1;
    }
    if(pthread_create(&threads[1], NULL, (void*)second_task, (void*)&seed) !=0)
    {
        printf("thread creation error\n");
        return 1;
    }
    if(pthread_create(&threads[2], NULL, (void*)third_task, (void*)&seed) !=0)
    {
        printf("thread creation error\n");
        return 1;
    }

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);
    printf("program finished successfully\n");


    return 0;
}