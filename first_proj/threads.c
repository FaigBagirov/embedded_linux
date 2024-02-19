#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *customThreadFunction(){
for(int i = 0; i < 15; i++){
	printf("I'm a custom thread function created by Faig\n");
	sleep(1);
	}
}

int main(){
pthread_t thread;

int status;
status = pthread_create(&thread,NULL, customThreadFunction, NULL);
if (!status){
	printf("Custom thread created successfully.\n");
}
else{
	printf("Unable to create the custom thread.\n");
return 0;
}

for (int i = 0; i<15; i++){
	printf("I'm the process thread created by compiler by default.\n");
        sleep(1);
}








return 0;
}
