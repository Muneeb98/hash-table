#include<iostream>
#include<string>
using namespace std;

int main()
{
	int convertToAscii(string);
	int hashIndex(int);
void search(string [],string);
	const int sizeOfArr=10;
	string key;
	string arr[sizeOfArr];
	int n;
	cout<<"How many strings you want to Enter : ";
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
	cout<<"Enter a string : ";
	getline(cin,key);
	
	int asciiSum=convertToAscii(key);
	int index=hashIndex(asciiSum);
	//cout<<index;
	if(arr[index][0]=='\0')
	{
	arr[index]=key;
	}
	else
	{
		while(arr[index][0]!='\0')
		{
			if(index==sizeOfArr-1)
			{
				index=0;
			}
			else
			index++;
		}
		arr[index]=key;
	}
	
	}
	for(int i=0;i<10;i++)
	{
     	cout<<i<<"  "<<arr[i]<<endl;
	}
	string a="ZAHID";
	search(arr,a);



}
//=======================================================//
int convertToAscii(string str)
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

int hashIndex(int asciiOfKey)
{
	return asciiOfKey%10;
}

//========================================================//

void search(string arr[],string key)
{
	int asciiSum=convertToAscii(key);
	int index=hashIndex(asciiSum);
	string str=arr[index];
	if(str==key)
	cout<<"Yes the string is found i.e "<<str;
	//if(arr[index]==key)
//	return true;
}
