#include<stdio.h>
#include<stdlib.h>

int *u,**a,*dist;
struct node
{
	int data;
	struct node *next;
};

struct node *s;

void push(int j)
{
	struct node *new,*q;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=j;
	new->next=NULL;
	if(s==NULL)
		s=new;
	else
	{
		q=s;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=new;
	}
}

int pop()
{
	int p=s->data;
	s=s->next;
	return p;
}

void BFS(int k,int n)
{
	int j,r;
	for(j=0;j<n;j++)
	{
		if(a[k][j]==1)
		{	
			if(dist[j]==999)
			{
				push(j);
				dist[j]=dist[k]+1;
				u[j]=k;
			}
		}	
	}
	if(s!=NULL)
	{
		r=pop();
		BFS(r,n);
	}
}

int main()
{
	int i,n,m,j,k;
	printf("ENTER THE NUMBER OF NODES :\t");
	scanf("%d",&n);
	printf("Enter the starting node :\t");
	scanf("%d",&k);
	a=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		a[i]=(int *)malloc(n*sizeof(int));
	printf("ENTER THE GRAPH :\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	s=NULL;
	dist=(int *)malloc(n*sizeof(int));
	u=(int *)malloc(n*sizeof(int));
	dist[k]=0;
	for(i=0;i<k;i++)
		dist[i]=999;
	for(i=k+1;i<n;i++)
		dist[i]=999;
	BFS(k,n);
	printf("the distance from %dto others nodes is given by:\n",k);
	for(i=0;i<n;i++)
		printf("for%d distance:\t%d\n",i,dist[i]);
	printf("\n");
	printf("ENTER THE NODE:\t");
	scanf("%d",&m);
	printf("%d\t",m);
	while(u[m]!=k)
	{
		printf("%d\t",u[m]);
		m=u[m];
	}
	printf("%d\n",k);
}
