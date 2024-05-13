#include<iostream>
#include<stdlib.h>
using namespace std;

void fun1(int);
void fun2(int);
void fun3(int);

int main(void)
{
	try
	{
		cout<<"Calling Fun1"<<endl;
		fun1(20);	
	}
	catch(int Exception)
	{
		cout<<"Exception Found"<<endl;
		exit(0);
	}
	return 0;
}

void fun1(int no)
{
	cout<<"In fun1"<<endl;
	if(no == 10)
	{
		throw no;
	}
	fun2(no);	
}
void fun2(int no)
{
	cout<<"In fun2"<<endl;
	if(no == 20)
		throw no;

	fun2(no);
}
void fun3(int no)
{
	cout<<"In fun3"<<endl;
	if(no == 30)	
		throw no;

}
