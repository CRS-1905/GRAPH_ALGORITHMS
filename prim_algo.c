#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct key
{
	int v;
	double W;
	struct key *next;
};
typedef struct key node;

typedef struct
{
	int s;
	int t;
	double W;
}edge;

struct key1
{
	int data;
	struct key1 *next;
};

int **a,**a1,e,*visit;
double **w,**w1;
node **s,**t;
struct key1 *box;

void insert(int i,int j,int n);
void push_box(int i);
void add(edge );
edge min(edge *bag,int n);

int main()
{
	int n,i,j,source,k1,k;
	node *q;
	struct key1 *q1;
	edge m;
	double sum;

	printf("Enter The Number Of Nodes :\t");
	scanf("%d",&n);

	a=(int **)malloc(n*sizeof(int *));
	a1=(int **)malloc(n*sizeof(int *));
	w=(double **)malloc(n*sizeof(int *));
	w1=(double **)malloc(n*sizeof(int *));
	s=(node **)malloc(n*sizeof(node *));
	t=(node **)malloc(n*sizeof(node *));
	visit=(int *)malloc(n*sizeof(int));

	for(i=0;i<n;i++)
	{
		a[i]=(int *)malloc(n*sizeof(int));
		a1[i]=(int *)malloc(n*sizeof(int));
		w[i]=(double *)malloc(n*sizeof(double));
		w1[i]=(double *)malloc(n*sizeof(double));
		s[i]=NULL;
		t[i]=NULL;
		visit[i]=0;
	}

	printf("Enter The Adjacency Matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(i == j)
				a[i][j]=0;
		}

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j]!=a[j][i])
			{
				printf("The graph Is Not Undirected\n");
				exit (1);
			}
	
	printf("Enter The Weights:\n");
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
			if(a[i][j] == 1)
			{
				printf("Enter The Weight Of (%d,%d)\t",i,j);
				scanf("%lf",&w[i][j]);
				w[j][i]=w[i][j];
				insert(i,j,n);
				e++;
			}
			else
				w[i][j]=w[j][i]=INFINITY;
	
	printf("Enter A Source Node :\t");
	scanf("%d",&source);
	
	box=NULL;
	push_box(source);
	for(i=0;i<n;i++)
	{
		q1=box;
		edge *bag;
		bag=(edge *)malloc(sizeof(edge));
		k1=1;
		while(q1!=NULL)
		{
			k=q1->data;
			q=s[k];
			while(q!=NULL)
			{
				if(visit[q->v] == 0)
				{
					bag=(edge *)realloc(bag,k1*sizeof(edge));
					bag[k1-1].s=k;
					bag[k1-1].t=q->v;
					bag[k1-1].W=q->W;
					k1++;
				}
				q=q->next;
			}
			q1=q1->next;
		}
		m=min(bag,k1-1);
		visit[m.t]=1;
		push_box(m.t);
		add(m);
		free(bag);
	}

	printf("The Adjacency Matrix Of The Tree\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d",a1[i][j]);
		printf("\n");
	}
	printf("\n");
	
	printf("The Weights are given below:\n");
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
			if(a1[i][j] == 1)
			{
				printf("The Weights Of (%d,%d) is %lf\n",i,j,w1[i][j]);	
				sum=sum+w1[i][j];
			}
	printf("Total Weight Is %lf\n",sum);
}

void insert(int i,int j,int n)
{
	node *p,*q;
	p=(node *)malloc(sizeof(node));
	q=(node *)malloc(sizeof(node));

	p->v=i;
	p->W=w[i][j];
	p->next=s[j];
	s[j]=p;
	
	q->v=j;
	q->W=w[i][j];
	q->next=s[i];
	s[i]=q;
}

void push_box(int i)
{
	struct key1 *new;
	new=(struct key1 *)malloc(sizeof(struct key1));
	new->data=i;
	new->next=box;
	box=new;
}

edge min(edge *bag,int n)
{
	int i,smallest,l,r;
	edge p;

	for(i=(n/2) -1 ;i>=0;i--)
		{
			smallest=i;
			l=2*i+1;
			r=2*i+2;
			if(l<n && bag[smallest].W > bag[l].W)
				smallest=l;
			if(r<n && bag[smallest].W > bag[r].W)
				smallest=r;
			if(smallest!=i)
			{
				p=bag[smallest];
				bag[smallest]=bag[i];
				bag[i]=p;
			}
		}
	return bag[0];
}

void add(edge m)
{
	node *p,*q;
	p=(node *)malloc(sizeof(node));
	q=(node *)malloc(sizeof(node));

	a1[m.s][m.t]=a1[m.t][m.s]=1;
	w1[m.s][m.t]=w1[m.t][m.s]=m.W;
	
	p->v=m.s;
	p->W=m.W;
	p->next=t[m.t];
	t[m.t]=p;

	q->v=m.t;
	q->W=m.W;
	q->next=t[m.s];
	t[m.s]=q;
}
