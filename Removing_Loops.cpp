#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

node* insert_tail(node* head,int data)
{
    if(head==NULL)
    {
        head = new node(data);
        return head;
    }
    node *temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = new node(data);
    return head;
}

void display(node *head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

bool detect(node* &head)
{
    node* slow = head;
    node* fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if(slow==fast)
            return true;
    }
    return false;
}

void remove(node* head)
{
    node* fast = head;
    node* slow = head;
    do
    {
        fast = fast->next->next;
        slow = slow->next;
    }while(fast!=slow);
    fast = head;
    while(slow->next!=fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

void create_loop(node* head,int k)
{
    node* temp=head;
    node* temp2;
    int count=0;
    while(temp->next!=NULL)
    {
        count++;
        if(count==k)
            temp2 = temp;
        temp = temp->next;
    }
    temp->next = temp2;
}

int main()
{
    node *head=NULL;
    head = insert_tail(head,10);
    head = insert_tail(head,20);
    head = insert_tail(head,30);
    head = insert_tail(head,40);
    head = insert_tail(head,50);
    head = insert_tail(head,60);
    head = insert_tail(head,70);
    head = insert_tail(head,80);
    head = insert_tail(head,90);
    display(head);
    create_loop(head,3);
    if(detect(head))
    {
        remove(head);
    }
    display(head);
    return 0;
}