#include<iostream>
using namespace std;
class base
{
	public:
	int no1;
	int no2;
	
	base()
	{
		no1 = no2 = 30;
	}
	void fun1()
	{
		cout<<"In base fun1"<<endl;
	}
	void fun2()
	{
		cout<<"In base fun2"<<endl;
	}
};

class derived : public base
{
	public:
	int no3;
	int no4;

	void fun3()
	{
		cout<<"In derived1 fun3"<<endl;
	}
	void fun4()
	{
		cout<<"In derived1 fun4"<<endl;
	}
};
void fun(base bobj)
{
	cout<<bobj.no1<<endl;
	cout<<bobj.no2<<endl;
	
	bobj.fun1();
	bobj.fun2();	
}
int main(void)
{
	derived dobj;
	
	//dobj.no1 = dobj.no2 = 10;
	dobj.no3 = dobj.no4 = 20;

	fun(dobj);

	return 0;
}

	

