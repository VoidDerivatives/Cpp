#include<iostream>
using namespace std;

class demo2
{
	public :
	void fun();
};
class demo1
{
	int pri;

	public :
	int pub;

	protected :
	int pro;

	friend void demo2 :: fun();

	public :
	void display()
	{
		cout<<pri<<endl;
		cout<<pro<<endl;
		cout<<pub<<endl;
	}	
};

void demo2 :: fun()
{
	demo1 obj1;
	obj1.pri = 10;
	obj1.pro = 20;
	obj1.pub = 30; 
	obj1.display();	
}
	

int main(void)
{
	demo2 obj2;

	obj2.fun();

	return 0;

}	

