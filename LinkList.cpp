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


int main()
{
    node *head=NULL;
    head = insert_tail(head,10);
    head = insert_tail(head,20);
    head = insert_tail(head,30);
    head = insert_tail(head,40);
    head = insert_tail(head,50);
    display(head);
    return 0;
}