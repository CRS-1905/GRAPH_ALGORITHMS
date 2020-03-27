#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int *u;
double *dist;
struct node
{
	int data;
	struct node *next;
};

struct node **a,*s;

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

void BFS(int n)
{
	int j,r,k;
	struct node *q;
	while(s!=NULL)
	{
		k=pop();
		q=a[k];
		while(q!=NULL)
		{
			j=q->data;	
			if(dist[j]==INFINITY)
			{
				push(j);
				dist[j]=dist[k]+1;
				u[j]=k;
			}
			q=q->next;
		}	
	}
	
}

int main()
{
	int i,n,m,j,k,r;
	struct node *q;
	printf("ENTER THE NUMBER OF NODES :\t");
	scanf("%d",&n);
	printf("Enter the starting node :\t");
	scanf("%d",&k);
	a=(struct node **)malloc(n*sizeof(struct node *));
	for(i=0;i<n;i++)
		a[i]=NULL;
	printf("ENTER THE GRAPH :\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the number of edges connected with %d\t",i);
		scanf("%d",&m);
		printf("ENTER THE EDGES :\t");
		for(j=0;j<m;j++)
		{
			scanf("%d",&r);
			insert(i,r);
		}
	}
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}*/
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
	s=NULL;
	dist=(double *)malloc(n*sizeof(double));
	u=(int *)malloc(n*sizeof(int));
	dist[k]=0;
	for(i=0;i<k;i++)
		dist[i]=INFINITY;
	for(i=k+1;i<n;i++)
		dist[i]=INFINITY;
	push(k);
	BFS(n);
	printf("the distance from %dto others nodes is given by:\n",k);
	for(i=0;i<n;i++)
		printf("for%d distance:\t%lf\n",i,dist[i]);
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
