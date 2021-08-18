#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    node* left;
    node* right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
}node;

void no_nodes(node* root)
{
    if(!root)
        return;
    
    int level=1;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* front = q.front();
        q.pop();
        if(front)
        {
            if(front->left)
            q.push(front->left);
            if(front->right)
            q.push(front->right);
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    cout<<level;
}

void sum_all_nodes(node* root)
{
    if(!root)
        return;
    
    int sum=0;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* front = q.front();
        q.pop();
        if(front)
        {
            sum+=front->data;
            if(front->left)
            q.push(front->left);
            if(front->right)
            q.push(front->right);
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
    cout<<sum;
}



int main()
{
    node* n = new node(1);
    n->left = new node(2);
    n->right = new node(3);
    n->left->left = new node(4);
    n->left->right = new node(5);
    n->right->left = new node(6);
    n->right->right = new node(7);
    
    sum_all_nodes(n);
    return 0;
}