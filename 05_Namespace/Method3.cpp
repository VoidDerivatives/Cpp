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
using namespace one;
// using namespace two;
// ithech error yenar karan jeva doghnche baher yetat tevach error yete

int main(void)
{
	cout<<"No1 is :\t"<<no1<<endl;  // one :: no1  10
	cout<<"No2 is :\t"<<no2<<endl;  // no2         60

	cout<<"No1 is :\t"<<two :: no1<<endl;   // 10
	cout<<"No2 is :\t"<<two :: no2<<endl;  // 20

	return 0;
}

		
		
		
		
		
		
		
		
		
				 
