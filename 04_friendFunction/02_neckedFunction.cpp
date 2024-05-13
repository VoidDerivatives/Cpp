#include<iostream>
using namespace std;

class demo
{
	int pri;

	friend void fun();

	public :
	int pub;

	protected :
	int pro;

	public :
	void display()
	{
		cout<<pri<<endl;
		cout<<pro<<endl;
		cout<<pub<<endl;
	}	
};

void fun()
{
	demo obj;
	obj.pri = 10;
	
	obj.pro = 20;

	obj.pub = 30;

	obj.display();
}

int main(void)
{
	cout<<"In main:"<<endl;

	cout<<"call fun:"<<endl;
	fun();
	
	

	return 0;
}
