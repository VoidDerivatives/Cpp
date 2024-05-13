#include<iostream>
#include "SinglyServerh.h"
using std :: cout;
using std :: cin;
using std :: endl;

int main()
{
	list obj;
	list obj1;

	int pos;
	int pos1;
	int choice;
	int data;
	int count;
	int choice1;

	BACK:do
	{
		cout<<"1]Insert First "<<endl<<"2]Insert Last"<<endl<<"3]Insert At Position"<<endl;
		cout<<"4]Delete First "<<endl<<"5]Delete Last "<<endl<<"6]Delete At Position"<<endl;
		cout<<"7]search First Occurance"<<endl<<"8]search Last Occurance "<<endl<<"9]search All Occurance"<<endl;
		cout<<"10]physical Reverse "<<endl<<"11]Reverse Display"<<endl;
		cout<<"12]concate List "<<endl<<"13]Concate At position"<<endl;
		cout<<"14]Total count "<<endl;
		cout<<"15]Exit";

		cout<<endl<<endl<<"_______________________________________"<<endl<<endl;
		cout<<"Enter Your choice:\t";
		cin>>choice;
		
		// Imp: we can avoid duplicate code instead of writing following code 
		// I am not following code using just beacause of 'goto' keyword
		// if(first == NULL)  => for case 3 to case 16 expect 1, 2, 12,13
		/*if(choice !=12 && choice !=13)
			if(choice!=1  && choice!=2 choice!=3 && choice<16)
			{
				if(first == NULL)
				{
					printf("List is empty\n");
					goto BACK;
				}
			}*/

		switch(choice)
		{
			case 1: cout<<"_____________________________________"<<endl;
					
				cout<<"Enter the data:\t";
				cin>>data;
				obj. InsertFirst(data);
					
				obj.display();
				cout<<"_____________________________________"<<endl;
					break;
				
			case 2: cout<<"_____________________________________"<<endl;
					
				cout<<"Enter the data:\t";
				cin>>data;
				obj.InsertLast(data);
					
				obj.display();
				cout<<"_____________________________________"<<endl;
					break;

			case 3:cout<<"_____________________________________"<<endl;
		
				cout<<"Enter the position:\t"<<endl;
				cin>>pos;
					
				count = obj.CountNode();
				if(pos<=0  || count+1<pos)
				{
					cout<<"Position is Invaild"<<endl<<endl;
					break;
				}
				cout<<"Enter the data:\t";
				cin>>data;
					
				obj.InsertAtPosition(data,pos);
					
				obj.display();
				cout<<"_____________________________________"<<endl;
				break;

			case 4:	cout<<"_____________________________________"<<endl;
				
					data = obj.DeleteFirstNode();
					if(data == -1)
						cout<<"List is Empty"<<endl;					
					else	
						cout<<"Your deleted Data is:\t"<<data<<endl;
					
					obj.display();
					cout<<"_____________________________________"<<endl;
					break;

			case 5: cout<<"_____________________________________"<<endl;
			
				data = obj.DeleteLastNode();
				if(data == -1)
					cout<<"List is Empty"<<endl;					
				else					
					cout<<"Your deleted Data is:\t"<<data<<endl;
					
				obj.display();
				cout<<"_____________________________________"<<endl;
					break;

			case 6: cout<<"_____________________________________"<<endl;
					
				    cout<<"Enter the position which to be deleted:"<<endl;
				    cin>>pos;
					
				    count = obj.CountNode();
					if(pos<=0  || count<pos)
					{
						cout<<"Position is Invaild"<<endl;
						break;
					}
					data = obj.DeleteAtPosition(pos);
					
					cout<<"Your deleted Data is:\t"<<data;
					
					obj.display();
					cout<<"_____________________________________"<<endl;
					break;

			case 7: cout<<"_____________________________________"<<endl;
					
					cout<<"Enter the data which to be search At first Occurance:";
					cin>>data;
					
					pos = obj.SearchFirstOccurance(data);

					if(pos == 0)
						cout<<"Data not found"<<endl;
					else
						cout<<"Data is found at"<<pos<<" position."<<endl;
					
					obj.display();
					cout<<"_____________________________________"<<endl;
					break;

			case 8:	cout<<"_____________________________________"<<endl;
					
					cout<<"Enter the data which to be search At Last Occurance:\t"<<endl;
					cin>>data;
					
					pos = obj.SearchLastOccurance(data);
					
					if(pos == 0)
						cout<<"Data not found"<<endl;
					else 
					    	cout<<"Data is found at "<<pos<<" position."<<endl;
					
					obj.display();
					cout<<"_____________________________________"<<endl;
					break;

			case 9:cout<<"_____________________________________"<<endl;
					
					cout<<"Enter the data which to be search All (count)Occurance:\t";
					cin>>data;
					
					pos = obj.SearchAllOccurance(data);
					
					if(pos == 0)
						cout<<"Data not found"<<endl;
					else
						cout<<"Total count Is:\t"<<pos<<endl;
					 
					cout<<"_____________________________________"<<endl;
					break;

			case 10:cout<<"_____________________________________"<<endl;
					
					obj.PhysicalReverse();
					
					obj.display();
					cout<<"_____________________________________"<<endl;
					break;

			case 11:cout<<"_____________________________________"<<endl;
					
					obj.ReverseDisplay();

					cout<<"_____________________________________"<<endl;
					break;

			case 13:cout<<"_____________________________________"<<endl;
					cout<<"Enter the position:\t";
					cin>>pos;
					
					count = obj.CountNode();
					if(pos<=0  || count+1<pos)
					{
						cout<<"Position is Invaild"<<endl<<endl;
						break;
					}
					 // jar user ne directly concate at position selete kel tr?
					 // tya sathi khalil logic
					 // accpect second list in 'case 12'
			case 12:cout<<"_____________________________________"<<endl;
					
						
						cout<<"Enter the second list:"<<endl;
						cout<<"Secong List is :"<<endl;
						obj1.display();							
					do
					{
						cout<<"1]Insert First "<<endl<<"2]Insert Last "<<endl<<"3]Insert At Position "<<endl;
						cout<<"4]go Back to main menu "<<endl;
						cout<<"5]select these option for result"<<endl;
						
						cout<<endl<<"Enter your choice:\t";
						cin>>choice1;
						
						switch(choice1)
						{
	
							case 1: cout<<"_____________________________________"<<endl;
						
									cout<<"Enter the data:\t";
									cin>>data;
									obj1.InsertFirst(data);
							
									obj1.display();
									cout<<"_____________________________________"<<endl;
									break;
							case 2: cout<<"_____________________________________"<<endl;
							
									cout<<"Enter the data:\t";
									cin>>data;
									obj1.InsertLast(data);
								
									obj1.display();
									cout<<"_____________________________________"<<endl;
									break;
							case 3: cout<<"_____________________________________"<<endl;
									
									cout<<"Enter the position:\t";
									cin>>pos1;
									count = obj1.CountNode();
									if(pos1 <= 0  || count+1 < pos1)
									{
										cout<<"Position is Invaild"<<endl<<endl;
										break;
									}
										
									cout<<"Enter the data:\t";
									cin>>data;
									obj1.InsertAtPosition(data,pos1);
									
									obj1.display();
									cout<<"_____________________________________"<<endl;
									break;
							case 4:	goto BACK;
								
							case 5: break;  //directly break for concate list
							default:cout<<"Your choice is Invalid please select correct one"<<endl;

							}
					}while(choice1!=5);
				
						// if user wants to do concatAtPostion() then 'if' will excute otherwise else
						if(choice==13)
						{
							obj.ConcatAtPosition(obj1,pos);
							cout<<"***Concate At position***"<<endl;
						}
						else
						{
							//list will concate here
							cout<<"***Your concat list are***"<<endl;
							obj.ConcatList(obj1);
				 		}
						obj.display();
						cout<<"_____________________________________"<<endl;
							break;

			case 14:cout<<"_____________________________________"<<endl;
					obj.display();
					data = obj.CountNode();
					cout<<"Your count is:\t"<<data<<endl;
					
					 cout<<"_____________________________________"<<endl;
					break;

			case 15: cout<<"_____________________________________"<<endl;
					
					cout<<"First List is :"<<endl;	
					obj.DeleteAllNode();
		
					cout<<"Second List is :"<<endl;
					obj1.DeleteAllNode();

					cout<<"_____________________________________"<<endl;
					break;

			default: cout<<"_____________________________________"<<endl<<endl; 
				 cout<<"choice is Invalid"<<endl;
				 break;
		}
	}while(choice!=15);

	return 0;
} 
