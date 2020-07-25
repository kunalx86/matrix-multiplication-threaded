#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define ull long long 

ull sum = 0;

void* runner_sum(void* limit) {
	ull* limit_ptr = (ull*)limit;
	for (int i = 0; i < *limit_ptr; ++i) {
		sum += i;
	}
	return NULL;
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("Please enter limit\n");
		exit(-1);
	}
	ull limit = atoll(argv[1]);
	pthread_t tid;
	pthread_create(&tid, NULL, runner_sum, &limit);
	pthread_join(tid, NULL);
	// runner_sum(limit);
	printf("The sum is %lld\n", sum);
	return 0;
}

