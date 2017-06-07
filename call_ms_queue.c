

// 어플리케이션 함수 입니다.

#include<stdio.h>
#include<unistd.h>

int queue[100];

void main()
{
int i=0;
for(i=0;i<100;i++)
{
queue[i]=-9999;
}	



        syscall(326,3,queue);
	syscall(327,queue);
	syscall(326,4,queue);
	syscall(326,5,queue);
	syscall(326,6,queue);
	syscall(326,6,queue);
	syscall(327,queue);
        syscall(327,queue); 	
        syscall(327,queue); 

        //시스템 콜 호출~!!
	printf("exc sucess!!");
}
