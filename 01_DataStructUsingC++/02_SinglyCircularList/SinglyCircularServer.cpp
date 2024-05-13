#include<iostream>
#include "Serverh.h"

using std :: cout;
using std :: endl;

list :: list()
{
	first = NULL;
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
	data = 0;
	next = NULL;
}
node :: ~node()   // ?
{ 
	data = 0;
	if(next != NULL)
	{
		delete next;
		next = NULL;
	}	
}	

void list :: InsertFirst(int no)
{
	node *newnode = NULL;
	
	newnode = new node;

	if(newnode == NULL)
	{
		cout<<"Memory allocation failed";
		return ;
	}
	newnode -> data = no;
	/*if(*head==NULL)
	{
		newnode->next=NULL;
		*head=newnode;
		return ;
	}*/
	newnode -> next = first;
	first = newnode;
	newnode = NULL;    // sanskar

}
void list :: InsertLast(int no)
{
	node *newnode=NULL;
	node *temp=NULL;

	newnode = new node;

	if(newnode == NULL)
	{
		cout<<"Memory allocation failed";
		return ;
	}
	newnode -> data = no;
	newnode -> next = NULL;      // as a last node

	if(first == NULL)   //if list is empty
	{
		first = newnode;  //first as well as last node
		return ;
	}
	temp = first;
	while(temp -> next != NULL)
		temp = temp -> next;
	temp -> next = newnode;

	// sanskar
	temp = NULL;   
	newnode = NULL;
}
void list :: InsertAtPosition(int no,int pos)
{
	struct node *newnode = NULL;
	struct node *temp = NULL;
	int count;
	
	if(pos == 1)
	{
		InsertFirst(no);
		return;
	}
	newnode = new node;
	
	if(newnode == NULL)
	{
		cout<<"memory allocation failed"<<endl;
		return;
	}

	newnode->data = no;
	temp = first;
	count = 1;
	while(count < pos-1)
	{
		count++;
		temp = temp -> next;
	}
	newnode -> next = temp -> next;
	temp -> next = newnode;
	//sanskar
	temp = NULL;
	newnode = NULL;
}
int list :: DeleteFirstNode()
{
	int data;
	struct node *temp = NULL;
	
	if(first == NULL)
	{
		cout<<"List is Empty";
		return -1;
	}
	temp = first;
	data = temp -> data;
	first = temp -> next;
	temp -> next = NULL;
	delete temp;
	temp = NULL;
	
	return data;
}
int list :: DeleteLastNode() 
{
	node *temp = NULL;
	int data;
	
	if(first == NULL)
	{
		cout<<"List is Empty";
		return -1;
	}
	temp = first;
	if(temp->next == NULL)
	{   //only one node
		data = temp->data;
		delete temp;            //first as well as last node
		first = NULL;       //here list becomes empty
		return data;
	}

	while(temp->next->next != NULL)
	{
		temp = temp->next;
	}

	data = temp -> next -> data;
	delete temp -> next;      //last node deleted
	temp->next = NULL;    //second last becomde last
	temp = NULL;  //sanskar
	return data;
}
int list :: DeleteAtPosition(int pos)
{
	node *temp = NULL;
	node *temp1 = NULL;
 	
	int count;
	int data;

	if(first == NULL)
	{
		cout<<"List is Empty";
		return -1;
	}
	count = CountNode();
	if(pos == 1)
	{
		return DeleteFirstNode();
	}

	if(pos == count)
	{
		return DeleteLastNode();
	}
	temp = first;
	count = 1;
	while(count < pos-1)
	{
		count++;
		temp = temp -> next;
	}
	temp1 = temp -> next;
	data = temp1 -> data;
	temp -> next = temp1 -> next;
	temp1 -> next = NULL;
	delete temp1;
	temp1 = NULL;  //sanskar
	return data;
}
int list :: SearchFirstOccurance(int key)
{
	int pos = 0;
	node *head = first;

	if(head == NULL)
	{
		cout<<"List is Empty";
		return -1;
	}
	while(head != NULL)
	{
		pos++;
		if(head->data == key)
			break;
		head = head->next;
	}

	if(head == NULL)   
		pos = 0;    //data not fond
	return pos;

}
int list :: SearchLastOccurance(int key)
{
	int pos = 0;
	int lastpos = pos;
	node *head = first;

	if(head == NULL)
	{
		cout<<"List is Empty";
		return -1;
	}
	while(head != NULL)
	{
		pos++;
		if(head->data == key)
			lastpos = pos;
		head = head->next;
	}
	return lastpos;
}
int list :: SearchAllOccurance(int key)
{
	int count=0;
	node *head = first;
	if(head == NULL)
	{
		cout<<"List is Empty";
		return -1;
	}
	while(head != NULL)
	{
		if(head->data == key)
			count++;
		head = head->next;
	}
	return count;
}
void list :: PhysicalReverse()
{
	struct node *current = first;
	struct node *prev = NULL;
	struct node *Next = NULL;
	
	if(first == NULL)
	{
		cout<<"List is Empty";
		return ;
	}
	while(current != NULL)
	{
		Next = current->next;
		current->next = prev;
		prev = current;
		current = Next;
	}
	first = prev;
}
void list :: ReverseDisplay()
{		
	if(first == NULL)
	{
		cout<<"List is Empty";
		return ;
	}
	PhysicalReverse();

	display();

	PhysicalReverse();

}
int list :: CountNode()
{
	int count = 0;
	node *head = first;	

	while(head != NULL)
	{
		count++;
		head = head->next;
	}
	return count; 
}
void list :: ConcatList(list &second)
{
	node *temp = NULL;
	if(second.first == NULL)
	{
		return ;
	}
	if(first == NULL)
	{
		first = second.first;
		second.first = NULL;
		return ;
	}
	temp = first;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = second.first;
	second.first = NULL;
	temp = NULL;
}
void list :: ConcatAtPosition(list &second,int pos)
{
	int count;
	node *temp1 = NULL;
	node *temp2 = NULL;

	if(second.first == NULL)
		return;

	if(pos == 1)
	{
		second.ConcatList(*this);
		first = second.first;
		second.first = NULL;	
		return ;
	}

	temp1 = first;
	temp2 = second.first;

	while(temp2->next != NULL)
		temp2 = temp2->next;

	count = 1;
	while(count<pos-1)
	{
		count++;
		temp1 = temp1->next;
	}
	temp2->next = temp1->next;
	temp1->next = second.first;
	second.first = NULL;
	//sanskar
	temp1 = NULL;
	temp2 = NULL;
}
void list :: display()
{
	node *head = first;
	cout<<"\n****Singly Circular Linked List ****"<<endl;
	
	if(head == NULL)
	{
		cout<<"List is Empty"<<endl<<endl;
		return ;
	}
	while(head != NULL)
	{
		cout<<"|"<<head -> data<<"|->";
		head = head->next;
	}
	cout<<endl<<endl;
}
void list :: DeleteAllNode()
{
	node *temp = NULL;
	node *head = first;	

	if(first == NULL)
	{
		cout<<"List is Empty"<<endl;
		return ;
	}
	while(head != NULL)
	{
		temp = head;
		head = temp->next;
		temp->next = NULL;
		delete temp;
	}
	first = NULL;
	cout<<"Deleted all nodes successfully"<<endl;
}
