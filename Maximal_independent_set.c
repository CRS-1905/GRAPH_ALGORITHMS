#include<stdio.h>
#include<stdlib.h>

int power(int n);
int has_edge(int *new,int k);

int **adj;

int main()
{
	int n,i,m,j,*a,*b,size,k,*new,p;

	printf("Enter The Number Of Points:\t");
	scanf("%d",&n);
	
	adj=(int **)malloc(n*sizeof(int *));
	a=(int *)malloc(n*sizeof(int));
	b=(int *)malloc(n*sizeof(int));
	size=0;
	
	for(i=0;i<n;i++)
	{
		adj[i]=(int *)malloc(n*sizeof(int));
		a[i]=1;
		b[i]=-1;
	}

	printf("Enter The Adjacency Matrix :\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
			
			if(i == j)
				adj[i][j]=0;
		}

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(adj[i][j]!=adj[j][i])
			{
				printf("The Graph is not Undirected\n");
				exit (0);
			}

	m=power(n);
	
	for(i=m-1;i>=1;i--)
	{
		k=1;
		new=(int *)malloc(k*sizeof(int));
	
		for(j=0;j<n;j++)
		{
			if(a[j] == 1)
			{
				new=(int *)realloc(new,k*sizeof(int));				
				new[k-1]=j+1;
				k++;
			}
		}
		
		k=k-1;
		p=has_edge(new,k);
		
		if(p == 1)
		{
			if(k > size)
			{
				size=k;
				for(j=0 ;j<k;j++)
					b[j]=new[j];
			}	
		}
		
		free(new);

		for(j=n-1;j>=0;j--)
		{
			if(a[j] == 0)
				a[j]=1;
			else
			{
				a[j]=0;
				break;
			}
		}
			
	}
	printf("The size of independent set is =%d\n",size);
	printf("The independent set is given by:\n");
	for(i=0;i<size;i++)
		printf("%d\t",b[i]);
	printf("\n");
}

int power(int n)
{
	int s=1;

	for(int j=1;j<=n;j++)
		s=s*2;
	
	return s;
		
}

int has_edge(int *new,int k)
{
	int i,j;

	for(i=0;i<k;i++)
		for(j=i+1;j<k;j++)
			if(adj[new[i]-1][new[j]-1] == 1)
			{
				return 0;
				break;
			}
	return 1;
}
