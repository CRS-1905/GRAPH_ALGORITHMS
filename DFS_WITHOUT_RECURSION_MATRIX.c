#include<stdio.h>
#include<stdlib.h>

int **a,*s_time,*f_time,current_time,*visit,*P,*step,r=1;

struct node
{
	int data;
	struct node *next;
};
struct node *s,*v;

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
		s=new;
		new->next=q;
	}
}

void push1(int j)
{
	struct node *new,*q;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=j;
	new->next=NULL;
	if(v==NULL)
		v=new;
	else
	{
		q=v;
		v=new;
		new->next=q;
	}
}

int pop()
{
	int p;
	p=s->data;
	s=s->next;
	return p;
}

int pop1()
{
	int p;
	p=v->data;
	v=v->next;
	return p;	
}

void DFS(int n)
{
	
	int k,s1,i,j,p;
	struct node *q;
	while(s!=NULL)
	{
		//k=pop();
		k=pop();
		if(visit[k]==0)
		{
			s_time[k]=current_time;
			current_time++;
			push1(k);
			visit[k]=1;
			s1=1;
			for(j=0;j<n;j++)
			{
				if(a[k][j]==1 && visit[j]==0)
				{
					push(j);
					s1=0;
//					P[j]=k;
				}
			}
			if(s1==1)
			{
				//pop1();
			//	v=v->next;
				visit[k]=2;
				step[k]=r;
				f_time[k]=current_time;
				current_time++;
				v=v->next;
				q=v;
				while(q!=NULL)
				{
					p=q->data;
					for(j=0;j<n;j++)
					{
						if(a[p][j]==1 && visit[j]==0)
						{
							current_time++;
							break;
						}
					}
					if(j==n)
					{
						q=q->next;
						v=q;
						visit[p]=2;
						step[p]=r;
						f_time[p]=current_time;
						current_time++;
					}
					else
						q=NULL;
				}
			}		
		}
	}
}


int main()
{
	int n,i,j,s2=0,k;
	printf("ENTER THE NUMBER OF NODES :\t");
	scanf("%d",&n);
	a=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		a[i]=(int *)malloc(n*sizeof(int));
	printf("ENTER THE adjacency matrix of the GRAPH\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	s_time=(int *)malloc(n*sizeof(int));
	f_time=(int *)malloc(n*sizeof(int));
	visit=(int *)malloc(n*sizeof(int));
	step=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		step[i]=0;
	for(i=0;i<n;i++)
		visit[i]=0;
	current_time=0;
	s=NULL;
	printf("ENTER A STARTING NODE :\t");
	scanf("%d",&k);
	j=n;
	while(j>0)
	{
		push(k);
		DFS(n);
		for(i=0;i<n;i++)
		{
			if(visit[i]==2 && step[i]==r)
			{
				printf("for the node :%d\tthe starting time is %d\t and the finishing time is %d\n",i,s_time[i],f_time[i]);
				s2++;	
			}
			if(visit[i]==0)
				k=i;
		}
		printf("\n");			
		r++;
		j=n-s2;
	}
	printf("\n");
}
