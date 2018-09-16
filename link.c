#include<stdio.h>
#include<malloc.h>

struct node{
int data;
struct node *nptr;
};

void main()
{
struct node *start=NULL,*t,*p;
int n=100;
while(n!=0)
{
printf("enter the no");
scanf("%d",&n);
t=(struct node*)malloc(sizeof(struct node*));
if(start==NULL)
{
 t->data=n;
 t->nptr=NULL;
 start=t;
}
else{
p=start;
while(p->nptr!=NULL)
{
 p=p->nptr;
}
t->data=n;
t->nptr=NULL;
p->nptr=t;
}
}
for(p=start;p!=NULL;p=p->nptr)
{
  printf("%d",p->data);
}
}
