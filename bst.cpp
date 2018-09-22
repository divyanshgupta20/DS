#include<iostream>
using namespace std;
struct node
{
 int data;
 struct node *left;
 struct node *right;
};
typedef struct node node;
class bst
{
 private:
 node *root;
 int tot;

 public:
 bst()
 {
  root=NULL;
  tot=0;
 }
 
 node* create(int val)
 {
    node *t=new node;
    t->data=val;
    t->left=NULL;
    t->right=NULL;
    return t; 
 }
 
 void insert(int val)
 {
    node *t=create(val);
    
    if(root==NULL)
    {  
        root=t;
        tot=0;
    }      
    
    else
    {
      node *temp=root;
      while(temp!=NULL)
      {
         if(t->data < temp->data)
         {
            if(temp->left==NULL)
            {
               temp->left=t;
               tot++;
               cout<<"\ndata:"<<t->data<<"inserted in"<<temp->data<<"left";
               break;    
            }
            else
              temp=temp->left;
         }
         else
         {
            if(temp->right==NULL)
            {
               temp->right=t;
               tot++;
               cout<<"\ndata:"<<t->data<<"inserted in"<<temp->data<<"right";
               break;    
            }
            else
              temp=temp->right;
         }
     }
    }
 }  

void traverse()
{
        node *r=root;
        cout<<"preorder\n";
        preorder(r);
        cout<<"\ninorder\n";
        inorder(r);
        cout<<"\npostorder\n";
        postorder(r);    
}   

void preorder(node *r)
{
  if(r==NULL)
     return;
  cout<<" "<<r->data;
  preorder(r->left);
  preorder(r->right); 
} 

void inorder(node *r)
{
  if(r==NULL)
     return;
  inorder(r->left);
  cout<<" "<<r->data;
  inorder(r->right); 
} 


void postorder(node *r)
{
  if(r==NULL)
     return;
  postorder(r->left);
  postorder(r->right); 
  cout<<" "<<r->data;
} 

void find(int val)
{
 node *temp=root;
 while(temp!=NULL)
 {
   if(val==temp->data)
    {
     cout<<"\nvalue found:"<<temp->data;
      
     break;
    }
   else if(val<temp->data)
   {
     temp=temp->left;
   }
   else if(val>temp->data)
   {
     temp=temp->right;
   }
 cout<<"\nvalue not found"; //this is showing how many time the value was searched;
 }
 
}

void dele(int val)
{
  node *temp=root;
  node *parent=NULL;
  while(temp!=NULL)
  {
   if(val==temp->data)
   {
     break;
   }
   else if(val<temp->data)
   {
      parent=temp;
      temp=temp->left;
   }
   else if(val>temp->data)
   { 
       parent=temp;
       temp=temp->right;
   }
  }

  if(temp->left==NULL && temp->right==NULL)
  {
     int val;
     val=temp->data;
     if(parent->data>val)
       parent->left=NULL;
     if(parent->data<val)
       parent->right=NULL;
     delete temp;
     cout<<"deleted val"<<val<<endl;
  } 
  else
  { 
     cout<<"\nno function is present right now for the single child or root node"<<endl;
  }
}



};

int main()
{
bst b;
b.insert(100);
b.insert(75);
b.insert(200);
b.insert(80);
b.insert(150);
b.insert(250);
cout<<"\ninsert completed\n";
b.traverse();  
b.find(80);
b.dele(250);
b.traverse();
return 0;
}









