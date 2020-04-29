include<iostream>
include<conio.h>
include<stdio.h>
include<string.h>
include<stdlib>


using namespace std;
static int p=0;  // scope is whole program
class a
{
	char busn[5],driver[10],arrival[5],depart[5],from[10],to[10],seat[8][4][10]	;
	public:
		void install();
		void allotment();
		void empty();
		void show();
		void avail();
		void position(int i);
		
}


bus[10]; //obj
void vline(char c)
{
	for (int i=80;i>0;i--)
	{
		
		cout<<ch;	
	}
	
}

void a::install()
{
	cout<<" Enter bus no: ";
	cin>>bus[p].busn;
	cout<<"\n Enter driver name: ";
	cin>>bus[p].driver;
	cout<<"\n Arrival time: ";
	cin>>bus[p].arrival;
	cout<<"\n Departing time: ";
	cin>>bus[p].depart;
	cout<<"\n from:    ";
	cin>>bus[p].from;
	cout<<"\n to:      ";
	bus[p].empty();		// what??empty func??
	p++
}

void a::allotment()
{
	
	int seat;
	char number[5];
	top:
		cout<<"bus no: ";
		cin>>number;
		int n;
		for(n=0;n<=p;n++)
		{
			if(strcmp(bus[n].busn,number)==0)
			break;
		}
		while(n<=p)
		{
			cout<<"\nSeat number: ";
			cin>>seat;
			if(seat>32)
			{
				cout<<"\nThere are only 32 seats available in thgis bus. ";
				
			}
			else
			{
				
				if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"empty")==0)
					{
						cout<<"Enter passenger's name: ";
						cin>>bus[n].seat[seat/4][(seat%4)-1];
						break;
				
			
					}	
					
					
				else
				{
					cout<<"the seat no. is already reserved.\n
				}	
			}
			
			
			
		}
	
	
	
	
	
	
	
	
	
}



