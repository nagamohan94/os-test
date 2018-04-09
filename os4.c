#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#define n 5             /* maximum number of processes  */               
#define m 3            /* maximum number of resource types              */
int ProcCurr[5][3];     /* 3 threads(processes), 3 resources    */
//int temp1[5][3];       /* temp array location           */
int available[10]={3,3,2};        /* Available[m] = # resources unallocated */
int max[5][3] = { {7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3} }; /* Max[n][m] = max demand of processes n for resource m    */
int allocation[5][3] = { {0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2} }; /* Allocation[n][m] = # resources m allocated to processes n*/
int need[5][3];       /* Need[n][m] = resources m needed by processes n         */
int counti = 0;             /* Need[n][m] = Max[n][m] - Allocation[n][m]     */
int countj = 0;
int s,i,j,count,temp[10],w=0,x=0,temp1[10][10],h[10];
//int threadsi = 3;
pthread_mutex_t an;
void display();
void *naga(void *a);
void test();
void check();
int main()
{
int q;
pthread_t p[10];
display();
if(pthread_mutex_init(&an,NULL)<0)
{
printf("something worng try again");

}
else{
printf("enter no of threads requeired :");
scanf("%d",&q);
for(i=0;i<q;i++)
{
pthread_create(&p[i],NULL,naga,(void*)i);
}
}
pthread_mutex_lock(&an);
display();
pthread_mutex_unlock(&an);
for(i=0;i<q;i++)
{
pthread_join(p[i],NULL);
}
}
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
void test()
{
pthread_mutex_lock(&an);
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
pthread_mutex_unlock(&an);
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
void *naga(void *a)
{pthread_mutex_lock(&an);
int q=(int)a;

printf("thread is requseting :%d\n",q);

//printf("enter the process any form 1,2,3 for requset :");
//scanf("%d",&s);
for(i=0;i<m;i++)
{
printf("enter no of instance resources for type r%d :",i+1);
scanf("%d",&temp1[q][i]);
}
check();
pthread_mutex_unlock(&an);
//sleep(1);
if(x=0)
{
printf("process are safe so requset granted :");
}
else{
for(i=0;i<m;i++)
{
available[i]+=temp1[q][i];
allocation[q][i]-=temp1[q][i];
need[q][i]+=temp1[q][i];
}


}
//pthread_mutex_unlock(&an);
} 

