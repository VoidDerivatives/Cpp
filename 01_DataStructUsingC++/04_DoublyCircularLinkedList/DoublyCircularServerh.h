class list;
class node
{
	node *prev;
	int data;
	node *next;
	
	public :
	node();
	~node();
	friend class list;
};
class list 
{
	node *first;
	node *last;

	public :	
	list();
	~list();	
	
	void InsertFirst(list &,int);
	void InsertLast(list &,int);
	void InsertAtPosition(list &,int,int);
	int DeleteFirstNode(list &);
	int DeleteLastNode(list &);
	int DeleteAtPosition(list &,int);
	int SerachFirstOccurance(list &,int);
	int SerachLastOccurance(list &,int);
	int SerachAllOccurance(list &,int);
	void ConcatList(list &,list &,list &);
	void ConcatAtPosition(list &,list &,list &,int);
	void PhysicalReverse(list &);
	void ReverseDisplay(list &);
	int CountNode(list &);
	void DeleteAllNode(list &);
	void display(list &);
};

