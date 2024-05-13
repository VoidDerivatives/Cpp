#include<iostream>
class list;

class node
{
	int data;
	node * next;
	
	public :
	friend class list; 
	node();
	~node();
		
};
class list 
{
	node *first;
	public : 	
	list();
	~list();

	void InsertLast(int);
	void InsertFirst(int);
	void InsertAtPosition(int,int);    
	int DeleteFirstNode();
	int DeleteLastNode(); 
	int DeleteAtPosition(int);
	int SearchFirstOccurance(int);
	int SearchLastOccurance(int);
	int SearchAllOccurance(int);
	void PhysicalReverse();
	void ReverseDisplay();
	void ConcatList(list &);
	void ConcatAtPosition(list &,int);
	void display();
	int CountNode();
	void DeleteAllNode();
};

