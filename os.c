#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int  i,n,m,j,allocation[10][10],need[10][10],max[10][10],available[10];
int temp[10],h[10],count=0,x=0,w=0;
sem_t q[10];
void * naga(void *r);
void *nag1(void *r1);
void *nag2(void *r2);
int main()
{int re;
int a[10]={1,2,3}; 
printf("enter no of threads :");
scanf("%d",&n);
pthread_t p[10];
printf("Enter the no of type of resources");
scanf("%d",&m);
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
printf("enter the allocation of process %d of resources %d",i,j);
scanf("%d",&allocation[i][j]);
printf("Enter the max of process %d of resources %d",i,j);
scanf("%d",&max[i][j]);
}
}
for(i=0;i<m;i++)
{
printf("enter the available of resources %d\n",i);
scanf("%d",&available[i]);
}
for(i=0;i<n;i++)
{
re=sem_init(&q[i],0,0);
}
if (re==-1)
{
perror("semphore initalization falied");
//exit(1);
}
else
{
//for(i=0;i<n;i++)
//{
pthread_create(&p[0],NULL,naga,&a[0]);
pthread_create(&p[1],NULL,nag1,&a[1]);
pthread_create(&p[2],NULL,nag2,&a[2]);//}
}
for(i=0;i<n;i++)
{
pthread_join(p[i],NULL);
}
}

void *naga(void *r)
{
int i,j;
long my_id=(long)r;
printf("process   allocation            max       need\n");
printf("        r1   r3   r3      r1  r2   r3   r1    r2   r3\n");
for(i=0;i<n;i++)
{printf("p%d\t",i+1);
for(j=0;j<m;j++)
{
printf("%d   ",allocation[i][j]);
}

for(j=0;j<m;j++)
{
printf("%d   ",max[i][j]);
}
for(j=0;j<m;j++)
{
need[i][j]=max[i][j]-allocation[i][j];
printf("%d   ",need[i][j]);
}

printf("\n");
}
}

void *nag1(void *r1)
{
long q=(long)r1;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{int count=0;
for(int k=0;k<m;k++)
{
if(temp[j]==0&&need[j][k]<=available[k])
{
available[k]=available[k]+allocation[k];
count++;
if(count==3)
{
temp[j]=1;
printf("allocation  of resources to process %d has done\n",j);
h[w]=j;
w++;
}
}
break;
}
}
}
}
void *nag2(void *r3)
{
long q=(long)r3;
for(i=0;i<n;i++)
{
if(temp[i]==0)
{
printf("system is unsafe state\n");
x=1;
break;
}
}
if(x==0)
{
printf("\n     SAFE STATE\n");
for(i=0;i<n;i++)
{
printf("p[%d]->",h[i]);
}
}
printf("\n");
}

