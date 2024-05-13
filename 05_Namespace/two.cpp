#include<iostream>
using std :: cout;
using std :: endl;

namespace one
{
	int no3;
	int no4;
}

void fun1()
{

	cout<<"In fun1 :"<<endl;
//	cout<<"No1 is : \t"<<no1<<endl;

	cout<<"No3 is :\t"<<one::no3<<endl;
	cout<<"No4 is :\t"<<one::no4<<endl;
	
}
