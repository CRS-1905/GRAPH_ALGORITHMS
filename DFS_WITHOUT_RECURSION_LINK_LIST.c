#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node **a,*s,*v;
int *s_time,* f_time,*visit,*step,current_time,r=1;
void insert(int i,int j)
{
	struct node *new,*q;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=j;
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

void DFS()
{
	int k,s1,j,s2,p;
	struct node *q,*q1;
	while(s!=NULL)
	{
		k=pop();
		if(visit[k]==0)
		{
			s_time[k]=current_time;
			current_time++;
			visit[k]=1;
			push1(k);
			s1=1;
			q=a[k];
			while(q!=NULL)
			{
				j=q->data;
				if(visit[j]==0)
				{
					push(j);
					s1=0;
				}
				q=q->next;
			}
			if(s1==1)
			{
				visit[k]=2;
				f_time[k]=current_time;
				step[k]=r;
				current_time++;
				v=v->next;
				q=v;
				while(q!=NULL)
				{
					p=q->data;
					q1=a[p];
					s2=1;
					while(q1!=NULL)
					{
						j=q1->data;
						if(visit[j]==0)
						{
							current_time++;
							q1=NULL;
							s2=0;
						}
						else
							q1=q1->next;
					}
					if(s2==1)
					{
						visit[p]=2;
						step[p]=r;
						f_time[p]=current_time;
						current_time++;
						q=q->next;
						v=q;
					}
					else
					{
						v=q;
						q=NULL;
					}
				}
			}
		}
	}
//	v=NULL;
}
int main()
{
	int n,i,j,m,k,e,s1=0;
	struct node *q;
	printf("ENTER THE NUMBER OF NODES :\t");
	scanf("%d",&n);
	a=(struct node **)malloc(n*sizeof(struct node *));
	for(i=0;i<n;i++)
		a[i]=NULL;
	for(i=0;i<n;i++)
	{
		printf("ENTER THE NUMBER OF EDGES OF THE NODE %d:\t",i);
		scanf("%d",&m);
		printf("ENTER THE EDGES OF %d:\t",i);
		for(j=0;j<m;j++)
		{
			scanf("%d",&e);
			insert(i,e);
		}
	}
	printf("\n");
	printf("ENTER THE STARTING NODE :\t");
	scanf("%d",&k);
	s_time=(int *)malloc(n*sizeof(int));
	f_time=(int *)malloc(n*sizeof(int));
	visit=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		visit[i]=0;
	step=(int *)malloc(n*sizeof(int ));
	for(i=0;i<n;i++)
		step[i]=0;
	current_time=0;
	v=NULL;
	s=NULL;
	j=n;
	while(j>0)
	{
		push(k);
		DFS();
		for(i=0;i<n;i++)
		{
			if(visit[i]==0)
				k=i;
			else if(visit[i]==2 && step[i]==r)
			{
				printf("for node:%d\tstarting time is %d\t finishing time is%d\n",i,s_time[i],f_time[i]);
				s1++;
			}
		}
		printf("\n");
		r++;
		j=n-s1;
	}	
	printf("\n");
}
