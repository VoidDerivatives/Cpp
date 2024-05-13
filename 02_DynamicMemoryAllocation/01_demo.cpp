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
		no1 = 10;
		no2 = 30;
	}
	demo(int no1,int no2)
	{
		this -> no1 = no1;
		this -> no2 = no2;
	}
	void display()
	{
		cout<<no1<<endl<<no2<<endl;
	}
};
int main(void)
{
	// call to default coustructor
	demo *p = new demo;   
	if(p == NULL)
	{
		cout<<"Memory allocation failed";
	}
	p -> display();        


	 // call to parameteries constructor
	demo *p1 = new demo(500,300);
	if(p1 == NULL)
	{
		cout<<"Memory allocation failed";
	}
	p1 -> display();

	
	// using malloc 
	// only used when its not depend on constructors 
	demo *p2 = (demo *)malloc(sizeof(demo));
	if(p2 == NULL)
	{
		cout<<"Memory allocation failed";
	}
	p2 -> display();
	
	delete p;
	delete p1;
	free(p2);
	p = p1 = p2 = NULL;	
	
	return 0;
}

