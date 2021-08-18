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

int height(node* root) //O(n)
{
    if(root==NULL)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight,rheight)+1;
}

int diameter(node* root) //O(n^2)
{
    if(root==NULL)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    int currdia = lheight+rheight+1;

    int ldia = diameter(root->left);
    int rdia = diameter(root->right);

    return max(currdia,max(ldia,rdia));
}

int CalcDia(node* root)
{
    
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
    n->right->right->left = new node(8);
    cout<<height(n)<<endl;
    cout<<diameter(n);
    return 0;
}