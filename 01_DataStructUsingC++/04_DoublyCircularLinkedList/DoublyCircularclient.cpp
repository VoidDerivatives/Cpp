#include <iostream>
#include "Serverh.h"

using std :: cout;
using std :: cin;
using std :: endl;

int main(void)
{
	list obj1;
	list obj2;

	int pos;
	int pos1;
	int data;
	int count;
	int choice;
	int choice1; 
	int choice2;

	BACK:do
	{
		cout<<"___________________________________________________________"<<endl;
		cout<<"\t\t\tMain Menu\t\t\t"<<endl;
		cout<<"___________________________________________________________"<<endl;
		cout<<"\t\t1] Insert"<<endl;
		cout<<"\t\t2] Delete"<<endl;
		cout<<"\t\t3] Search"<<endl;
		cout<<"\t\t4] Reverse"<<endl;
		cout<<"\t\t5] Concate"<<endl;
		cout<<"\t\t6] Count"<<endl;
		cout<<"\t\t7] Exit"<<endl;

		cout<<"\nEnter Your choice:\t";
		cin>>choice;
		
		/*if(choice == 2 || choice == 3 || choice == 4 || choice ==7)
			if(first == NULL)
			{
				cout<<"List is Empty"<<endl;
				continue;
			}*/
		switch(choice)
		{
			case 1:	cout<<"_____________________________________"<<endl;
					do
					{
						cout<<"1] Insert first \n2] Insert Last\n3] Insert At Position"<<endl;
						cout<<"4] Back"<<endl;
						cout<<"Enter the choice:\t";
						cin>>choice1;

						switch(choice1)
						{
						case 1: cout<<"_____________________________________"<<endl;
							cout<<"Enter the data:\t";
							cin>>data;
						
							obj1.InsertFirst(obj1,data);
					
							break;

						case 2: cout<<"_____________________________________"<<endl;
					
							cout<<"Enter the data:\t";
							cin>>data;
							obj1.InsertLast(obj1,data);
					
							break;

						case 3: cout<<"_____________________________________"<<endl;
		
							cout<<"Enter the position:\t";
							cin>>pos;
					
							count = obj1.CountNode(obj1);
							if(pos <= 0  || count+1 < pos)
							{
								cout<<"Position is Invaild"<<endl<<endl;
								break;
							}
							cout<<"Enter the data:\t";
							cin>>data;
					
							obj1.InsertAtPosition(obj1,data,pos);
					
							break;
						case 4: break;
						default :cout<<"choice is Invaild"<<endl;
							break;
						}
					obj1.display(obj1);
					cout<<"_____________________________________"<<endl;	
					}while(choice1 != 4);
					break;

			case 2:	cout<<"_____________________________________"<<endl;	
					do
					{
						cout<<"1] Delete First\n2] Delete Last\n3] Delete At Position"<<endl;
						cout<<"4] Back"<<endl;
						cout<<"Enter the choice:\t";
						cin>>choice1;

						switch(choice1)
						{

							case 1:cout<<"_____________________________________"<<endl;
					
									data = obj1.DeleteFirstNode(obj1);
					
									cout<<"Your deleted Data is:\t"<<data<<endl;

									break;

							case 2: cout<<"_____________________________________"<<endl;
									
									data = obj1.DeleteLastNode(obj1);
				
									cout<<"Your deleted Data is:\t"<<data<<endl;
					
									break;

							case 3: cout<<"_____________________________________"<<endl;
									
								cout<<"Enter the position which to be deleted:\t";
								cin>>pos;
				
								count= obj1.CountNode(obj1);
								if(pos<=0  || count<pos)
								{
									cout<<"Position is Invaild"<<endl<<endl;
								
									break;
								}
								data = obj1.DeleteAtPosition(obj1,pos);
					
								cout<<"Your deleted Data is:\t"<<data<<endl;
				
								break;
							
							case 4:break;
							default:cout<<"choice is Invaild";
								break;
							}
						obj1.display(obj1);
						cout<<"_____________________________________"<<endl;
					}while(choice1 != 4);
						break;

			case 3:	cout<<"_____________________________________"<<endl;
					do
					{
						cout<<"1] Serach First occurance"<<endl;
						cout<<"2] search Last Occarance"<<endl;
						cout<<"3] Search All Occuarance"<<endl;
						cout<<"4] back"<<endl;
						
						cout<<"Enter the choice:\t";
						cin>>choice1;

						switch(choice1)
						{
						case 1:	cout<<"_____________________________________\n";
								
								cout<<"Enter the data which to be search At first Occurance:\t";
								cin>>data;
					
								pos = obj1.SerachFirstOccurance(obj1,data);
		
								if(pos == 0)
									cout<<"Data not found\n";
								else
									cout<<"Data is found at "<<pos<<" position."<<endl;
						
								break;
	
						case 2:	cout<<"_____________________________________"<<endl;
							
							cout<<"Enter the data which to be search At Last Occurance:\t";
							cin>>data;
					
							pos = obj1.SerachLastOccurance(obj1,data);
					
							if(pos == 0)
								cout<<"Data not found"<<endl;
							else 
							  cout<<"Data is found at "<<pos<<" position."<<endl;
					
							break;

						case 3:cout<<"_____________________________________"<<endl;
			
							cout<<"Enter the data which to be search All (count)Occurance:\t";
							cin>>data;
					
							pos = obj1.SerachAllOccurance(obj1,data);
						
							if(pos == 0)
								cout<<"Data not found"<<endl;
							else
								cout<<"Total count Is:\t"<<pos<<endl;
					 
							break;
					case 4:break;
					default:cout<<"choice is Invaild";
						break;
						}
						
							obj1.display(obj1);
							cout<<"_____________________________________"<<endl;
					}while(choice1 != 4);
						break;

			case 4:	cout<<"_____________________________________"<<endl;
				do
				   {
					   cout<<"1] Physical Reverse"<<endl;
					   cout<<"2] Reverse Display"<<endl;
					   cout<<"3] Back"<<endl;
					   
					   cout<<"Enetr the choice:\t";
					   cin>>choice1;

					   switch(choice1)
					   {
					   case 1:cout<<"_____________________________________"<<endl;
							
							obj1.PhysicalReverse(obj1);
				
							break;

					   case 2:cout<<"_____________________________________"<<endl;
							
							obj1.ReverseDisplay(obj1);

							break;
					   case 3:break;
					   default:cout<<"choice is Invaild";
							   break;
					   }
					   
							obj1.display(obj1);
							cout<<"_____________________________________"<<endl;
				   }while(choice1 != 3);
					   break;

			case 5:	cout<<"_____________________________________"<<endl;
					do
					{
						cout<<"1] concat List"<<endl;
						cout<<"2] concat At position"<<endl;
						cout<<"3] Back"<<endl;
						
						cout<<"Enter the choice:\t";
						cin>>choice2;
				
						switch(choice2)
						{
						case 2: cout<<"_____________________________________"<<endl;
								cout<<"Enter the position:\t";
								cin>>pos;
					
								count = obj1.CountNode(obj1);
								if(pos<=0  || count+1<pos)
								{
									cout<<"Position is Invaild\n\n";
									break;
								}
					 // jar user ne directly concate at position selete kel tr?
					 // tya sathi khalil logic
					 // accpect second list in 'case 12'
						case 1:cout<<"_____________________________________"<<endl;
							
									cout<<"Your second list sre empty"<<endl;
									cout<<"****second list:****"<<endl;
									obj2.display(obj2);
								do
								{
									cout<<"1]Insert First \n2]Insert Last \n3]Insert At Position"<<endl;
									cout<<"4]go Back to main menu "<<endl;
									cout<<"5]select these option for result"<<endl;
						
									cout<<"\nEnter your choice:\t";
									cin>>choice1;
						
									switch(choice1)
									{
		
										case 1: cout<<"_____________________________________"<<endl;
						
											cout<<"Enter the data:\t";
											cin>>data;
											obj2.InsertFirst(obj2,data);
					
											break;
										case 2: cout<<"_____________________________________"<<endl;
							
												cout<<"Enter the data:\t";
												cin>>data;
												obj2.InsertLast(obj2,data);
								
												break;
										case 3: cout<<"_____________________________________"<<endl;
									
											cout<<"Enter the position:\t";
											cin>>pos1;
											count = obj2.CountNode(obj2);
											if(pos1 <= 0  || count+1 < pos1)
											{
												cout<<"Position is Invaild"<<endl;
												break;
											}
										
											cout<<"Enter the data:\t";
											cin>>data;
											obj2.InsertAtPosition(obj2,data,pos1);
									
											break;
										case 4:	goto BACK;
								
										case 5: break;  //directly break for concate list
										default:cout<<"Your choice is Invalid please select correct one"<<endl;

										}
									
										obj2.display(obj2);
										cout<<"_____________________________________"<<endl;
								}while(choice1!=5);
							
						// if user wants to do concatAtPostion() then 'if' will excute otherwise else
								if(choice2 == 2)
								{
									obj1.ConcatAtPosition(obj1,obj2,obj2,pos);
									cout<<"***Concate At position***"<<endl;
								}
								else
								{
							//list will concate here
									cout<<"***Your concat list are***"<<endl;
									obj1.ConcatList(obj1,obj2,obj2);
				 				}
								obj1.display(obj1);
								cout<<"_____________________________________"<<endl;
								break;
						case 3:break;

						default:cout<<"choice is Invalid";
							break;
					}
					}while(choice2 != 3);
					break;

			case 6:cout<<"_____________________________________"<<endl;
					obj1.display(obj1);
					data = obj1.CountNode(obj1);
					cout<<"Total count is:\t"<<data<<endl;
					
					break;

			case 7: cout<<"_____________________________________\n";
				
					 obj1.DeleteAllNode(obj1);

					 cout<<"_____________________________________\n";
					 break;

			default: cout<<"_____________________________________\n\n"; 
					 cout<<"choice is Invalid\n";
					 break;
		}
	}while(choice != 7);

	return 0;
}
