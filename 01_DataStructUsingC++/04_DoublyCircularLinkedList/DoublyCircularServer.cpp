#include <iostream>
#include "Serverh.h"

using std :: cout;
using std :: endl;

list :: list()
{
	first = NULL;
	last = NULL;
}
list :: ~list()
{	
	if(first != NULL)
	{
		delete first;
		first = NULL;
	}
}	
node :: node()
{
	prev = NULL;
	data = 0;
	next = NULL;
}
node :: ~node()
{
	data = 0;
	if(next != NULL)
	{
		delete next;
		next = NULL;
	}
	if(prev != NULL)
	{
		delete prev;
		prev = NULL;
	}
}
void list :: InsertFirst(list &tail,int no)
{
	node *newnode = NULL;

	newnode = new node;

	if(newnode == NULL)
	{
		cout<<"Memory allocation failed";
		return ;
	}
	newnode -> data = no;
	if(first == NULL)
	{
		first = newnode;
		tail.last = newnode;
	}
	else
	{
	newnode -> next = first;
	first -> prev = newnode;
	first = newnode ;
	}
	(tail.last) -> next = first;   //circular effect
	first -> prev = tail.last;   // circular effect
	newnode = NULL;
}
void list :: InsertLast(list &tail,int no)
{
	node *newnode = NULL;

	newnode = new node;

	if(newnode == NULL)
	{
		cout<<"Memory allocation failed";
		return ;
	}
	newnode -> data = no; 
	
	if(first == NULL)
	{
		first = newnode;
		tail.last = newnode;
	}
	else
	{
		tail.last -> next = newnode;
		newnode -> prev = tail.last;
		tail.last = newnode;
	}
	tail.last -> next = first;   //circular effect
	first -> prev = tail.last;   // circular effect
}
void list :: InsertAtPosition(list &tail,int no,int pos)
{
	node *newnode = NULL;
	node *temp = NULL;
	int count ;
	 
	newnode = new node;
	if(newnode == NULL)
	{
		cout<<"Memory allocation failed";
		return ;
	}
	newnode -> data = no;

	if(pos == 1)
	{
		InsertFirst(tail,no);
		return ;
	}
	
	count = CountNode(tail);
	if(pos == count + 1)
	{
		InsertLast(tail,no);
		return ;
	}

	temp = first;
	count = 1;

	while(count < pos - 1 )
	{
		count++;
		temp = temp -> next;
	}
	newnode -> next = temp ->next;
	temp -> next -> prev = newnode;
	temp -> next = newnode;
	newnode -> prev = temp;

	//sanskar
	newnode = NULL;
 	temp = NULL;
}
int list :: DeleteFirstNode(list &tail)
{
	int del_data;
	if(first == NULL)
	{
		cout<<"List is Empty"<<endl;
		return -1;
	}
	del_data = first -> data;
	
	if(first == tail.last)
	{
		first -> next = NULL;
		first -> prev = NULL;
		delete first;
		first = tail.last = NULL;
	}
	else
	{
		first = first -> next;
		(tail.last) -> next -> next = NULL;
		(tail.last) -> next -> prev = NULL;
		delete (tail.last) -> next;
		(tail.last) -> next = first;
		(first -> prev) = tail.last;
	}
	return del_data;

}
int list :: DeleteLastNode(list &tail)
{
	int del_data;
	if(first == NULL)
	{
		cout<<"List is empty";
		return -1;
	}
	del_data = (tail.last)-> data;

	if(first == tail.last)
	{
		first -> next = NULL;
		first -> prev = NULL;
		delete first;
		first = tail.last = NULL;
	}
	else
	{
		tail.last = (tail.last) -> prev;
		(tail.last) -> next ->next = NULL;
		(tail.last) -> next -> prev= NULL;
		delete (tail.last) -> next;
		(tail.last) -> next = first;
		(first) -> prev = tail.last;
	}
	return del_data;

}
int list :: DeleteAtPosition(list &tail , int pos)
{	
	int del_data;
	node *temp = NULL;
	int count;
	
	if(first == NULL)
	{
		cout<<"List is empty";
		return -1;
	}

	if(pos == 1)
	{
		return DeleteFirstNode(tail);
	}

	temp = first;
	count = 1;

	while(count < pos)
	{
		count++;
		temp = temp -> next;
	}
	del_data = temp -> data;

	count = CountNode(tail);

	if(pos == count)
		tail.last = temp->prev;
	
	temp -> prev -> next = temp -> next;
	temp -> next -> prev = temp -> prev;

	temp -> next  = NULL;
	temp -> prev = NULL;
	
	delete temp;
	temp = NULL;
	return del_data;
	 
}  
int list :: SerachFirstOccurance(list &tail,int key)
{
	int pos = 0;
	node *head = first;

	if(first == NULL)
		return pos;

	do
	{
		pos++;
		if(head -> data == key)
			return pos;
		head = head -> next;
	}while(head != (tail.last)->next);
	return 0;
}
int list :: SerachLastOccurance(list &tail,int key)
{
	int pos = 0;
	int lastpos = 0;
	node *head = first;

	if(head == NULL)
		return pos;
	do
	{
		pos++;
		if(head ->data == key)
			lastpos = pos;
		head = head -> next;
	}while(head != (tail.last)->next);

	return lastpos;

}
int list :: SerachAllOccurance(list &tail,int key)
{
	int count = 0;
	node *head = first;

	if(head == NULL)
		return count;
	do
	{
		if(head ->data == key)
			count++;
		head = head -> next;
	}while(head != (tail.last)->next);

	return count;
}
void list :: ConcatList(list &tail1,list &head2,list &tail2)
{
	if(head2.first == NULL)
		return ;

	if(first == NULL)
	{
		first = head2.first;
		tail1.last = tail2.last;
		head2.first = tail2.last = NULL;
		return;
	}

	(tail1.last) -> next = head2.first;
	(head2.first) -> prev = tail1.last;
	(tail2.last) -> next = first;
	first -> prev = tail2.last;
	tail1.last = tail2.last;
	head2.first = tail2.last = NULL;
}
void list :: ConcatAtPosition(list &tail1,list &head2,list &tail2,int pos)
{
	node *temp = NULL;
	int count;
	count = CountNode(tail1);

	if(head2.last == NULL)
		return ;
	if(pos == 1)
	{
		ConcatList(tail2,*this,tail1);
		first = head2.first;
		tail1.last = tail2.last;
		head2.first = NULL;
		tail2.last = NULL;
		return ;
	}
	temp = first;
	count = 1;
	while(count < pos -1)
	{
		count++;
		temp = temp->next;
	}
	if(temp == tail1.last)
		tail1.last = tail2.last; 
	(tail2.last) -> next = temp -> next;
	temp->next ->prev = tail2.last;
	temp -> next = head2.first;
	(head2.first) -> prev = temp;
	(head2.first) = (tail2.last) = NULL;

}
void list :: PhysicalReverse(list &tail)
{
	node *current = first;
	node *NEXT = NULL;
	node *PREV = tail.last;

	if(first == NULL)
		return ;

	do
	{
		NEXT = current -> next;
		current -> next = PREV;
		current -> prev = NEXT;
		PREV = current;
		current = NEXT;
	}while(current != first);
	tail.last = first;
	first = PREV;
}
void list :: ReverseDisplay(list &tail)
{
	if(first == NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}

	cout<<"**** Reverse Display ****"<<endl;
	do
	{
			cout<<"<-|"<< (tail.last)-> data <<"|->";
			tail.last = (tail.last) -> prev;
	}while(first != (tail.last)->next);
	cout<<endl;

}
int list :: CountNode(list &tail)
{
	int count = 0;
	node *head = first;

	if(head == NULL)
		return count;
	do
	{
		count++;
		head = head -> next;
	}while(head != (tail.last)->next);

	return count;
}
void list :: display(list &tail)
{
	node *head = first;
	if(head == NULL)
	{
		cout<<"\nList is empty"<<endl;
		return ;
	}
	do
	{
		cout<<"<-|"<<head -> data<<"|->";
		head = head -> next;
	}while(head != (tail.last) -> next);

	cout<<endl;
}
void list :: DeleteAllNode(list &tail)
{
	node *temp = NULL;
	
	if(first == NULL)
	{
		cout<<"List is Empty";
		return ;
	} 
	do
	{
		temp = first;
		first = temp -> next;
		temp -> next = NULL;
		temp -> prev = NULL;
		delete temp;
		if(first == tail.last)  // only one node is present
		{
			first = tail.last = NULL;
			break;
		}
		(tail.last) ->next = first;
		first -> prev = tail.last;
		temp = NULL;
	}while(first != tail.last);  // more than one node 
	
	cout<<"Deleted all nodes successfully"<<endl;
}
