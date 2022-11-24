#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node *next;
};
struct node *head=NULL;

void insert(int val)
{
    struct node *p=(struct node *) malloc(sizeof(struct node));
    struct node *t;
    if(head==NULL)
    {
        p->val=val;
        p->next=NULL;
        head=p;
    }
    else{
    t=head;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    p->val=val;
    t->next=p;
    p->next=NULL;}


}

void del(struct node *head,int pos)
{
    struct node *t=head,*p=head->next;int i;
    if(pos==1)
    {
        head=p;
        free(t);
    }
    for(i=2;i<pos;i++)
    {
        t=p;
        p=p->next;
    }
    t->next=p->next;
    free(p);
}

int isSort(struct node *head)
{
    struct node *t=head;
    while(t->next!=NULL)
    {
        if((t->val)>(t->next->val))
            return 0;
        t=t->next;
    }
    return 1;
}

void dup(struct node *head)
{
    struct node *t;
    t=head; int c=1;
    while(t->next!=NULL)
    {
        if(t->val==t->next->val)
        {
            c++;
            del(head,c);
        }
        else
        {
            c++;t=t->next;
        }
    }
}
void display(struct node *head)
{

    struct node *p=head;
    printf("\n");

    while(p->next!=NULL)
    {
        printf("%d->",p->val);

        p=p->next;
    }
    printf("%d",p->val);
}


void main()
{
    int i;
    for(i=1;i<10;i++)
        insert(i);
    insert(9);
    display(head);
    printf("\nIssorted: %d",isSort(head));
    dup(head);
    display(head);
}
