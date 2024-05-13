// fkt ekch direct navani vaprycha asel tr

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
using one::no1;  // ha baher aala 

//int no1 = 50;     // tyamule he redeclaration zal 
int no2 = 60;

int main(void)
{
	cout<<"No1 is :\t"<<no1<<endl;  // one :: no1  10
	cout<<"No2 is :\t"<<no2<<endl;  // no2         60

	cout<<"No1 is :\t"<<no1<<endl;   // 10
	cout<<"No2 is :\t"<<two::no2<<endl;  // 20
	cout<<"No3 is :\t"<<one::no1<<endl;  // 30
	cout<<"No4 is :\t"<<two::no2<<endl;  // 40 

	return 0;
} 
