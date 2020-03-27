#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};


int r=1,current_time,*s_time,*e_time,*visit,*step,s=0;
struct node **a;

void insert(int i,int k)
{
	struct node *new,*q;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=k;
	new->next=NULL;
	if(a[i]==NULL)
		a[i]=new;
	else
	{
		q=a[i];
		a[i]=new;
		new->next=q;
	}
}


int DFS(int k,int current_time)
{
	int i,j,s1;
	struct node *q;
	s_time[k]=current_time;
	current_time++;
	visit[k]=1;
	s1=1;
	q=a[k];
	while(q!=NULL)
	{
		j=q->data;
		if(visit[j]==0 && s1==1)
		{
			current_time=DFS(j,current_time);
			current_time++;
			s1=0;
		}
			
		if(visit[j]==0 && s1==0)
		{
			current_time++;
			current_time=DFS(j,current_time);
			current_time++;
		}
		q=q->next;
	}
	e_time[k]=current_time;
	visit[k]=2;
	step[k]=r;
	return current_time;
}

int main()
{
	int i,n,k,j,p,m,e;
	struct node *q;
	printf("ENTER THE NUMBER OF NODES :\t");
	scanf("%d",&n);
	a=(struct node **)malloc(n*sizeof(struct node *));
	for(i=0;i<n;i++)
		a[i]=NULL;
	printf("ENTER THE GRAPH :\n");
	for(i=0;i<n;i++)
	{
		printf("ENTER THE NUMBER OF EDGERS OF THE NODE %d\t",i);
		scanf("%d",&m);
		for(j=0;j<m;j++)
		{
			scanf("%d",&e);
			insert(i,e);
		}
	}
	printf("ENTER THE NODE :\t");
	scanf("%d",&k);
	for(i=0;i<n;i++)
	{
		q=a[i];
		while(q!=NULL)
		{
			printf("%d\t",q->data);
			q=q->next;
		}
		printf("\n");
	}
	printf("\n");
	current_time=0;
	s_time=(int *)malloc(n*sizeof(int));
	e_time=(int *)malloc(n*sizeof(int));
	visit=(int *)malloc(n*sizeof(int));
	step=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		visit[i]=0;
	printf("\nthe connected component is given by :\n");	
	j=n;
	while(j>0)
	{
		p=DFS(k,current_time);
		printf("%d\n",p);
		for(i=0;i<n;i++)
		{
			if(visit[i]==2 && step[i]==r)
			{
				printf("%d\t",i);
				printf("for the node %d\t:\t the starting value is\t%d\tthe finishing time is \t%d\n",i,s_time[i],e_time[i]);
				s++;
			}
			if(visit[i]==0)
				k=i;
		}
		printf("\n");
		r++;
		p++;
		j=n-s;
		current_time=p;
	}
	printf("\n");
}
