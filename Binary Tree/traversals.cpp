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

int search(int inorder[],int start,int end,int curr)
{
    for(int i=start;i<=end;i++)
        if(inorder[i]==curr)
            return i;
    return -1;
}

//convert given pre-In order to Tree
node* build_tree_pre_inorder(int preorder[],int inorder[],int start,int end)
{
    static int idx =0;
    if(start>end)
        return NULL;
    int curr = preorder[idx];
    idx++;
    node* n = new node(curr);
    if(start==end)
        return n;
    int pos = search(inorder,start,end,curr);
    n->left = build_tree_pre_inorder(preorder,inorder,start,pos-1);
    n->right = build_tree_pre_inorder(preorder,inorder,pos+1,end);
    return n;
}

//convert given post-In order to Tree
node* build_tree_post_inorder(int preorder[],int inorder[],int start,int end)
{
    static int idx =end;
    if(start>end)
        return NULL;
    int curr = preorder[idx];
    idx--;
    node* n = new node(curr);
    if(start==end)
        return n;
    int pos = search(inorder,start,end,curr);
    n->right = build_tree_post_inorder(preorder,inorder,pos+1,end);
    n->left = build_tree_post_inorder(preorder,inorder,start,pos-1);
    return n;
}

void level_order(node* root)//implemented using queue
{
    if(root==NULL)
        return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* front = q.front();
        q.pop();
        if(front){
            cout<<front->data<<" ";
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        else if(!q.empty())
            q.push(NULL);
    }
    
}

void k_level_sum(node* root,int k)//implemented using queue
{
    if(root==NULL)
        return;

    queue<node*> q;
    int sum=0;
    int level=0;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* front = q.front();
        q.pop();
        if(front){
            if(level==k)
            {
                sum+=front->data;
            }
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        else if(!q.empty()){
            q.push(NULL);
            level+=1;
        }
    }
    cout<<sum<<endl;
}

void display(node* root)
{
    if(root==NULL)
        return;
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}

int main()
{
//     int  preorder[] = {1,2,4,3,5};
//     int inorder[] = {4,2,1,5,3};

//     node* n = build_tree_post_inorder(preorder,inorder,0,4);
    node* n = new node(1);
    n->left = new node(2);
     n->right = new node(3);
     n->left->left = new node(4);
     n->left->right = new node(5);
     n->right->left = new node(6);
     n->right->right = new node(7);
    
    k_level_sum(n,1);
    return 0;
}