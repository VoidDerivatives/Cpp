#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>

void fun1(int);
void fun2(int);
void fun3(int);

jmp_buf env; // sagli kundali save karyna sathi variable banvla 
// jmp_buf datatype ahee user defined(struct cha use krun banvla ahee)					

int main(void)
{
	int ret;
	// sagli current situvation store karnya sathi setjmp la env pathvla
	ret = setjmp(env);  

	if(ret == 0)
	{
		printf("Calling fun1\n");
		printf("ret = %d\n",ret);
		fun1(20);
	}
	else
	{
		printf("Exception Found\n");
		printf("ret = %d\n",ret);
		exit(0);
	}
	
	printf("Exception Not Found\n");	

	return 0;
}
void fun1(int no)
{
	printf("In fun1\n");
	if(no == 10)
	{
	// longjmp madhe env ha reset zala aani to setjmp madhe uathla.
		longjmp(env,1);
	}
	fun2(no);	
}
void fun2(int no)
{
	printf("In fun2\n");
	if(no == 20)
		longjmp(env,2);

	fun2(no);
}
void fun3(int no)
{
	printf("In fun3\n");
	if(no == 30)	
		longjmp(env,3);

}
