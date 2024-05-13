#include<iostream>
#include "DoublyServerh.h"
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

void list :: InsertLast(int no)
{
	node *newnode = NULL;
	node *temp = NULL;

	newnode = new node;
	
	if(newnode == NULL)
	{
		cout<<"Memory allocation Failed";
		return ;
	}

	newnode -> data = no;
	newnode -> next = NULL;

	if(first == NULL)
	{
		first = newnode;
		newnode -> prev = NULL;
		return;
	}

	temp = first;
	while(temp->next != NULL)
		temp = temp->next;
	
	temp -> next = newnode;
	newnode -> prev = temp;
	//sanskar
	temp=NULL;
	newnode=NULL;
}
void list :: InsertFirst(int no)
{
	node *newnode = NULL;

	newnode = new node;
	
	if(newnode == NULL)
	{
		cout<<"Memory allocation Failed";
		return ;
	}

	newnode -> data = no;
	newnode -> prev = NULL;

	if(first == NULL)
	{
		newnode -> next = NULL;
		first = newnode;
		return ;
	}

	newnode -> next = first;
	first -> prev = newnode;
	first = newnode;
	//sanskar
	newnode=NULL;

}
void list :: InsertAtPosition(int no,int pos)
{
	int count;
	node *newnode = NULL;
	node *temp = NULL;

	newnode = new node;
	
	count = CountNode();

	if(newnode == NULL)
	{
		cout<<"Memory allocation Failed";
		return ;
	}

	if(pos == 1)
	{
		InsertFirst(no);
		return ;
	}

	if(pos == count+1)
	{
		InsertLast(no);
		return ;
	}

	newnode->data=no;
	count = 1;
	temp = first;
	while(count < pos-1)
	{
		count++;
		temp = temp->next;
	}

	newnode->next = temp->next;
	temp->next->prev = newnode;
	newnode->prev = temp;
	temp->next = newnode;

	temp=NULL;
	newnode=NULL;

}
int list :: DeleteFirstNode()
{
	int data;
	
	if(first == NULL)
	{
		return -1;
	}
	data = first->data;

	if(first->next == NULL)
	{
		delete first;
		first = NULL;
	}
	else
	{
	first = (first)->next;
	(first)->prev->next = NULL;
	delete first->prev;
	first->prev = NULL;
	}
	return data; 
}
int list :: DeleteLastNode()
{
	struct node *temp = NULL;
	int data;
	
	if(first == NULL)
		return -1;

	temp = first;
	while(temp->next != NULL)
		temp = temp->next;

	data = temp->data;

	if(temp->prev == NULL)
	{
		first = NULL;
	}
	else
	{
	temp->prev->next = NULL;
	temp->prev = NULL;
	}

	delete temp;
	temp = NULL;
	return data;
}
int list :: DeleteAtPosition(int pos)
{
	int count;

	node *temp = NULL;
	
	if(first == NULL)
	{
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
	count=1;
	while(count < pos)
	{
		count++;
		temp = temp->next;
	}
	 
	 count = temp->data;
	 temp->prev->next = temp->next;
	 temp->next->prev = temp->prev;
	 temp->next = NULL;
	 temp->prev = NULL;

	 delete temp;
	 temp = NULL;
	 return count;             // data = count variable is used
}
int list :: SearchFirstOccurance(int key)
{
	int pos = 0;
	node *head = first;
		
	if(head == NULL)
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
		pos = 0;
	return pos;

}
int list :: SearchLastOccurance(int key)
{
	int pos = 0;
	int lastpos = pos;
	node *head = first;
		
	if(head == NULL)
	{
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
	int count = 0;
	node *head = first;
	
	if(head == NULL)
	{
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
	node *PREV = NULL;
	node *current = first;
	node *NEXT = NULL;
	
	if(first == NULL)
	{
		cout<<"List is Empty";
		return ;
	}
	while(current != NULL)
	{
		NEXT = current->next;
		current->next = PREV;
		current->prev = NEXT;
		PREV = current;
		current = NEXT;
	}
	first = PREV;
}
void list :: ReverseDisplay()
{
	node *head = first;
	if(head == NULL)
	{
		cout<<"List is Empty";
		return ;
	}
	while(head->next != NULL)
	{
		head = head->next;
	}

	while(head)
	{
		cout<<"<-|"<<head -> data<<"|->";
		head = head->prev;
	}
}
void list :: ConcatList(list &second)
{
	struct node *temp = NULL;
	if(second.first == NULL)
	{
		return ;
	}
	if(first == NULL)
	{
		first = second.first;
		first = NULL;
		return ;
	}
	temp = first;
	
	while(temp->next != NULL)
		temp = temp->next;
	
	temp->next = second.first;
	(second.first)->prev = temp;
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
		second.ConcatList(*this);  //*this karan ghenara reference ahee so mala object pathavaycha ahee 
		first = second.first;
		second.first = NULL;
		return ;
	}

	temp1 = first;
	temp2 = second.first;
	count = 1;
	while(count<pos-1)
	{
		count++;
		temp1 = temp1->next;
	}
	count = CountNode();
	if(pos-1 == count)
	{
		temp1->next=temp2;
		temp2->prev=temp1;
		second.first = NULL;
		return ;
	}
	
	while(temp2->next != NULL)    
	temp2 = temp2->next;

	temp2->next = temp1->next;
	temp1->next->prev = temp2;
	temp1->next = second.first;
	(second.first)->prev = temp1;
	
	second.first = NULL;
	//temp1 = NULL;
	//temp2 = NULL;
}
void list :: display()
{
	cout<<endl<<endl<<"**** Doubly Linked List ****"<<endl<<endl;
	
	node *head = first;	

	if(head == NULL)
	{
		cout<<"List is Empty\n";
		return;
	}
	while(head != NULL)
	{
		cout<<"<-|"<<head -> data <<"|->";
		head = head->next;
	}
	cout<<endl;
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
void list :: DeleteAllNode()
{
	node *temp = NULL;
	node *head = first;	

	if(head == NULL)
	{
		cout<<"List is Empty"<<endl;
		return ;
	} 
	while(head != NULL)
	{
		temp = head;
		head = temp->next;
		temp->next = NULL;
		temp->prev=NULL;
		delete temp;
		temp=NULL;
	}
	first = NULL;
	cout<<"Deleted all nodes successfully"<<endl;
}
