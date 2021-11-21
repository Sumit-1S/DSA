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

node* Reverse(node* head)       //Using Iterative approach
{
    node* prev = NULL;
    node* curr = head;
    node* next;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

node* reverse(node* &head)
{
    if(head==NULL || head->next ==NULL)
        return head;
    
    node* newhead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
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
    node* Rev_head = Reverse(head);
    node* rev_head = reverse(Rev_head);
    display(rev_head);
    return 0;
}