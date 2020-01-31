/*NAME : DINESH BHARAT NIKAM
ROLL NO 48
DATE OF PERFORMANCE :    /    /20
DATE OF CORRECTION :    /    /20
*/

#include<iostream>
#include<string.h>
#include<math.h>
#include"d1.cpp"

int icp(char x)
{
	switch(x)
	{
		case '+':


		case '-':return 1 ;


		case '*':


		case '/':


		case '%':return 2;


		case '^':return 3;


		case '(':return 4;


		return 5;
	}
}


int isp(char x)
{
	if(x=='(')return 0;
	else if(x=='+'||x =='-')return 1;
	else if(x=='*' || x=='/'|| x=='%')return 2;
	else if(x=='^')return 3;
	return 4;
}

class post
{
	public :

	void inftopof(char inf[],char pof[])
	{ stack s;
	int i, j=0;
	for(i=0;inf[i]!='\0';i++)
	{
		int x=inf[i];

if(isalnum(x))
		{
			pof[j++]=x;
		}
		else if(x=='(')
		{
		s.push(x);
		}
		else if(x==')')
		{
			while((x=s.pop())!='(')
			{
				pof[j++]=x;
			}
		}
		else
		{
			while(!s.isEmpty() && icp(x) <= isp(s.topdata()))
			{
				pof[j++] = s.pop();
			}
			s.push(x);
		}
	}	//end of for


	while(!s.isEmpty())
	{
		pof[j++]=s.pop();

	}
	pof[j]='\0';
	}


void strrev(char inf[])
{
	int i,j;
	i=0;
	j=strlen(inf)-1;
char temp;

while(i<j)
{
		temp=inf[i];
		inf[i]=inf[j];
		inf[j]=temp;
		i++;
		j--;

}

}

void inftopre(char inf[], char pre[])
{  int i;

		strrev(inf);

	for(i=0; inf[i]!='\0';i++)
	{
		if(inf[i]=='(')
			inf[i]=')';

		else if(inf[i]==')')
		     inf[i]='(';
	}
	  inftopof(inf,pre);
	  strrev(pre);
	}

};

class infix
{
	public:
	float eval(char x,float x1,float x2)
	{	switch(x)
		{
		case '+' :return x1 + x2;
		case '-' :return x1 - x2;
		case '*' :return x1 * x2;
		case '/' :return x1 / x2;
		case '%' :return (int)x1 % (int)x2;
		case '^' :return pow(x1,x2);
		}
		return -1;
	}

	float posteval(char post[])
	{
		float x,op1,op2,val;
		stack s;
		for(int i=0;post[i]!='\0';i++)
		{
			x=post[i];
			if(isalpha(x))
			{
				cout<<"\nEnter Value : of "<<x;
				cin>>val;
				s.push(val);
			}
			else if(isdigit(x))
			{
				s.push(x-48);
			}
			else
			{
				op2=s.pop();
				op1=s.pop();
				val=eval(x,op1,op2);
				s.push(val);
			}
		}
		val=s.pop();
		return val;
	}
float prieval(char post[])
	{
		float x,op1,op2,val;
		stack s;
		for(int i=0;post[i]!='\0';i++)
		{
			x=post[i];
			if(isalpha(x))
			{
				cout<<"\nEnter Value : of "<<x;
				cin>>val;
				s.push(val);
			}
			else if(isdigit(x))
			{
				s.push(x-48);
			}
			else
			{
				op1=s.pop();
				op2=s.pop();
				val=eval(x,op1,op2);
				s.push(val);
			}
		}
		val=s.pop();
		return val;
	}

};

int main()
{
	     post p;
		infix i;
		char in[20],po[20], pri[20];
		float j;
		int n,el,ch;

		while(1)
		{
		cout<<"\nEnter choice : \n1.convert infix to postfix\n2. convert infix to prefix 				  \n3.Evaluate postfix\n4.Evaluate prifix \n5.Exit \n";
		cin>>ch;
		switch(ch)
		{
			case 1 :
				cout<<"Enter Equation :";
				cin>>in;
				p.inftopof(in,po);
				cout<<po;
				break;

			case 2 :
				cout<<"Enter Equation :";
				cin>>in;
				p.inftopre(in,pri);
				cout<<pri;
				break;

	  		case 3 :
	  			cout<<"Enter Equation :";
				cin>>in;
				j=i.posteval(in);
	  			cout<<j;
	  			break;

			case 4:
				cout<<"Enter Equation :";
				cin>>in;
	  			p.strrev(in);
	  			j=i.prieval(in);
	  			cout<<j;
	  			break;

			case 5 :
			return 0;
			break;

		}
		}
return 0;
}
/*
Output  :
Enter choice :
1.convert infix to postfix
2. convert infix to prefix
3.Evaluate postfix
4.Evaluate prifix
5.Exit
1
Enter Equation :a+b*c
abc*+
Enter choice :
1.convert infix to postfix
2. convert infix to prefix
3.Evaluate postfix
4.Evaluate prifix
5.Exit
2
Enter Equation :a+b*c
+a*bc
Enter choice :
1.convert infix to postfix
2. convert infix to prefix
3.Evaluate postfix
4.Evaluate prifix
5.Exit
3
Enter Equation :232^*1-
17
Enter choice :
1.convert infix to postfix
2. convert infix to prefix
3.Evaluate postfix
4.Evaluate prifix
5.Exit
4
Enter Equation :-/*3+2121
3

*/
