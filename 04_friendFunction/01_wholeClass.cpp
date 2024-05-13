#include<iostream>
using namespace std;

class demo2;

class demo1
{
	int pri;

	public :
	int pub;

	protected :
	int pro;

	friend class demo2;

	public :
	void display()
	{
		cout<<pri<<endl;
		cout<<pro<<endl;
		cout<<pub<<endl;
	}	
};

class demo2
{
	public :
	void fun1()
	{
		demo1 obj1;
		obj1.pri = 10;
		obj1.pro = 20;
		obj1.pub = 30; 
		obj1.display();	
	}

	void fun2()
	{
		demo1 obj2;
		obj2.pri = 100;
		obj2.pro = 200;
		obj2.pub = 300; 
		obj2.display();	
	}
};

int main(void)
{
	demo2 obj3;

	obj3.fun1();

	obj3.fun2();
	return 0;

}	

