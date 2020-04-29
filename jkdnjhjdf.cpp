
#include<iostream>
using namespace std;
 
 class time 
 {
 		public:
 		int hour,min,sec;
 		string str;
 		 time();
 		void showTime();
 		void setTime(int a,int b,int c);
 		void timeFor();
 	
 }
 t1;
 
  time::time()
 {
 	int h, m, s;
 	cout<<"Enter" <<endl<<"hours- ";
	cin>>h;
	cout<<"\nminutes- ";
	cin>>m;
	cout<<"\nseconds- ";
	cin>>s;
	t1.hour=h;
	t1.min=m;
	t1.sec=s;

}
void time::setTime(int a,int b,int c)
{
	if (a>=60)
	{
		a=a-60;
		b=b+1;
		time::setTime(a,b,c);
	}
	else if (b>=60)
	{
		b=b-60;
		c=c+1;
		time::setTime(a,b,c);
	}
	else if(c>=24)
	{
		c=c-24;
		time::setTime(a,b,c);
		
		
	}
	else
	{
	  t1.hour=c;
	  t1.min=b;
	  t1.sec=a;
	
	
	
	}
	
	
	
	
	
}




void time::timeFor()
{
cout<<"Choose time format\n1. 24 hour system \n2. 12 hour system  \n3. In seconds.\n";
int a;
cin>>a;
switch(a)
{
	case 1: 
	time::showTime();
	break;
	case 2:
    if(t1.hour==0&& t1.min==0&& t1.sec==0)
    {
    	t1.hour=12;
    	t1.str=" midnight";
	}
	else if(t1.hour==12&&t1.min==0&& t1.sec==0)
	
	{
		t1.str=" noon";	
	}
	else if(t1.hour>12)
	
	{
		t1.hour=t1.hour-12;
		t1.str=" PM";
	}
	else if(t1.hour==12)
	
	{
	
		t1.str=" PM";
	}
	else
	{
		t1.str=" AM";
	}
	time::showTime();
	cout<<t1.str;
	break;
	
	case 3:
	t1.sec=(t1.hour*24*60)+(t1.min*60)+t1.sec;
	cout<<t1.sec<<" secs";
	break;
}
}
void time::showTime()
{
	cout<<endl<<time::hour<<":"<<time::min<<":"<<time::sec;
	
}
int main()
{
	t1.setTime(t1.sec,t1.min,t1.hour);
	t1.timeFor();
	
	
	return 0;
	
	
}
