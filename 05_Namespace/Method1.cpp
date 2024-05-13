#include<iostream>
//#include<stdlib>

using namespace std;

namespace one
{
	int no1 = 10;
	int no2 = 20;
}
namespace two
{
	int no1 = 30;
	int no2 = 40;
}	

int no1 = 50;
int no2 = 60;

int main(void)
{
	
	cout<<"No1 is :\t"<<no1<<endl;
	cout<<"No2 is :\t"<<no2<<endl;

	cout<<"No1 is :\t"<<one::no1<<endl;
	cout<<"No2 is :\t"<<two::no2<<endl;
	cout<<"No3 is :\t"<<one::no1<<endl;
	cout<<"No4 is :\t"<<two::no2<<endl;

	return 0;
} 
