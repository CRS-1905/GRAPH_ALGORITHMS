#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
	int a;
	int b;
	struct node *next;
};
typedef struct node edge;
edge *s;
int **a,n,*visit;

struct node1
{
	int data;
	struct node1 *next;
};
typedef struct node1 stack;
stack *r;

void insert(int i,int j)
{
	edge *new;
	new=(edge *)malloc(sizeof(edge));
	new->a=i;
	new->b=j;
	new->next=NULL;
	if(s==NULL)
		s=new;
	else
	{
		new->next=s;
		s=new;
	}
}

void push(int j)
{
	stack *new,*q;
	new=(stack *)malloc(sizeof(stack));
	new->data=j;
	new->next=NULL;
	if(r==NULL)
		r=new;
	else
	{
		q=r;
		while(q->next!=NULL)
			q=q->next;
		q->next=new;
	}
}
void delete(int k,int j)
{
	edge *q1,*q;
	q=s;
	q1=q->next;
	if(q->a==k && q->b==j)
		s=s->next;
	else
	{
		while(q1->a!=k || q1->b!=j)
		{
			q=q->next;
			q1=q1->next;
		}
		q->next=q1->next;
	}
}

int pop()
{
	int k;
	k=r->data;
	r=r->next;
	return k;
}

void BST()
{
	int k,j;
	while(r!=NULL)
	{
		k=pop();
		visit[k]=2;
		for(j=0;j<n;j++)
		{
			if(a[k][j]==1 && visit[j]==0)
			{
				push(j);
				visit[j]=1;
				delete(k,j);
				delete(j,k);
			}
		}
	}
}

int main()
{
	int i,j,k,s1;
	double **w;
	edge *q;
	printf("Enter The Number Of Vertices :\t");
	scanf("%d",&n);
	a=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		a[i]=(int *)malloc(n*sizeof(int));
	visit=(int *)malloc(n*sizeof(int));
	printf("Enter The Adjacency Matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	s=NULL;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j]==1)	
				insert(i,j);
	for(i=0;i<n;i++)
		visit[i]=0;
	k=0;
	s1=1;
	while(s1!=0)
	{
		s1=0;
		push(k);
		visit[0]=1;
		BST();
		for(j=0;j<n;j++)
		{
			if(visit[j]!=2)
			{
				k=j;
				s1=1;
				break;
			}	
		}
	}
	if(s!=NULL)
		printf("The Graph Contains A Cycle \n");
	else
		printf("The Graph Does Not Contain Any Cycle \n");
}
