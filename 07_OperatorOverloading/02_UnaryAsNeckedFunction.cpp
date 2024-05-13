#include<iostream>
using namespace std;
	
class demo;

demo & operator +(demo &refobj);
demo operator -(demo &refobj);
demo operator ~(demo &refobj);
demo operator ++(demo &refobj);
demo & operator ++(demo &refobj,int);
demo operator --(demo &refobj);
demo & operator --(demo &refobj,int);
demo * operator &(demo &refobj);
	
class demo
{
	int i,j;
	
	public : demo(int i = 10,int j = 20)
		{
			this -> i = i;
			this -> j = j;

		}

		demo * This()
		{
			return this;
		}

		friend demo & operator +(demo &refobj);
		friend demo operator -(demo &refobj);
		friend demo operator ~(demo &refobj);
		friend demo operator ++(demo &refobj);
		friend demo & operator ++(demo &refobj,int);
		friend demo operator --(demo &refobj);
		friend demo & operator --(demo &refobj,int);
		friend demo * operator &(demo &refobj);

		void display()
		{
			cout<<"i is :\t"<<i<<endl;
			cout<<"j is :\t"<<j<<endl;
		}

};
demo & operator +(demo &refobj)
{
	cout<<"In unary + operator:"<<endl;
	return refobj;
} 
demo operator -(demo &refobj)
{
	cout<<"In unary - operator:"<<endl;
	return demo(-refobj.i,-refobj.j);
} 
demo operator ~(demo &refobj)
{
	cout<<"In unary ~(not) operator:"<<endl;
	return demo(~refobj.i,~refobj.j);
}
demo operator ++(demo &refobj)
{
	cout<<"In unary pre- increment operator:"<<endl;
	return demo(++refobj.i,++refobj.j);	
}
demo & operator ++(demo &refobj,int)
{
	cout<<"In unary post - increment operator:"<<endl;
	refobj.i++;
	refobj.j++;			
	return refobj;	
}
demo operator --(demo &refobj)
{
	cout<<"In unary pre- decrement operator:"<<endl;
	return demo(--refobj.i,--refobj.j);	
}
demo & operator --(demo &refobj,int)
{
	cout<<"In unary post - decrement operator:"<<endl;
	refobj.i--;
	refobj.j--;			
	return refobj;	
}
demo * operator &(demo &refobj)
{
	cout<<"In unary & opeartor :"<<endl;
	return refobj.This();
}	
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
	
