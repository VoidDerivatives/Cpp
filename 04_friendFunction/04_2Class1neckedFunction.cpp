#include<iostream>
using namespace std; 
class demo1;
class demo2;

void swap(demo1 & , demo2 &);

class demo1
{
	int no;

	public :
	void set(int no)
	{
		this -> no = no;
	}
	
	void get()
	{	
		cout<<"In demo1 no is "<<no<<endl;
	}	
	friend void swap(demo1 & , demo2 &);
	
};
class demo2
{

	int no;

	public :
	void set(int no)
	{
		this -> no = no;
	}
	
	void get()
	{	
		cout<<"In demo1 no is "<<no<<endl;
	}
	friend void swap(demo1 & , demo2 &);	

};

void swap(demo1 &refdemo1 , demo2 &refdemo2)
{
	refdemo1.no = refdemo1.no + refdemo2.no;
        refdemo2.no = refdemo1.no - refdemo2.no;
	refdemo1.no = refdemo1.no - refdemo2.no;	

}

int main(void)
{
	demo1 obj1;
	demo2 obj2;

	obj1.set(10);
	obj2.set(20);

	cout<<"Before Swapping "<<endl;

	obj1.get();
	obj2.get();

	swap(obj1,obj2);	
	cout<<"After Swapping "<<endl;

	obj1.get();
	obj2.get();


}


