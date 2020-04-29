#include<iostream>
using namespace std;
int main()
{
int i,j;	
int array[5];
int *p;
p=array;
cout<<"Enter the elements- ";
for(i=0;i<5;i++)
	{
		cin>>*(p+i);
	
		
		
		
	}
	cout<<"You entered-    ";
	for (j=0;j<5;j++)
	{
			cout<< *(p+j)<< endl;
	
		
	

    }
	
return 0;	
	
}
