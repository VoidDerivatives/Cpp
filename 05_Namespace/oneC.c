#include<stdio.h>

void fun1();
extern int no1 = 20;

int main(void)
{

	printf("Enter the number:\t");
	scanf("%d",&no1);

	printf("In main :\t\n");

	printf("No1 is :\t%d\n",no1);
	fun1();

	return 0;
}
