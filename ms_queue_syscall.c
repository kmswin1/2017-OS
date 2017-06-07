//system call 을 위한 queue를 구현해놓은 함수입니다.
#include<linux/kernel.h>

int i;
int m;  /* for 문시 사용할 변수 선언 입니다. */
int n;
int o;
int j;

asmlinkage void sys_ms_enqueue(int n, int* queue)
{
	for (i = 0; i<100; i++) {
		if(queue[i]==n){
			printk("error!\n");
			break;
		}
	//중복된 값을 큐에 넣을수 없는 조건문입니다.
		if (queue[i] ==-9999) {
			queue[i] = n;
			break;
		}
	//NULL 의 개념으로 queue에 모두 초기화된 -9999 값이면 그 자리에
	//인자를 삽입해줍니다.
	}
	printk("queue : ");
	for (m = 0; m < 100; m++) {
		if (queue[m] != -9999)
			printk("%d ", queue[m]);
	}
	//for 문을 통한 큐의 저장값만 출력해주는 반복문입니다.
	printk("\n");
}

asmlinkage void sys_ms_dequeue(int *queue)
{
	int k = 0;
	//deque 값 출력을 위한 변수 선언입니다.
	for (n = 0; n<100; n++) {
		if (queue[n] !=-9999) //만약 큐에 저장된 값이 있으면 
		{
			for (j = n; j < 99; j++) {
				k = queue[j]; // 그 값을 k 에 저장하고
				queue[j] = queue[j + 1];
			}
			// deque 를 위한 값을 빼고 모두 인덱스를 한칸씩 당겨줍니다.
		}
		else
			printk("error!\n");
		// 만약 인자값이 없으면 에러를 뜨게 해놨습니다.
		break;
	}
	printk("queue : ");
	for (o = 0; o < 100; o++) {
		if (queue[o] != -9999)
			printk("%d ", queue[o]);
	}
	//남아있는 큐를 출력해주는 반복문입니다.
	printk("\n");
}