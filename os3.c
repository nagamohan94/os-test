#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/types.h>
int allocation[10][10],max[10][10],need[10][10],available[10],temp[10],h[10];
int s,i,j,n,m,count,w=0,x=0,temp1[10][10];
void *naga(void *r);
void test();
pthread_mutex_t an;
int res_allocation()
{
//int n,m;
printf("enter the noof process :");
scanf("%d",&n);
printf("enter the no of type of resources :");
scanf("%d",&m);
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
printf("enter alocation of resource %d to process %d :",j,i);
scanf("%d",&allocation[i][j]);
printf("enter the max  to process %d  of resources  %d :",j,i);
scanf("%d",&max[i][j]);
need[i][j]=max[i][j]-allocation[i][j];
}
//printf("enter the available resources of Type R%d",j-1);
//scanf("%d",&available[j-1]);
}
for(i=0;i<m;i++)
{
printf("enter the available resources of type R%d",i+1);
scanf("%d",&available[i]);

}}
void display()
{printf("proces  allocaton     max       need \n ");
for(i=0;i<3;i++)
{printf("\t");
for(j=0;j<m;j++)
{
printf(" r%d ",j+1);
}
}
printf("\n");
for(i=0;i<n;i++)
{printf("p%d\t",i+1);
for(j=0;j<m;j++)
{
printf("%d ",allocation[i][j]);
}
printf("\t");
for(j=0;j<m;j++)
{
printf("%d ",max[i][j]);
}
printf("\t");
for(j=0;j<m;j++)
{
need[i][j]=max[i][j]-allocation[i][j];
printf("%d ",need[i][j]);
}

printf("\n");
}

}

void check()
{
pthread_mutex_lock(&an);
for(i=0;i<m;i++)
{
if(temp1[s][i]<=need[s][i])
{
if(temp1[s][i]<=available[i])
{available[i]-=temp1[s][i];
allocation[s][i]+=temp1[s][i];
need[s][i]-=temp1[s][i];
}
else
{
printf("resources are not available for grant resources :");
break;
}
}

else
{
printf("error due to   max claim");
}
}
test();
pthread_mutex_unlock(&an);
}

void test()
{
x=0;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{ count=0;
for(int k=0;k<m;k++)
{
if(temp[j]==0&&need[j][k]<=available[k])
{
available[k]+=allocation[j][k];
count++;
if(count==m)
{
temp[j]=1;
printf("allocation  of resources to process %d has done\n",j);
h[w]=j;
w++;

}
continue;
}
break;
}
}
}
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


int main()
{pthread_t p[10];
int a;
res_allocation();
display();
test();
printf("enter no of threads need the request :");
scanf("%d",&a);
pthread_mutex_init(&an,NULL);
for(i=0;i<a;i++)
{
pthread_create(&p[i],NULL,naga,(void*)i);
}

for(i=0;i<a;i++)
{
pthread_join(p[i],NULL);
}
}

void *naga(void *a)
{int q=(int)a;
printf("thread is requseting\n",q);
pthread_mutex_lock(&an);
printf("enter the process any form 1,2,3 for requset :");
scanf("%d",&s);
for(i=0;i<m;i++)
{
printf("enter no of instance resources for type r%d :",i+1);
scanf("%d",&temp1[i][j]);
}
check();
//sleep(1);
if(x=0)
{
printf("process are safe so requset granted :");
}
else{
for(i=0;i<m;i++)
{
available[i]+=temp1[s][i];
allocation[s][i]-=temp1[s][i];
need[s][i]+=temp1[s][i];
}


}
pthread_mutex_unlock(&an);
} 
