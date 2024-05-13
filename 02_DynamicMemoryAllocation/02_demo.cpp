#include<iostream>
#include<malloc.h>	
using namespace std;

class demo
{
	int no1;
	int no2;
	public :
	demo()
	{
		cout<<"In default construtor"<<endl;
		no1 = 10;
		no2 = 30;
	}
	demo(int no1,int no2)
	{
		cout<<"In parameteris constructor"<<endl;
		this -> no1 = no1;
		this -> no2 = no2;
	}
	void display()
	{
		cout<<no1<<endl<<no2<<endl;
	}
	~demo()
	{
		cout<<"In default destructor"<<endl;
	}
};
int main(void)
{
	// call to default coustructor
	demo *p = new demo[3]{{},{100,200},{}};   
	if(p == NULL)
	{
		cout<<"Memory allocation failed";
	}

	(p + 0)-> display();
	(p + 1)-> display();
	(p + 2)-> display();

	delete []p;
	p = NULL;
	return 0;
}

