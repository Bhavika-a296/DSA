#include<iostream>
using namespace std;

class Node{
   public:
   int data;
   Node* next ;
   
   Node(int data){
    this->data=data;
    this->next=NULL;
   }
   ~Node(){
    int value=this->data;
    if(this->next!=NULL){
        delete next;
        this->next=NULL;
    }
    cout<<"Memory free for value"<<value<<endl;
   }
    
};
void insertNode(Node* &tail,int element,int d){
      //step1 :Create a new node temp
      //Empty list
     if (tail==NULL){
         Node* temp1= new Node(d);
         tail=temp1;
         temp1->next=temp1;
     }
     //assuming the element is present
     else{
        Node* curr= tail;
        while(curr->data !=element){
            curr=curr->next;
        }
        Node* temp= new Node(d);
        temp->next=curr->next;
        curr->next=temp;

     }
    }
// void insertAtTail(Node* &tail,int data){
//     Node*temp = new Node(data);
//     tail->next=temp;
//     tail=temp;
// }  
void print(Node* &tail){
     if(tail==NULL){
        cout<<"The List is empty"<<endl;
        return;
    }
    Node* temp =tail;
   do{
    cout<<tail->data<<" ";
    tail=tail->next;
   }while(tail!=temp);
   cout<<endl;

}
void deleteNode(Node* &tail,int value){
    if(tail==NULL){
        cout<<"The List is empty"<<endl;
        return;
    }

    else{
    //non-empty
    //assuming that the value is present in the list
    Node *prev=tail;
    Node *curr=prev->next;
//1 element
    if(curr==prev){
        tail=NULL;
    }

    while(curr->data!=value){
      prev=curr;
      curr=curr->next;
    }
//2 element
    prev->next=curr->next;
    if(tail==curr){
        tail=prev;
    }
    curr->next=NULL;
    delete curr;
    }

}
bool isCircular(Node* head){
    Node* temp=head->next;
    while(temp!=NULL&&temp!=head){
        temp=temp->next;
    }
    if(temp==head){
        return true;
    }
    return false;
}

int main(){
    Node *tail=NULL;
    Node *head=NULL;
    insertNode(tail,5,3);
    print(tail);
    insertNode(tail,3,4);
    print(tail);
    deleteNode(tail,3);
    print(tail);
    cout<<tail->data<<" "<<tail->next<<endl;
    if(isCircular(tail)){
        cout<<"Linked list is circular"<<endl;
    }
    else{
        cout<<"Linked List is not circular";
    }
}