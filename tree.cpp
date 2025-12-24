#include<iostream>
using namespace std;

struct treeNode{
    int value;
    treeNode* Left;
    treeNode* Right;
};

void preOrder(treeNode* root){
    if(root){
        cout<<root->value<<" ";
        preOrder(root->Left);
        preOrder(root->Right);
    }
}

void inOrder(treeNode* root){
    if(root){
        inOrder(root->Left);
        cout<<root->value<<" ";
        inOrder(root->Right);
    }
}

void postOrder(treeNode* root){
    if(root){
        postOrder(root->Left);
        postOrder(root->Right);
        cout<<root->value<<" ";
    }
}
int main(){
    treeNode *head =new treeNode();
    head->value=7;
    head->Left =new treeNode();
    head->Right =new treeNode();
    head->Left->value=6;
    head->Right->value=9;
    head->Left->Left = new treeNode();
    head->Left->Right = new treeNode();
    head->Left->Left->value=2;
    head->Left->Right->value=10;
    head->Right->Left = new treeNode();
    head->Right->Right = new treeNode();
    head->Right->Left->value=4;
    head->Right->Right->value=12;

    preOrder(head);
    cout<<endl;
    inOrder(head);
    cout<<endl;
    postOrder(head);
    cout<<endl;


} 