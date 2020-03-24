#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int **a,*P;
double **d,*dist;
void initialize(int n,int s)
{
	int i;
	for(i=0;i<n;i++)
		dist[i]=INFINITY;
	dist[s]=0;
}

void relax(int i,int j)
{
	if(dist[j]>dist[i]+d[i][j])
	{
		dist[j]=dist[i]+d[i][j];
		P[j]=i;
	}
}

int BELLMAN_FORD(int n,int s)
{
	int i,j,p;
	initialize(n,s);
	for(p=1;p<n;p++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]!=0)	
					relax(i,j);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]!=0 && dist[j]>dist[i]+d[i][j])	
				break;
		}
		//printf("%d\n",j);	
		if(j!=n)
			break;
	}
	if(i==n && j==n)
		return 1;
	else
		return 0;		
}

int main()
{
	int n,p,i,j,s;
	printf("ENTER THE NUMBER OF NODES :\t");
	scanf("%d",&n);
	a=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		a[i]=(int *)malloc(n*sizeof(int));
	d=(double **)malloc(n*sizeof(double *));
	for(i=0;i<n;i++)
		d[i]=(double *)malloc(n*sizeof(double));
	P=(int *)malloc(n*sizeof(int));
	printf("ENTER THE ADJACENCY MATRIX :\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==0)
				d[i][j]=INFINITY;
			else
			{
				printf("ENTER THE WEIGHT OF CORRESPONDING EDGE OF %d and %d\t",i,j);
				scanf("%lf",&d[i][j]);
			}
		}
	}
	dist=(double *)malloc(n*sizeof(double));
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	printf("\n");
	printf("ENTER THE SOURCE NODE :\t");
	scanf("%d",&s);
	p=BELLMAN_FORD(n,s);
	if(p==0)
		printf("THE GRAPH CONTAIN A NEGATIVE CYCLE \n");
	else
	{
		for(i=0;i<n;i++)
			printf("the cost from %d to %d is %lf\n",s,i,dist[i]);
	}
	printf("\n");
	//printf("\n%d\n",TMP_MAX);
}
