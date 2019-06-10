#include<iostream>
using namespace std;
class node{
	public :char sym;
	node* next;
};

class stack
{
	node* stacktop;
	public:
		stack()
		{
			stacktop=NULL;
		}
		bool isEmpty();
		void view();
		char pop();
		int precedence(char ch);
		void push(char ch);
		
};
int stack::precedence(char ch)
{
	switch(ch)
	{
		case '(':
		case ')':
			return 1;
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 3;
		default:
		 return 0;	
	}
}
void stack::view()
{
	if(!isEmpty())
	{
		node*temp=stacktop;
		while(temp)
		{
			cout<<"\n"<<temp->sym;
			temp=temp->next;
		}
	}
}
void stack::push(char ch)
{
	node* newnode=new node;
	newnode->sym=ch;
	newnode->next=stacktop;
	stacktop=newnode;
	
	
}
char stack::pop()
{
	if(isEmpty())
	{
		return '=';
	}
	else
	{
		char ch=stacktop->sym;
		node* temp=stacktop;
		stacktop=stacktop->next;
		delete temp;
		return ch;
		
	}
}
bool stack::isEmpty()
{
	if(stacktop==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	char ch;
	char temp;
	stack su;
	abc:
	su.push('(');
	string pfx="";
	cout<<"\nEnter the Infix expression";
	do
	{
		cin>>ch;	
		switch(ch)
		{
			
			case '+':	
			case '-':
			case '*':
			case '/':
				while((temp=su.pop())!='(')
				{
				
					if(su.precedence(temp)<su.precedence(ch))
					{
						
						su.push(temp);
						break;
					}
					else
					{
						pfx+=temp;
					}
				}
				
				if(temp=='(')
				{
				su.push('(');
				}
				su.push(ch);
				break;
			case '(':
				su.push(ch);
				break;
				
			case ')':
						while((temp=su.pop())!='(')
			{
					pfx+=temp;
				} 
				break;
			case '=':
				break;
				
			default:
			pfx+=ch;	
			
		}
		
		
		
		
	}while(ch!='=');
		while((temp=su.pop())!='(')
				{
					pfx+=temp;
				} 
	cout<<"\npostfix expression is"<<pfx;
	su.view();
	cout<<"\ndo u wish to conitue";
	cin>>ch;
	if(ch=='y')
		goto abc;
}
