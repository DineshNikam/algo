#include<iostream>
using namespace std;

struct node
{
int data;
struct node *next;

};

class stack
{
node *top;
public :
	
	stack()
	{
	top=NULL;
	
	}
	
	int isEmpty()
	{
	if(top==NULL)
		return 1;
	else 
	 	return 0; 
	
	}
	
	void push(int x)
	{
	node *p;
	p=new node;
	p->data =x;
	p->next = top;
	top =p;
	
	}
	
	int pop()
	{int x;
	node *temp;
	x=top->data;
	temp=top;
	top=top->next;
	delete temp;
	
	return x;
	}
	
	int topdata()
	{
	return top->data;
	};
	
    void rev()
    {

    }


	void display()
	{
	node *temp;
	temp =top;
	while(temp!=NULL)
	{
	cout<<temp->data<<"\t";
	temp=temp->next;
	}
	}
	
	
};

/*int main()
{
stack s1;
int n,el,ch;

while(1)
{
cout<<"\nEnter choice : \n1.push\n2.pop\n3.display\n";
cin>>ch;
switch(ch)
{
	case 1 :
	cout<<"Enter element :"<<endl;
	cin>>el;
	s1.push(el);
	break;
	
	case 2 :
	if(s1.isEmpty()==1)
	cout<<"cannot pop list is Empty"<<endl;
	else{
	n=s1.pop();
	cout<<"Element popped out is : "<<n<<endl;
	}
	break;
	
	case 3 :
	s1.display();
	break;
	
}
}
return 0;
}*/
