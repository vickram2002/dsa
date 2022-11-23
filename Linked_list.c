#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node *next;
};
struct node *head=NULL;

void insert(int a[],int n)
{
	
	struct node *las;
	head=(struct node*) malloc(sizeof(struct node));
	head->val=a[0];
	head->next=NULL;
	las=head;
	int i;
	for(i=1;i<n;i++)
	{
		struct node t=(struct node) malloc(sizeof(struct node));
		t->val=a[i];
		t->next=NULL;
		las->next=t;
		las=t;
	}
	printf("fgasgsdrfg");
}
void display(struct node *p)
{
	printf("\n");
	while(p->next!=NULL)
	{
		printf("%d->",p->val);
		p=p->next;
	}
	printf("%d",p->val);
}
void rec(struct node *p)
{
	if(p!=NULL)
	{
		printf("%d ",p->val);
		rec(p->next);
	}
}

int count(struct node *t)
{
	int n=0;
	while(t!=NULL)
	{
		n++;
		t=t->next;
	}
	return n;
}

int sum(struct node *t)
{
	int sum=0;
	while(t!=NULL)
	{
		sum+=(t->val);
		t=t->next;
	}
	return sum;
}

int max(struct node *p)
{
	int max=-15111;
	while(p!=NULL)
	{
		if(max<p->val)
			max=p->val;
		p=p->next;
	}
	return max;
}
int search(struct node *p,int t)
{
	while(p!=NULL)
	{
		if(p->val==t)
			return 1;
		p=p->next;
	}
	return 0;
}

void insert1(struct node *p,int n,int pos)
{
	struct node *ne=(struct node *) malloc(sizeof(struct node));
	struct node *t,*t1;
	if(pos==1){
		ne->val=n;
		ne->next=head;
		head=ne;
	}
	t=head; int i;
	for(i=1;i<pos-1;i++)
	{
		t=t->next;
	} 
	ne->val=n;
	ne->next=t->next;
	t->next=ne;
}

void insert2(struct node *p,int n)
{
	struct node ne=(struct node) malloc(sizeof(struct node));
	struct node*t=head,*q=NULL;
	while(t && t->val<=n)
	{
		q=t;
		t=t->next;
	}
	ne->val=n;
	q->next=ne;
	ne->next=t;

}

void delete(struct node *p,int pos)
{
	
	struct node *t=p,*t1=NULL;
	int i;
	
	for(i=1;i<pos;i++)
	{
		t1=t;
		t=t->next;
	}
	t1->next=t->next;
	free(t);
}

int sort_not(struct node *p)
{
	struct node *t=p;
	while(t->next!=NULL)
	{
		if(t->val>t->next->val)
			return 0;
		t=t->next;
	}
	return 1;
	
}
void dup(struct node *p)
{
	struct node *t=p->next,*q=p;
	while(t!=NULL)
	{
		if(t->val!=q->val)
		{
			q=t;
			t=t->next;
		}
		else
		{
			q->next=t->next;
			free(t);
			t->next=q;
		}
	}
	
	
}

void main()
{
	int a[8]={4,5,8,9,11,11,63,75};
	insert(a,8);
	rec(head);
	printf("\n the count is: %d",count(head));
	printf("\n the sum is: %d",sum(head));
	printf("\nThe maximum element is: %d",max(head));
	int x=search(head,63);
	if(x==1)
		printf("\nThe element 63 is present.");
	else
		printf("The element 63 is not found.");
	insert1(head,56,7);
	display(head);
	insert2(head,15);
	printf("\n");
	display(head);
	x=sort_not(head);
	if(x==1)
		printf("\nsorted..");
	else
		printf("\nNot sorted");
	dup(head);
	display(head);
}
