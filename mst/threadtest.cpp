
#include<iostream>
#include<unistd.h>
#include<pthread.h>

using namespace std;

pthread_mutex_t mtx;
pthread_cond_t _cond;

int g_Count = 0;

void* threadProc1(void *ptr){
	for (;;){
		pthread_mutex_lock(&mtx);
		std::cout << " thread1 proc" << endl;
		if(g_Count < 10){
			g_Count += 10;
			std::cout << " thread1 proc ADD" << endl;
		}
		pthread_mutex_unlock(&mtx);
		pthread_cond_signal(&_cond);
	}
}


void* threadProc2(void *ptr){
	for (;;){
		pthread_mutex_lock(&mtx);
		while(g_Count < 1)
			pthread_cond_wait(&_cond,&mtx);
		std::cout << " thread2 proc" << endl;
		g_Count--;
		pthread_mutex_unlock(&mtx);
	}
}

int main(int argc ,char* argv[]){
	pthread_mutex_init(&mtx,NULL);
	pthread_cond_init(&_cond,NULL);
	pthread_t id[2] = {0};
	int err1 = pthread_create(&id[0],NULL,threadProc1,NULL);
	int err2 = pthread_create(&id[1],NULL,threadProc2,NULL);
	if (err1 or err2){
		std::cout << "create thread error " << endl;
		return 1;
	}
	pthread_join(id[0],NULL);
	pthread_join(id[1],NULL);
	
	pthread_mutex_destroy(&mtx);
	pthread_cond_destroy(&_cond);
	return 0;
}



