#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//git实验副本
//
//看看改变了多少     　到这里说是改变了6个插入，我也不知道是啥
//
//how about now?

//线程运行函数

void* th_fn(void *arg)
{
	int distance = (int)arg;
	int i;
	for(i = 1; i <= distance; i++){
		printf("%lx run %d\n", pthread_self(), i);
		int time = (int) (drand48()*200000);
		usleep(time);
	}
	return (void*)0;
}




int main(void)
{
	int err;
	pthread_t rabbit, turtle;//定义线程标识符
	
	
	//建立rabbit线程
	if( (err = pthread_create(&rabbit, NULL, 
					th_fn, (void*)50)) != 0){
		perror("pthread_create error");
	}

	//建立turtle线程	
	if( (err = pthread_create(&turtle, NULL, 
					th_fn, (void*)50)) != 0){
		perror("pthread_create error");
	}
	
	//主控线程调用这个会阻塞，
	//直到rabbit和turtle线程结束才能运行	
	pthread_join(rabbit,NULL);
	pthread_join(rabbit,NULL);
	//	sleep(10);
	printf("control thread id : %lx \n", pthread_self());
	printf("finished!\n");

	return 0;
}
