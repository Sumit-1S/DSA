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

node* reverse_knode(node* head,int k)
{
    node* prev = NULL;
    node* curr = head;
    node* next;
    int count=0;
    while(curr!=NULL && count<k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next!=NULL)
    {
        head->next = reverse_knode(next,k);
    }
    return prev;
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
    display(head);
    cout<<endl;
    node* newhead = reverse_knode(head,2);
    display(newhead);
    return 0;
}