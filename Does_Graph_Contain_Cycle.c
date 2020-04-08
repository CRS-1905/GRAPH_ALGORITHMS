#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
};
struct node **s,*s1;
int *visit,*p;

void insert(int i,int j)
{
	struct node *new,*q;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=j;
	new->next=NULL;
	if(s[i]==NULL)
		s[i]=new;
	else
	{
		new->next=s[i];
		s[i]=new;
	}
}

void push(int i)
{
	struct node *new,*q;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=i;
	new->next=NULL;
	if(s1==NULL)
		s1=new;
	else
	{
		q=s1;
		while(q->next=NULL)
			q=q->next;
		q->next=new;
	}
}

int pop()
{
	int p=s1->data;
	s1=s1->next;
	return p;
}

int BFS()
{
	int k,r,e;
	struct node *q;
	while(s1!=NULL)
	{
		k=pop();
		visit[k]=1;
		q=s[k];
		while(q!=NULL)
		{
			r=q->data;
			if(visit[r]==0)
			{
				push(r);
				p[r]=k;
				visit[r]=1;
			}
			else
				if(visit[r]==2 && p[k]!=r)
				{
					e=0;
					return e;
				}
				else
					q=q->next;
		}
		visit[k]=2;
	}
	return 1;
	
}
int main()
{
	int n,**a,i,j,t,k,p1;
	struct node *q;
	printf("Enter The NNumber Of Nodes :\t");
	scanf("%d",&n);
	printf("Enter The Adjacency Matrix :\n");
	a=(int **)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		a[i]=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	s=(struct node **)malloc(n*sizeof(struct node *));
	for(i=0;i<n;i++)
		s[i]=NULL;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j]==1)
				insert(i,j);

	visit=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		visit[i]=0;
	p=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		p[i]=-1;
	for(i=0;i<n;i++)
	{
		push(i);
		p1=BFS();
		if(p1==0)
			break;
		else
		{
			for(j=0;j<n;j++)
				visit[j]=0;
		}
	}
	if(i==n)
		printf("The Graph Does Not Contain Any Cycle\n");
	else
		printf("The Graph Contain A Cycle\n");
}
