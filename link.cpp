#include<iostream>
using namespace std; 
struct node
{
 int data;
 struct node *next;
};
class list
{
  struct node *first;
  struct node *last;
  int count;
  public:
 
 list()
  {
     first=NULL;
     last=NULL;
     count=0;
  }

  void insert(int ele)
  {
   int s;
   struct node *t;
   t=new struct node;
   t->data=ele;
   t->next=NULL;
  cout<<"\nenter the choice where u want to enter\n1.enter from front\n2.enter from rear"<<endl;
  cin>>s;
  switch(s)
  {
     case 1:
          cout<<"\nelement entered at front"<<endl;
           if(first==NULL)
  	  {
      		first=t;
      		last=t;
      		count++;
          }
          else
          {
            t->next=first;
            first=t;
          }
        break;       
     case 2:
          cout<<"\nelement entered at rear"<<endl;
           if(first==NULL)
  	  {
      		first=t;
      		last=t;
      		count++;
   	  } 
  	  else
  	 {
       		last->next=t;
       		last=t;
       		count++;
  	}
        break;
  } 
 }

  void show()
  {
   struct node *p;
   p=first;
   cout<<"elements of list:"<<endl;
   if(first==NULL || count==0)
     cout<<"\n no element are there in list"<<endl;
   /*else if(first==last && count==1)
     cout<<" "<<first->data;*/
   else
    {
      while(p!=NULL && count!=0)
      {
       cout<<" "<<p->data;
       p=p->next;
      }
    } 
  }

 void del()
 {
  int s;
  struct node *temp,*temp1;
  if(first==NULL)
    cout<<"\nlist empty";
  else
 {
    cout<<"\n enter choice\n1.delete from front\n2.delete from end"<<endl;
    cin>>s;
    switch(s)
    {
      case 1:
            cout<<"\ndelete from start"<<endl;
            if(first==NULL)
               cout<<"delete not possible list empty";
            else
            {    
            temp=first;
            first=temp->next;
            count--;
            delete temp;
            }
            break;    
      case 2:
            cout<<"\ndelete from end"<<endl;
            if(first==NULL)
               cout<<"delete not possible list empty";
            else{
            temp=first;
            temp1=last;
            while(temp->next!=NULL)
             {
             if(temp->next==last)
               break;
              else  
               temp=temp->next;
             } 
             temp->next=NULL;
             last=temp;
             count--; 
             delete temp1;
             }
            break;
    } 
  }
   if(count==0)
   {  
    first=NULL;
    last=NULL; 
   } 
 }
  
 void rev()
 {

 }

};

int main()
{
int flag=1,s,val;
list l;
while(flag==1)
{
 cout<<"\nenter the choice\n1.insert node\n2.display\n3.delete\n4.exit\n";
 cin>>s;
 switch(s)
 {
 case 1:
     cout<<"enter an element to be inserted";
     cin>>val;
     l.insert(val);
     break;
 case 2:
     l.show();
     break;
 case 3:
     l.del();
     break;
  case 4:
     flag=0;
     break;
 }
}
return 0;
}
