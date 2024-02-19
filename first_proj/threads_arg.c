#include <stdio.h>
#include <pthread.h>

void *saySomething(void *input){
	printf("Hello %s\n", (char *)input);
	pthread_exit(NULL);
}

int main(){

	char name[50];
	printf("Enter something: \n");
	fgets(name, 50, stdin);
	pthread_t thread;
	pthread_create(&thread, NULL, saySomething, name);
	pthread_join(thread, NULL);
	return(0);
}
