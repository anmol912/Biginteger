#include<iostream>
#include<malloc.h>
using namespace std;
struct node{
	int info;
	struct node *next;
};
typedef struct node node;
int len(node *head)
{
	int c=0;
	node *i=head;
	while(i!=NULL)
	{
		i=i->next;
		c++;
	}
	return(c);
}
node *insert(node *head,int d)
{
	node *p;
	p=(node *)malloc(sizeof(node));
	if(p!=NULL)
	{
		if(head==NULL)
		{
			p->info=d;
			p->next=NULL;
			head=p;
		}
		else
		{
			p->next=head;
			p->info=d;
			head=p;
		}
	}
	else
	cout<<"\nNOT ENOUGH MEMORY";
	return(head);
}
node *reverse(node *head)
{
	node *i=head;
	head=NULL;
	while(i!=NULL)
	{
		head=insert(head,i->info);
		i=i->next;
	}
	return(head);
}
node *add(node *head1,node *head2)
{
	node *i=head1;
	node *j=head2;
	node *head3=NULL;
	int c=0,r;
	while(i!=NULL&&j!=NULL)
	{
		r=i->info+j->info+c;
		if(r>=10)
		{
			r=r-10;
			c=1;
		}
		else
		c=0;
		head3=insert(head3,r);
		i=i->next;
		j=j->next;
	}
	if(j==NULL)
	{
		while(i!=NULL)
		{
			r=i->info+c;
			if(r>=10)
			{
				r=r-10;
				c=1;
			}
			else
			c=0;
			head3=insert(head3,r);
			i=i->next;
		}
	}
	else
	{
		while(j!=NULL)
		{
			r=j->info+c;
			if(r>=10)
			{
				r=r-10;
				c=1;
			}
			else
			c=0;
			head3=insert(head3,r);
			j=j->next;
		}
	}
	if(c==1)
	head3=insert(head3,c);
	return(head3);
}
node *sub(node *head1,node *head2)
{
	node *i=head1;
	node *j=head2;
	node *k=NULL;
	node *head3=NULL;
	int r;
	while(i!=NULL&&j!=NULL)
	{
		if(i->info<j->info)
		{
			k=i;
			if(i->next==NULL)
			{
				r=j->info-i->info;
				head3=insert(head3,r);
			}
			else
			{
				i->info=i->info+10;
				while(k->next->info==0)
				{
					k=k->next;
					k->info=9;
				}
				k->next->info=k->next->info-1;
				r=i->info-j->info;
				head3=insert(head3,r);
			}
		}
		else
		{
			r=i->info-j->info;
			head3=insert(head3,r);
		}
		i=i->next;
		j=j->next;
	}
	if(j==NULL&&i!=NULL)
	{
		while(i!=NULL)
		{
			head3=insert(head3,i->info);
			i=i->next;
		}
	}
	return(head3);
}
node *mul(node *head1,node *head2)
{
	node *i=head1;
	node *j=head2;
	node *head3=NULL;
	node *head4=NULL;
	node *head5=NULL;
	int c=0,r,z=1,k;
	while(j!=NULL)
	{
		i=head1;
		c=0;
		head4=NULL;
		head5=NULL;
		if(j==head2)
		{
			while(i!=NULL)
			{
				r=(j->info*i->info)+c;
				if(r>=10)
				{
					c=r/10;
					r=r%10;
				}
				else
				c=0;
				head3=insert(head3,r);
				i=i->next;
			}
			if(c!=0)
			head3=insert(head3,c);
		}
		else
		{
			for(k=0;k<z;k++)
			head4=insert(head4,0);
			while(i!=NULL)
			{
				r=(j->info*i->info)+c;
				if(r>=10)
				{
					c=r/10;
					r=r%10;
				}
				else
				c=0;
				head4=insert(head4,r);
				i=i->next;
			}
			if(c!=0)
			head4=insert(head4,c);
			z++;
		}
		if(head4!=NULL)
		{
			head3=reverse(head3);
			head4=reverse(head4);
			head5=add(head3,head4);
			head3=head5;
		}
		j=j->next;
	}
	return(head3);
}
int main()
{
	node *head1=NULL;
	node *head2=NULL;
	node *head3=NULL;
	node *z=NULL;
	string s,s1,s2,s3;
	int i=0,r,j,x,k=0,l1,l2,z1=0,z2=0;
	char choice;
	do
	{
		head1=NULL;
		head2=NULL;
		head3=NULL;
		z=NULL;
		k=0;
		z1=0;
		z2=0;
		cout<<"Press your choice->\n1-Addition\n2-Subtraction\n3-Multiplication\nchoice= ";
		cin>>x;
		if(x==1||x==2||x==3)
		{
			cout<<"\nenter the first number = ";
	        cin>>s;
			cout<<"\nenter the second number = ";
			cin>>s1;
			if(s[0]=='-')
			k=1;
			else
			k=0;
			while((s[k]-48)==0&&k<s.length())
			k++;
			if(k>(s.length()-1))
			z1=1;
			else
			{
				for(i=k;s[i]!='\0';i++)
				{
					r=s[i]-48;
					head1=insert(head1,r);
				}
				l1=len(head1);
		    }
			if(s1[0]=='-')
			k=1;
			else
			k=0;
			while((s1[k]-48)==0&&k<s1.length())
			k++;
			if(k>(s1.length()-1))
			z2=1;
			else
			{
				for(i=k;s1[i]!='\0';i++)
				{
					r=s1[i]-48;
					head2=insert(head2,r);
				}
				l2=len(head2);
			}
			cout<<"\n";
		}
		switch(x)
		{
			case 1:
				if(z1==1&&z2==1)
				cout<<"Addition = 0";
				else
				{
					if((s[0]!='-'&&s1[0]!='-')||(s[0]=='-'&&s1[0]=='-'))
					{
						if(s[0]!='-'&&s1[0]!='-')
						cout<<"Addition = ";
						else
						cout<<"Addition = -";
						head3=add(head1,head2);
					}
					else if(s[0]=='-'&&s1[0]!='-')
					{
						for(k=1;s[k]!='\0';k++)
						s2=s2+s[k];
						if(l2<l1)
						{
							cout<<"Addition = -";
							head3=sub(head1,head2);
						}
						else if(l2==l1)
						{
							if(s1<s2)
							{
								cout<<"Addition = -";
								head3=sub(head1,head2);
							}
							else
							{
								cout<<"Addition = ";
								head3=sub(head2,head1);
							}
						}
						else
						{
							cout<<"Addition = ";
							head3=sub(head2,head1);
						}
					}
					else if(s[0]!='-'&&s1[0]=='-')
					{
						for(k=1;s1[k]!='\0';k++)
						s2=s2+s1[k];
						if(l2>l1)
						{
							cout<<"Addition = -";
							head3=sub(head2,head1);
						}
						else if(l2==l1)
						{
							if(s2>s)
							{
								cout<<"Addition = -";
								head3=sub(head2,head1);
							}
							else
							{
								cout<<"Addition = ";
								head3=sub(head1,head2);
							}
						}
						else
						{
							cout<<"Addition = ";
							head3=sub(head1,head2);
						}
					}
					z=head3;
					while(z->info==0&&z->next!=NULL)
					z=z->next;
					if(z->info==0)
					cout<<"0";
					else
					{
						head3=z;
						while(head3!=NULL)
						{
							cout<<head3->info;
							head3=head3->next;
						}
					}
				}
				break;
			case 2:
				if(z1==1&&z2==1)
				cout<<"Subtraction = 0";
				else
				{
					head3=NULL;
					if(s[0]!='-'&&s1[0]!='-')
					{
						if(l1<l2)
						{
							cout<<"Subtraction = -";
							head3=sub(head2,head1);
						}
						else if(l2==l1)
						{
							if(s<s1)
							{
								cout<<"Subtraction = -";
								head3=sub(head2,head1);
							}
							else
							{
								cout<<"Subtraction = ";
								head3=sub(head1,head2);
							}
						}
						else
						{
							cout<<"Subtraction = ";
							head3=sub(head1,head2);
						}
					}
					else if(s[0]=='-'&&s1[0]!='-')
					{
						cout<<"Subtraction= -";
						head3=add(head1,head2);
					}
					else if(s[0]!='-'&&s1[0]=='-')
					{
						cout<<"Subtraction= ";
						head3=add(head1,head2);
					}
					else if(s[0]=='-'&&s1[0]=='-')
					{
						for(k=1;s[k]!='\0';k++)
						s2=s2+s[k];
						for(k=1;s1[k]!='\0';k++)
						s3=s3+s1[k];
						if(l1>l2)
						{
							cout<<"Subtraction = -";
							head3=sub(head1,head2);
						}
						else if(l2==l1)
						{
							if(s2>s3)
							{
								cout<<"Subtraction = -";
								head3=sub(head1,head2);
							}
							else
							{
								cout<<"Subtraction = ";
								head3=sub(head2,head1);
							}
						}
						else
						{
							cout<<"Subtraction = ";
							head3=sub(head2,head1);
						}
					}
					z=head3;
					while(z->info==0&&z->next!=NULL)
					z=z->next;
					if(z->info==0)
					cout<<"0";
					else
					{
						head3=z;
						while(head3!=NULL)
						{
							cout<<head3->info;
							head3=head3->next;
						}
					}
				}
				break;
			case 3:
				if(z1==1||z2==1)
				cout<<"Multiplication = 0";
				else
				{
					head3=NULL;
					cout<<"\n";
					if((s[0]=='-'&&s1[0]=='-')||(s[0]!='-'&&s1[0]!='-'))
					cout<<"Multiplication= ";
					else if((s[0]!='-'&&s1[0]=='-')||(s[0]=='-'&&s1[0]!='-'))
					cout<<"Multiplication= -";
					if(s<s1)
					head3=mul(head2,head1);
					else
					head3=mul(head1,head2);
					while(head3!=NULL)
					{
						cout<<head3->info;
						head3=head3->next;
					}
				}
				break;
			default:
				cout<<"you enter wrong choice";
				break;
		}
		cout<<"\ndo you want to continue press y otherwise n= ";
		cin>>choice;
		if(choice=='n')
		exit;
	}while(choice=='y');
	cout<<"\n";
	return(0);
}
