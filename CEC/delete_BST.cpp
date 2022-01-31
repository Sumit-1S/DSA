#include<bits/stdc++.h>
using namespace std;

// Code to print all the ancestors of an node in the tree

struct Tree{
  int data;
  Tree *left=NULL,*right=NULL;
  Tree(int a){
    this->data=a;
  }
};

vector<int> v;
Tree* root;
Tree* dele(Tree*del)
{
  if(!root->right and !root->left){free(root);return NULL;}
  else if(root->left){
    Tree* temp = del->left;
    Tree* parent = del;
    while(del->left!=NULL){
      parent=temp;
      temp=temp->right;
    }
    del->data=temp->data;
    if(temp==parent->left)
      parent->left = dele(temp);
    else
      parent->right = dele(temp);
  }
  else{
    Tree* temp = del->right;
    Tree* parent = del;
    while(del->left!=NULL){
      parent=temp;
      temp=temp->left;
    }
    del->data=temp->data;
    if(temp==parent->right)
      parent->right = dele(temp);
    else
      parent->left = dele(temp);
  }
}

void print(Tree* t){
  if(!t)return;
  print(t->left);
  cout<<t->data<<" ";
  print(t->right);
}

int main()
{
  Tree *t=new Tree(4);
  t->left = new Tree(2);
  t->right = new Tree(6);
  t->left->left = new Tree(1);
  t->left->right = new Tree(3);
  t->right->left = new Tree(5);
  t->right->right = new Tree(7);
  print(t);
  cout<<endl;
  root=t;
  cout<<root->data<<endl;
  t = dele(t);
  print(root);
  cout<<endl;
  return 0;
}