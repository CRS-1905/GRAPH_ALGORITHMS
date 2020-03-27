#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
	int p; 
	double d;
}edge;

typedef struct
{
	int r;
	edge *ver;
}node;

int **a,n,Q_size;
double **w; 
edge *v;
node *q;

void INITIALIZE(int s)
{
	v=(edge *)malloc(n*sizeof(edge));
	for(int i=0;i<n;i++)
	{
		v[i].p=-1;
		v[i].d=INFINITY;
	}	
	v[s].d=0;
}

void swap(int i,int j)
{
	int p;
	edge *s;
	p=q[i].r;
	q[i].r=q[j].r;
	q[j].r=p;
	
	s=q[i].ver;
	q[i].ver=q[j].ver;
	q[j].ver=s;
}

void creat_min_heap()
{
	int i,k,l,j;
	q=(node *)malloc(n*sizeof(node));
	for(i=0;i<n;i++)
	{
		q[i].r=i;
		q[i].ver=&v[i];
	}
	for(i=n/2;i>=0;i--)
	{
		k=i;
		l=2*i+1;
		j=2*i+2;
		if(l<n && q[l].ver->d<q[k].ver->d)
			k=l;
		if(j<n && q[j].ver->d<q[k].ver->d)
			k=j;
		if(k!=i)
			swap(k,i);
	}	
}

int extract_min()
{
	int i,k,l,j;
	swap(0,Q_size-1);
	Q_size--;
	for(i=0;i<Q_size;)
	{
		k=i;
		l=2*i+1;
		j=l+1;
		if(l<Q_size && q[k].ver->d > q[l].ver->d)
			k=l;
		if(j<Q_size && q[k].ver->d > q[j].ver->d)
			k=j;
		if(k!=i)
		{
			swap(k,i);
			i=k;
		}
		else
			break;
	}
	return (q[Q_size].r);
}

void relax(int i,int j)
{
	int k=v[i].d+w[i][j];
	if(v[j].d>k)
	{
		v[j].d=v[i].d+w[i][j];
		v[j].p=i;
	}
}

void DIJKSTRA(int s)
{
	int i,j;
	INITIALIZE(s);
	creat_min_heap();
	Q_size=n;
	while(Q_size!=0)
	{
		i=extract_min();
		for(j=0;j<n;j++)
		{
			if(a[i][j]==1)
				relax(i,j);
		}
	}
}

void dist(int s1)
{
	
	int i=v[s1].p;
	printf("%d\t",s1);
	while(i!=-1)
	{
		printf("%d\t",i);
		i=v[i].p;
	}
}

int main()
{
	int i,j,s,s1;
	printf("ENTER THE NUMBER OF NODES :\t");
	scanf("%d",&n);
	a=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		a[i]=(int *)malloc(n*sizeof(int));
	printf("ENTER THE ADJACENCY MATRIX :\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	w=(double **)malloc(n*sizeof(double *));
	for(i=0;i<n;i++)
		w[i]=(double *)malloc(n*sizeof(double));
	printf("ENTER THE WEIGHTS :\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==1)
			{
				printf("ENTER THE EDGE FROM %d to %d\t",i,j);
				scanf("%lf",&w[i][j]);
				if(w[i][j]<0)
				{
					printf("Negative edges are not allowed \n");
					return 0;
				}
			}

			else
				w[i][j]=INFINITY;
		}
	}
	printf("ENTER THE SOURCE NODE :\t");
	scanf("%d",&s);
	DIJKSTRA(s);
	for(i=0;i<n;i++)
	{
		printf("the distance from %d to %d is \t%lf\n",s,i,v[i].d);
	}
	printf("\n");
	printf("ENTER A NODE :\t");
	scanf("%d",&s1);
		dist(s1);
}
