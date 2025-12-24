#include<iostream>
using namespace std;

struct treeNode{
    int value;
    treeNode* left;
    treeNode* right;

    treeNode(int x){
        value=x;
        left=NULL;
        right=NULL;
    }
};

void preOrder(treeNode* root){
if(root){
    cout<<root->value<<" ";
    preOrder(root->left);
    preOrder(root->right);
    }
}
void inOrder(treeNode* root){
if(root){
    preOrder(root->left);
    cout<<root->value<<" ";
    preOrder(root->right);
    }
}
void postOrder(treeNode* root){
if(root){
    preOrder(root->left);
    preOrder(root->right);
      cout<<root->value<<" ";
    }
}

int main(){
    treeNode* head =new treeNode(1);
    head->left=new treeNode(2);
    head->right=new treeNode(3);
    head->left->left=new treeNode(4);
    head->left->right = new treeNode(5);
    head->right->left= new treeNode(6);
    head->right->right= new treeNode(7);

    preOrder(head);
    cout<<endl;

     inOrder(head);
    cout<<endl;

     postOrder(head);
     cout<<endl;
}
