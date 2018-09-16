#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
void *add(void *arg[])
{
  int a,b,c=0;
  a=(int*)arg[0];
  printf("%d\n",a);
  b=(int*)(arg+4);
  printf("%d\n",b);
  c=a+b;
  printf("%d\n",c);
}



int main()
{
pthread_t t;
int a[]={10,12};
pthread_create(&t,NULL,add,a);
pthread_join(t,NULL); 
return 0;
}
