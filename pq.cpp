#include<iostream>
#include<string.h>
using namespace std;
class Queue
{ struct node
	{
		int pri;
		char name[20];
		struct node *next;
		
	}*front;
	public:
	Queue()
	{
	front =NULL;
	
	}
	
	void insert(char name[10],int pr);
	void remove();
	void display();
	int empty(){if(front == NULL) return 1; else return 0;}
};//End of class

	void Queue :: insert(char name[10],int pr )
	{
		node *temp, *prev, *new1;
		new1=new node;
		strcpy(new1->name,name);
		new1->pri=pr;
		new1->next=NULL;
		if(front ==NULL)
			front=new1;
		else {	temp=front;
				
				while(temp!=NULL&& new1->pri<=temp->pri)
				{
					prev=temp;
					temp=temp->next;
				}	
			
		if(temp==front)
		{
		 new1->next=front;
		 front=new1;
		}
		else
		{
		new1->next=temp;
		prev->next=new1;
		}
	    }
	}
	
	void Queue :: remove()
	{
		node *temp =front;
		front =front->next;
		cout<<"\n Patient : "<<temp->name<<"  got Out for treatment according to priority___  "<<temp->pri;
  delete temp;		
	}
 
 void Queue :: display()
 {
  	node *temp;	
  	temp =front;
  	
  	cout<<"\n Name  \t priority ";
  	while(temp!=NULL)
  	{
  		cout<<"\n"<<temp->name<<"\t"<<temp->pri;
  		temp=temp->next;
  	}
 
 }
 
int main()
{

	Queue q;
	int ch;
	char name[20];
	int pri;
	while(1)
	{
	cout<<"\n****MENU****\n1.Insert NEW Patient in queue \n2.Remove Patient  from queue \n3.Display Patient queue \n4.Exit \n Enter your Choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1:
		cout<<"Enter name and priority :";
		cin>>name>>pri;
				q.insert(name,pri);
			break;
		
		case 2:if(q.empty()==1)
		cout<<"Queue is NUll";
		else 
		q.remove();
			break;
		
		case 3:
		q.display();
			break;
		
		case 4:
		return 0;
			break;
			
		default :
		cout<<"Invalid Choice ";
			
	}
	
	}
	return 0;
	
}
