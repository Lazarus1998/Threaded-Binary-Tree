
/*
Author: Parag Ghorpade

PROBLEM STATEMENT: Convert given binary tree into threaded binary tree.
*/
 
#include<iostream>
#define MAX 65536
using namespace std;

struct node
{
 int data;
 struct node *left;
 struct node *right;
 bool leftThread,rightThread;
};

	class tbt
	{
 	 struct node *ROOT;
	 public:
	 tbt();
	 void insert(int);
	 void show();
	 bool search(int);
	 void deleteNode(int);
	};


  tbt :: tbt()
{
  ROOT=new (struct node);
  ROOT->data=MAX;
  ROOT->left=ROOT->right=ROOT;
  ROOT->leftThread=true;
}


 void tbt :: insert(int x)
{
 struct node *p,*temp;
 p=ROOT;
 while(1)
   {
    if(x > p->data)
   {
    if(p->rightThread==true)
    break;
    p=p->right;
   }

   else if(x < p->data)
	{
         if(p->leftThread)
         break;
         p=p->left;
        }

   else
	{
          cout<<"\n Duplicate Element!";
          return ;
        }
   }

 temp=new (struct node);
 temp->data=x;
 temp->leftThread=temp->rightThread=true;

 if(x > p->data)
 {
   temp->right=p->right;
   temp->left=p;
   p->right=temp;
   p->rightThread=false;
 }
  else
	{
       	temp->left=p->left;
	temp->right=p;
        p->left=temp;
        p->leftThread=false;
        }
 }


void tbt :: show()
{
  struct node *p,*temp;
  temp=ROOT;
  while(1)
{
    p=temp;
    temp=temp->right;
    if(!p->rightThread)
    {
    while(!temp->leftThread)
    temp=temp->left;
    }
    if(temp==ROOT)
    break;
    cout<<temp->data<<"  ";
   }
}


int main()
{
 tbt obj;
 int x;
 int n,ch,p;
	do{
				    cout<<"\n==========================================\n"
				    	    "\n********THREADED BINARY TREE***********\n"
    	 				 "\nEnter your choice:\n"
         				 "1.Create tbt.\n"
         				 "2.Insert element.\n"
    	 				 "3.Display.\n"
     	 				 "4.Exit.\n"
    	 				 "==============================================\n";
   		
				    cin>>ch;
   		switch(ch)
		{
			case 1:cout<<"\n Enter total number of elements :";
			       cin>>n;
			       cout<<"\n Enter data :";
			       for(int i=1; i<=n; i++)
				{
   				 cin>>x;
   				 obj.insert(x);
  				}
			       cout<<"Threaded binary tree is created successfully!"<<endl;
			       break;

			case 2:cout<<"\n Enter data:";
			       cin>>p;
			       obj.insert(p);
			       break;

			case 3:cout<<"\n Threaded Binary Search Tree:\n";
                 	       obj.show();
			       break;

			case 4:cout<<"\n Exit"<<endl;
			       break;
		}
	}while(ch!=4);
 return 0;
}

