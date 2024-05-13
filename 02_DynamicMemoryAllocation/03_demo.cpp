#include<iostream>
#include<malloc.h>	
using namespace std;

class demo
{
	public :
	demo()
	{
		cout<<"Default constructor called"<<endl;
	}
	demo(int no1,int no2)
	{
		cout<<"parametries constructor called"<<endl;
	}
	~demo()
	{
		cout<<"Default destructor called"<<endl;
	}
};
int main(void)
{
	demo *ptr1,*ptr2,*ptr3,*ptr4,*ptr5;
	
	ptr1 = ptr2 = ptr3 = ptr4 = ptr5 = NULL;

	//No coustructor called
	cout<<"_________________________________________"<<endl;
	ptr1 = (demo *)malloc(sizeof(demo));

	// default constructor called
	cout<<"_________________________________________"<<endl;	
	ptr2 = new demo;
	
	// parametries constructor called
	cout<<"_________________________________________"<<endl;	
	ptr3 = new demo(10,20);

	//  3 times default constructor called
	cout<<"_________________________________________"<<endl;	
	ptr4 = new demo[3];
	
	// 1 default ,2nd parameteries & 3rd default
	cout<<"_________________________________________"<<endl;	
	ptr5 = new demo[3]{{} ,{100,300}};

	
	free(ptr1);
	
	cout<<"_________________________________________"<<endl;
	delete ptr2;

	cout<<"_________________________________________"<<endl;
	delete ptr3;

	cout<<"_________________________________________"<<endl;
	delete []ptr4;

	cout<<"_________________________________________"<<endl;
	delete []ptr5;

	return 0;
}
