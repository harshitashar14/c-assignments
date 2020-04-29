#include<iostream>
using namespace std;
int func(int a,int n)
{
if(a==2)
{
	return (1);
}	

else if(a==n)
{
	return(1);
}



else if(a%n==0)
{
	return (0);
	
}
	
	
else
{
	
	func(a,n+1);
	
}	
	
	
	
	
	
	
}
int main()
{
	
	cout<<"enter the number- ";
	int a,t;
	int n=2;
	cin>>a;
	if(a%2!=0)
	{
		t=2;
	}
	
	else
	
	{
	  t=(a/2);
	}
	
	for(int i=2;i<=t;i++)
	{
		if(func(i,n)==1&&func(a-i,n)==1)
		{
			cout<<i<<"+"<<a-i<<endl;
		}
		
		
		
		
		
		
	}
	
return 0;	
	
	
	
}
