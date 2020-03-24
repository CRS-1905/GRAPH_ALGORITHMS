#include<stdio.h>
#include<stdlib.h>

int r=1,current_time,*s_time,*e_time,**a,*visit,*step,s=0;

int DFS(int k,int n)
{
	int j,s1;
	s_time[k]=current_time;
	current_time++;
	visit[k]=1;
	s1=1;
	for(j=0;j<n;j++)
	{
		if(a[k][j]==1)
		{
			if(visit[j]==0 && s1==1)
			{
				current_time=DFS(j,n);
				current_time++;
				s1=0;
			}

			if(visit[j]==0 && s1==0)
			{
				current_time++;
				current_time=DFS(j,n);
				current_time++;
			//s1=0;
			}
		}
	}
	e_time[k]=current_time;
	visit[k]=2;
	step[k]=r;
	return current_time;
}

int main()
{
	int i,n,k,j,p;
	printf("ENTER THE NUMBER OF NODES :\t");
	scanf("%d",&n);
	a=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		a[i]=(int *)malloc(n*sizeof(int));
	printf("ENTER THE GRAPH :\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	printf("ENTER THE NODE :\t");
	scanf("%d",&k);
	current_time=0;
	s_time=(int *)malloc(n*sizeof(int));
	e_time=(int *)malloc(n*sizeof(int));
	visit=(int *)malloc(n*sizeof(int));
	step=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		visit[i]=0;
	j=n;
	while(j>0)
	{
		p=DFS(k,n);
		printf("%d\n",current_time);
		printf("\nthe connected component is given by :\n");
		for(i=0;i<n;i++)
		{
			if(visit[i]==2 && step[i]==r)
			{
				printf("%d\t",i);
				printf("for the node %d\t:\t the starting value is\t%d\tthe finishing time is \t%d\n",i,s_time[i],e_time[i]);
				s++;
			}
			if(visit[i]==0)
			k=i;
		}
		printf("\n");
		r++;
		current_time++;
		j=n-s;
	}
	printf("\n");
}

	
	
	
