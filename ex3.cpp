#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
struct node
{
	int data;
	node *l,*r;
	
};
class stack
{
node *data[10];
int top;
public :
	
	stack()
	{
	top=-1;
	
	}
	
	int isEmpty()
	{
		if(top==-1)
			return 1;
		else 
		 	return 0; 
	
		}
	
	void push(node *p)
	{
		data[++top]=p;
	}
	
	node *pop()
	{
		return data[top--];
	}
};
class bt
{
	stack s;
	node *root;

	
	
	public :

	bt()
	{
		root=NULL;
		
	}
	void create1()
	{
		root=create();
		
	}
	
	node *create()
	{
		node *p;
		int x;
			
		cout<<"\n Enter data (-1 to End)";
		cin>>x;
		if(x==-1)
		return NULL;
		else 
		{
			p=new node;
			p->l=p->r=NULL;
			p->data=x;
			
			cout<<"\n Enter left data of :"<<x;
			p->l=create();
			cout<<"\nEnter right data of : "<<x;
			p->r=create();		
		}
  return p;
  		
	}
	
	void disp(node *T)
	{
		if(T!=NULL)
		{
			disp(T->l);
			cout<<"\t"<<T->data;
			disp(T->r);
		}
	}
	void disp1()
	{
	disp(root);
	}
	
	void displ(node *T)
	{
		if(T!=NULL)
		{
			if(T->l==NULL && T->r==NULL)
				cout<<"\t"<<T->data;
			displ(T->l);
			displ(T->r);
		}
	}
	
	void displ1()
	{
	displ(root);
	}
	
	
	int depth(node *T)
	{
		if(T==NULL)
		{
			return 0;
			
		}
		else if(T->l==NULL && T->r==NULL)
		return 0;
		else return(max(depth(T->l),depth(T->r))+1);
	}
	
	int depth1()
	{
		return depth(root);
	}
	    
	void displeaf(node *T)
	{
	if(T!=NULL)
	{if(T->l==NULL && T->r)
	    cout<<"\t"<<T->data;
	    displeaf(T->r);
	    displeaf(T->l);
	}
	}
	
	void displeaf1()
	{
	    displeaf(root);
	}
	
	node *copy(node *T)
	{
	node *p=NULL;
	if(T!=NULL)
	{
	p=new node;
	p->data=T->data;
	p->l=p->r=NULL;
	p->l=copy(T->l);
	p->r=copy(T->r);
	
	}
	return p;
	}
	
void copy1()
    {
        node *T;
        T =copy(root);
        cout<<"\nCopied Tree ";
        disp(T);
    }
    
    
    node *search(node *T,int x)
    {
        while(T!=NULL || !s.isEmpty())
        {
            if(T!=NULL)
            {
                if(x==T->data)
                return T;
               else {
                       s.push(T);
                       T=T->l;
                   }
               }
           else{
           T=s.pop();
           T=T->r;
           }
            }
            return NULL;
        
    }
    
   void search1(int z)
    {
        node *T;
        T =search(root,z);
        if(T!=NULL)cout<<"\nsearch found "<<T->data;
        else cout<<"\n Element not Found \n";
        
    }
    
   
    void insert(int x)
    {
        node *T, *p;
        int old,n;
        cout<<"\n Enter node after which u Want To Insert :";
        cin>>n;
        T=search(root,n);
        if(T==NULL)
         cout<<"\n DAta NoT FoUnD  : ";
       else{
            if(T->l==NULL||T->r==NULL)
            {
                p=new node;
                p->l=p->r=NULL;
                p->data=x;
                if(T->l==NULL)
                T->l=p;
                else T->r=p;
            }
            else cout<<"\nInsertion not possibl.......@!\n";
    }
    }
};


int main()
{
 	bt b;
 	int ch,x;
 
 	b.disp1();
	while(1)
{
	cout<<"\nEnter choice : \n1.create\n2.display\n3.display leaf\n4.copy tree\n5.search \n6.insert new Element \n7.Display Depth\n";
	cin>>ch;
	switch(ch)
	{
	case 1 :
		b.create1();	
	break;
	
	
	
	case 2 :
	 	b.disp1();
	break;
	
	case 3:
		b.displ1();
		break;
	case 4:
	b.copy1();
	break;
	
	case 5:
	cout<<"\nEnter element to Search :";
	cin>>x;
	 b.search1(x);
	 
	break;
	
	case 6:
	cout<<"\nEnter element to insert :";
	cin>>x;
	b.insert(x);
	break;
	
	case 7 :
	x=b.depth1();
	cout<<x;
	break;
	 default :
	  return 1;
	  
	}
	}
	return 0;
	
}
