#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct key
{
	int v;
	double W;
	struct key *next;
};
typedef struct key vertex;

struct key1
{
	int s,t;
	double W;
};
typedef struct key1 edge;

struct key2
{
	int data;
	struct key2 *next;
};


int **a,**a1,e,*visit;
double **w,**w1;
vertex **t;
edge *box;
struct key2 *bag;

void min();
void swap(int ,int);
int check_path(int e,int e1,int n);
void push(int e);
void add(int i,int j,double wt);

int main()
{
	int n,i,j,k,count,k2;
	double sum_Weight;
	edge m;
	int p;
	vertex *q2;

	printf("Enter The Number Of Vertices :\t");
	scanf("%d",&n);

	a=(int **)malloc(n*sizeof(int *));
	a1=(int **)malloc(n*sizeof(int *));
	w=(double **)malloc(n*sizeof(double *));
	w1=(double **)malloc(n*sizeof(double *));
	t=(vertex **)malloc(n*sizeof(vertex *));
	visit=(int *)malloc(n*sizeof(int));

	for(i=0;i<n;i++)
	{
		a[i]=(int *)malloc(n*sizeof(int));
		a1[i]=(int *)malloc(n*sizeof(int));
		w[i]=(double *)malloc(n*sizeof(double));
		w1[i]=(double *)malloc(n*sizeof(double));
		t[i]=NULL;
		visit[i]=0;
	}
	
	printf("Enter The Adjacency Matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a1[i][j]=0;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j]!=a[j][i])
			{	
				printf("This Graph Is Not Undirected\n");
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
				e++;
			}
			else
				w[i][j]=w[j][i]=INFINITY;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			w1[i][j]=INFINITY;

	box=(edge *)malloc(e*sizeof(edge));
	k=0;
	while(k<e)
	{
		for(i=0;i<n;i++)
			for(j=0;j<i;j++)
				if(a[i][j] == 1)
				{
					box[k].s=i;
					box[k].t=j;
					box[k].W=w[i][j];
					k++;
				}
	}

	count=0;
	min();	
	k2=0;
	
	for(i=0;i<e;i++)
	{
		p=check_path(box[i].s,box[i].t,n);
		if(p == 0)
			add(box[i].s,box[i].t,box[i].W);
		for(j=0;j<n;j++)
				visit[j]=0;	
	}
	
	for(i=0;i<n;i++)
	{
		q2=t[i];
		while(q2!=NULL)
		{
			a1[i][q2->v]=1;
			w1[i][q2->v]=q2->W;
			sum_Weight=sum_Weight+q2->W;
			q2=q2->next;
		}
	}
	printf("The Adjacency Matrix Of The Tree Is :\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d",a1[i][j]);
		printf("\n");
	}
	printf("\n");
	printf("The Weights Are\n");
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
			if(a1[i][j] == 1)
				printf("The Weight Of (%d,%d) is %lf\n",i,j,w1[i][j]);
	printf("The total Weight Is %lf\n",(sum_Weight)/2);
}

void min()
{
	int n,j,i,largest,t1,k,l,r;
	n=e;
	for(k=0;k<n/2;k++)
		for(i=(n/2) -1 ;i>=k;i--)
		{
			largest=i;
			l=2*i+1;
			r=2*i+2;
			if(l<n && box[largest].W < box[l].W)
				largest=l;
			if(r<n && box[largest].W < box[r].W)
				largest=r;
			if(largest!=i)
				swap(largest,i);
		}

	for(j=n-1;j>0;j--)
	{
		swap(j,0);
		t1=0;
		while(t1<j)
		{
			l=2*t1+1;
			if(l<j-1 && box[l+1].W > box[l].W)
				l++;
			if(l<j && box[l].W > box[t1].W)
				swap(l,t1);
			t1=l;
		}
	}
}

void swap(int i,int j)
{
	edge p;
	p=box[i];
	box[i]=box[j];
	box[j]=p;
}

int check_path(int e2,int e1,int n)
{
	vertex *q;
	int k;
	bag=NULL;
	push(e2);
	visit[e2]=1;
	while(bag!=NULL)
	{
		k=bag->data;
		bag=bag->next;
	
		q=t[k];
		while( q!=NULL) 
		{
			 if(visit[q->v] == 0)
			{
				if(q->v != e1)
				{
					push(q->v);
					visit[q->v]=1;
					q=q->next;
				}
				else
				{
					bag=NULL;
					return 1;
				}
			}
			else
				q=q->next;
			
		}
		
			
	}
	return 0;
}

void push(int e)
{
	struct key2 *q,*q1,*new;
	new=(struct key2 *)malloc(sizeof(struct key2));
	new->data=e;
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

void add(int i,int j,double wt)
{
	vertex *new,*new1,*p,*q,*q1;
	
	new=(vertex *)malloc(sizeof(vertex));
	new1=(vertex *)malloc(sizeof(vertex));
	
	new->v=i;
	new->W=wt;
	new->next=t[j];
	t[j]=new;
	
	new1->v=j;
	new1->W=wt;
	new1->next=t[i];
	t[i]=new1;
	
}
