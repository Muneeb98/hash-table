#include<iostream>
#include<string>
 
using namespace std;


template<class T1>
class Node
{
public:
		
		T1 val;
		Node <T1>*next;
};
template<class T1>
class LinkList
{
	Node <T1>*head;
	Node<T1> *tail;
public:
	LinkList()
	{
		head=NULL;
		tail=NULL;
	}
	void CreateList(int);	
	void Traverse();
	void insert(T1);
	bool Search1(T1);
};





template<class T1>

void LinkList<T1>::insert(T1 str)
{
	if(head==NULL)
	{// T new_obj = new T();
		head=new Node<T1>;
		head->next=NULL;
		head->val=str;
		tail=head;
	}else
	{
		//T* new Node;
		Node<T1> * n=new  Node<T1>;
		//n=new  Node<T>;
		n->next=NULL;
		n->val=str;
		tail->next=n;
		tail=n;
	}
}


template<class T1>
void LinkList<T1>::Traverse()
{
	Node <T1>*Thead;                       //Temp Head
	Thead=this->head;
	//cout<<"\nHead at Start = "<<Thead;
	while(Thead!=NULL)
	{
		cout<<Thead->val<<endl;
		Thead=Thead->next;
	//	cout<<"\nThead= "<<Thead<<endl;
	}
}
//========================================================//
//    This function is to Search a value from List        //
//========================================================//
template <typename T1>
bool LinkList<T1>::Search1(T1 n)
{
	int pos=1;
	Node<T1> * Current=head;
	while(Current!=NULL && Current->val!=n)
	{
		Current=Current->next;
		pos++;
	}

	if (Current==NULL)
		return false;
	else if(Current->val==n)
		return true;
}




///////////////////////////////////////////////


template <typename T1>
class HashChain
{
	LinkList  <T1>*arr;
	int size;
	//string key;
	//string value;
public:
	HashChain(int s)
	{
		size=s;
		arr=new LinkList<T1>[size];
	}
	int convertToAscii(T1);
	int hashIndex(int);
	bool search(T1 ,T1);
	void insert1(T1,T1);
	void show();

};




//=======================================================//
template <typename T1>
int HashChain<T1>:: convertToAscii(T1 str)
{
	int sum=0,ascii;
	for(int i=0;str[i]!='\0';i++)
	{
		ascii=str[i];
		sum=sum+ascii;
	}
	return sum;
}

//=========================================================//
template <typename T1>
int HashChain<T1>::hashIndex(int asciiOfKey)
{
	return asciiOfKey%size;
}

//========================================================//
template <typename T1>
void HashChain<T1>::insert1(T1 key,T1 val)
{
	int asciSum=convertToAscii(key);
	int index=hashIndex(asciSum);
	arr[index].insert(val);

}
//=====================================================//
template <typename T1 >
	bool HashChain<T1>::search(T1 key,T1 val)
	{
		int ascSum=convertToAscii(key);
		int index=hashIndex(ascSum);
		if(arr[index].Search1(val))
			return true;
		else
			return false;
	}
//======================================================//
	
	template <typename T1 >
	void HashChain<T1>::show()
	{
		for(int i=0;i<size;i++)
		arr[i].Traverse();
	}

	


int main()
{
	int n;
	string key,value;
	cout<<"How many Values you want to Enter : ";
	cin>>n;
	HashChain <string> obj(n);
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter a key :  ";
		getline(cin,key);
		cout<<"\nEnter value :  ";
		getline(cin,value);
		obj.insert1(key,value);
	}
	cout<<"Enter key : ";
	getline(cin,key);
	cout<<"Enter value you want to search ";
	getline(cin,value);

	if(obj.search(key,value))
		cout<<"\nFound";
	else
		cout<<"\nNot Found";
	cout<<"\n-----------------------------------------------\n";
	cout<<"\nAll values are \n";
	cout<<"\n-----------------------------------------------\n";
	obj.show();
}