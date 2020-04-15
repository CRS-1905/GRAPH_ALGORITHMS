#include<stdio.h>
#include<stdlib.h>

struct key
{
	int v;
	struct key *next;
};
typedef struct key node;

int **a,*visit;
node **s,*bag;

void insert(int ,int);
void delete(int,int);
int check_path(int,int,int);
void push(int k);


int main()
{
	int n,i,j,e,e1,p;
	node *q;
	printf("Enter The Number Of Vertices :\t");
	scanf("%d",&n);
	
	a=(int **)malloc(n*sizeof(int *));
	s=(node **)malloc(n*sizeof(node *));
	visit=(int *)malloc(n*sizeof(int));

	for(i=0;i<n;i++)
	{
		a[i]=(int *)malloc(n*sizeof(int));
		visit[i]=0;
		s[i]=NULL;
	}

	printf("Enter The Adjacency Matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j]!=a[j][i])
			{
				printf("This Graph Is Not Undirected\n");
				exit (1);
			}
	
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
			if(a[i][j]==1)
				insert(i,j);

	printf("\n");
	printf("Enter The edge Of which You Want To Check Whether This Edge Is In A Cycle Or Not\t");
	scanf("%d%d",&e,&e1);

	if(a[e][e1]!=1)
	{
		printf("This Is Not Valid Edge\n");
		exit (1);
	}
	else
	{
		delete(e,e1);
		p=check_path(e,e1,n);
		if(p == 1)
			printf("The Edge (%d,%d) is in a Cycle\n",e,e1);
		else
			printf("The Edge (%d,%d) is Not In a Cycle\n",e,e1);
	
	}
}

void insert(int i,int j)
{
	node *new,*new1,*p,*q,*q1;
	
	new=(node *)malloc(sizeof(node));
	new1=(node *)malloc(sizeof(node));
	
	new->v=i;
	new->next=s[j];
	s[j]=new;
	
	new1->v=j;
	new1->next=s[i];
	s[i]=new1;
	
}

void delete(int e,int e1)
{
	node *p,*p1,*q,*q1;
	
	p=s[e];
	q=p->next;
	if(p->v == e1)
		s[e]=p->next;
	else
	{
		while(q->v!=e1)
		{
			p=p->next;
			q=q->next;
		}
		p->next=q->next;
	}

	p1=s[e1];
	q1=p1->next;
	if(p1->v == e)
		s[e1]=p1->next;
	else
	{
		while(q1->v!=e)
		{
			p1=p1->next;
			q1=q1->next;
		}
		p1->next=q1->next;
	}
}

int check_path(int e,int e1,int n)
{
	node *q;
	int k;

	push(e);
	visit[e]=1;
	while(bag!=NULL)
	{
		k=bag->v;
		if(k == e1)
		{
			free(bag);
			return 1;
		}
		else
		{
			q=s[k];
			while( q!=NULL && visit[q->v] == 0)
			{
				push(q->v);
				visit[q->v]=1;
				q=q->next;
			}
		}
		bag=bag->next;	
	}
	free(bag);
	return 0;
}

void push(int e)
{
	node *q,*q1,*new;
	new=(node *)malloc(sizeof(node));
	new->v=e;
	new->next=NULL;
	
	if(bag == NULL)
		bag=new;
	else
	{	
		q=bag;
		while(q->next!=NULL)
			q=q->next;
		q->next=new;
	}
}
