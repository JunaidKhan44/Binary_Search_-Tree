#include<iostream>
#include<string>
using namespace std;
class product;
product* first=NULL;
int c=0;
class product
{
   int id;
   int price;
   product* leftadd;
   product * rightadd;
public:
	void input()
   {
	   product * x=new product;
	   	c++;
	   cout<<"Enter Id"<<endl;
	   cin>>x->id;
	   cout<<"Enter Price"<<endl;
	   cin>>x->price;
	   x->leftadd=NULL;
	   x->rightadd=NULL;
	   if (first==NULL)
	   {
		   first=x;
	   }
	   else
	   {
		   product* y=first;
		   while (true)
		   {
			   if (y->price>=x->price)
			   {
				   if (y->leftadd==NULL)
				   {
					   y->leftadd=x;
					   break;
				   }
				   else
				   {
					   y=y->leftadd;
				   }
			   }
			   else
			   {
				   if(y->rightadd==NULL)
				   {
					   y->rightadd=x;
					   break;
				   }
				   else
				   {
					   y=y->rightadd;
				   }
			   }
		   }
	   }

   }
	void Inorder(product * root)
	{
		if (root==NULL)
		{
			return;
		}
		else
		{
			Inorder(root->leftadd);
			cout<<"Id is "<<root->id<<endl;
			cout<<"Price is "<<root->price<<endl;
			Inorder(root->rightadd);
		}
	}

	void Peerorder(product * root)
	{
		if (root==NULL)
		{
			return;
		}
		else
		{
			
			cout<<"Id is "<<root->id<<endl;
			cout<<"Price is "<<root->price<<endl;
			Inorder(root->leftadd);
			Inorder(root->rightadd);
		}
	}

		void Postrorder(product * root)
	{
		if (root==NULL)
		{
			return;
		}
		else
		{
			Inorder(root->leftadd);
			Inorder(root->rightadd);
			cout<<"Id is "<<root->id<<endl;
			cout<<"Price is "<<root->price<<endl;
			
		}
	}
		void search()
		{
			int i;
			cout<<"Enter Price"<<endl;
			cin>>i;
			if (first==NULL)
			{
				cout<<"Empty"<<endl;
			}
			else
			{
				product * t=first;
				while (t!=NULL)
				{
					if (t->price==i)
					{
						break;
					}
					else if(t->price<i)
					{
						t=t->rightadd;
					}
					else
					{
						t=t->leftadd;
					}
				}
				if (t==NULL)
				{
					cout<<"Not Found"<<endl;
				}
				else
				{
					cout<<"Price Match "<<t->id<<" Id "<<t->price<<" Price "<<endl;
				}
			}
		}
		void max(product * t)
		{
			if (t==NULL)
			{
				cout<<"Empty"<<endl;
			}
			else
			{
				while (t->rightadd!=NULL)
				{
					t=t->rightadd;
				}
				cout<<"Maximum is "<<t->price<<endl;
			}
		}
		void min(product * t)
		{

           if (t==NULL)
			{
				cout<<"Empty"<<endl;
			}
			else
			{
				while (t->leftadd!=NULL)
				{
					t=t->leftadd;
				}
				cout<<"Minimum is "<<t->price<<endl;
			}
		}
};
void main()
{
	int in;
	product p;
	do
	{
		cout<<"1 For Input\n2 For Display in In Order\n3 For Display Pre Order\n4 For Display Post Order\n5 For Total Count";
		cout<<"\n6 For Search\n7 For Maximum Price\n8 For Minimum Price\n9 For Exit"<<endl;
		cin>>in;
		switch (in)
		{
		case 1:
			p.input();
			break;
		case 2:
			p.Inorder(first);
			break;
		case 3:
			p.Peerorder(first);
			break;
		case 4:
			p.Postrorder(first);
			break;
		case 5:
			if (c==0)
			{
				cout<<"Empty"<<endl;
			}
			else
			{
				cout<<"Count is "<<c<<endl;
			}
			break;
		case 6:
			p.search();
			break;
		case 7:
			p.max(first);
			break;
		case 8:
				p.min(first);
			break;
		case 9:
			cout<<"The End"<<endl;
			break;
		}
	} while (in!=9);




	system("pause");
}