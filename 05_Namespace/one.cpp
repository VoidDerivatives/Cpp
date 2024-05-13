#include<iostream>
using std :: cout;
using std :: cin;
using std :: endl;

void fun1();
namespace one
{
	int no1;
	int no2;
}

namespace one 
{
	int no5;
	int no6;
}

int main(void)
{

	cout<<"Enter the number1:\t"<<endl;
	cin>>one::no1;

	cout<<"Enter the number2:\t"<<endl;
	cin>>one::no2;

	cout<<"In main :\t"<<endl;

	cout<<"No1 is :\t"<<one::no1<<endl;
	cout<<"No2 is :\t"<<one::no2<<endl;

	cout<<"No5 is :\t"<<one::no5<<endl;
	cout<<"No6 is :\t"<<one::no6<<endl;
	fun1();

	return 0;
}
