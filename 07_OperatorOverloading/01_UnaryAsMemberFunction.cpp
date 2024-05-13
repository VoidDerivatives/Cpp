#include<iostream>
using namespace std;

class demo
{
	int i,j;
	
	public : demo(int i = 10,int j = 20)
		{
			this -> i = i;
			this -> j = j;

		}
		// as member function ahee mhun this pointer ahee
		// this = addressof(obj1);
		demo & operator +()
		{
			cout<<"In unary + operator:"<<endl;
			return *this;
		} 
		demo operator -()
		{
			cout<<"In unary - operator:"<<endl;
			return demo(-i,-j);
		} 
		void display()
		{
			cout<<"i is :\t"<<i<<endl;
			cout<<"j is :\t"<<j<<endl;
		}
		demo operator ~()
		{
			cout<<"In unary ~(not) operator:"<<endl;
			return demo(~i,~j);
		}
		demo operator ++()
		{
			cout<<"In unary pre- increment operator:"<<endl;
			return demo(++i,++j);	
		}
		demo & operator ++(int)
		{
			cout<<"In unary post - increment operator:"<<endl;
			i++;
			j++;			
			return *this;	
		}
		demo operator --()
		{
			cout<<"In unary pre- decrement operator:"<<endl;
			return demo(--i,--j);	
		}
		demo & operator --(int)
		{
			cout<<"In unary post - decrement operator:"<<endl;
			i--;
			j--;			
			return *this;	
		}	
};
int main(void)
{
	demo obj1;
	demo obj2;
		
	// demo &
	+obj1;
	obj1.display();

	// demo
	obj2 = -obj1;
	obj2.display();	

	// demo
	obj2 = ~obj1;
	obj2.display();		
	
	// demo
	obj2 = ++obj1;
	obj2.display();	

	// demo &
	obj1++;	
	obj1.display();	

	// demo
	obj2 = --obj1;
	obj2.display();	

	// demo &
	obj1--;	
	obj1.display();	

	return 0;
}
	
