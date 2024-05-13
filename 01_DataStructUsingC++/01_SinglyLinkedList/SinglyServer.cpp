#include<iostream>
#include "SinglyServerh.h"
using std :: cout;
using std :: cin;
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
void list :: InsertLast(int no)
{
	node *newnode = NULL;
	node *temp = NULL;

	newnode = new node;

	if(newnode == NULL)
	{
		cout<<"Memory allocation Failed"<<endl;
		return;
	}	

	newnode -> data = no;
	newnode -> next = NULL;
	if(first == NULL)   // for single Node
	{		
		first = newnode;
		return;
	}
	temp = first;
	while(temp->next != NULL)
	{
		temp = temp-> next;	
	}
	temp -> next = newnode; 	
	
	newnode = NULL; //sanskar	
	temp = NULL;    //sanskar
	
}
void list :: InsertFirst(int no)
{
	node *newnode = NULL;
	newnode = new node;
	
	if(newnode == NULL)
	{
		cout<<"Memory alloaction failed";
		return;
	}	
	
	newnode -> data = no;
	newnode -> next = NULL;
			
	if(first == NULL)
	{
		first = newnode;
		return; 
	}
	newnode -> next = first;
	first = newnode;
	
	newnode = NULL;
	
}
void list :: InsertAtPosition(int no,int pos)    
{
	node *newnode = NULL;
	node *temp = NULL;
	int count;
	
	if(pos == 1)
	{
		InsertFirst(no);
		return;
	}
	newnode = new node;
	
	if(newnode == NULL)
	{
		cout<<"memory allocation failed";
		return;
	}

	newnode -> data = no;
	temp = first;
	count = 1;

	while(count < pos-1)
	{
		count++;
		temp = temp->next;
	}
	newnode->next = temp->next;
	temp->next = newnode;
	//sanskar
	temp=NULL;
	newnode = NULL;
}
int list :: DeleteFirstNode()
{
	int no;
	node *temp = first;
	if(first == NULL)
		return -1;
	

	no = temp -> data;
	first =  temp -> next;
	temp -> next = NULL;
	
	delete temp;

	temp = NULL; 

	return no;
}
int list :: DeleteLastNode() 
{
	struct node *temp = NULL;
	int data;
	
	if(first == NULL)
	{
		cout<<"List is Empty";
		return -1;
	}
	temp = first;
	if(temp -> next == NULL)
	{   				//only one node
		data = temp -> data;
		delete temp;            //first as well as last node
		first = NULL;           //here list becomes empty
		return data;
	}

	while(temp->next->next != NULL)
	{
		temp = temp->next;													   
	}

	data = temp->next->data;   
	delete temp->next;      //last node deleted
	temp -> next = NULL;    //second last becomde last
	temp = NULL;		//sanskar
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
	if(first == NULL)
	{
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
	node *current = first;
	node *prev = NULL;
	node *Next = NULL;
	
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
void list :: ConcatList(list &second)
{
	node *temp = first;
	
	if(second.first == NULL)
		return;
	
	if(temp == NULL)
	{
		first = second.first;
		second.first = NULL;
		return;
	}

	while(temp -> next != NULL)
		temp = temp -> next;

	temp -> next = second.first;
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

	/*if(pos == 1)
	{
		temp2 -> next = temp1;
		first = second.first; 	
		second.first = NULL;
		return;	
	}*/

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
int list :: CountNode()
{
	node *temp = first;
	int count = 0;
	
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count; 									
}
void list :: display()
{
	node *temp = first;
	
	cout<<"--------------Singly List -------------"<<endl;
	if(temp == NULL)
	{
		cout<<"List is empty"<<endl;	
		return;
	}
		
	while(temp != NULL)
	{
		cout<<"|"<<temp -> data<<"|->";
		temp = temp -> next;
	}	

	cout<<endl;
}
void list :: DeleteAllNode()
{
	node *temp = NULL;
	
	if(first == NULL)
	{
		cout<<"List is Empty"<<endl;
		return ;
	}
	while(first != NULL)
	{
		temp = first;
		first = temp->next;
		temp->next = NULL;
		delete temp;
	}
	cout<<"Deleted all nodes successfully"<<endl;
}
