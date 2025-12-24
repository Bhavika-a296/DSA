#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
       this->data =d;
       this->prev=NULL;
       this->next=NULL;
    }
    ~Node(){
        int value=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
    }
    cout<<"Memory free for node with data "<<value<<endl;
    }
};
//Traversing the linked list

//to get the length of the linkedlist
int getlen(Node* &head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
void insertAtHead(Node* &head,Node* &tail,int data){
    if (head==NULL){
        Node* temp=new Node(data);
        head=tail=temp;
    }
    else{
    Node* temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}

void insertAtTail(Node* &head,Node* &tail,int data){
    if(head==NULL){
    Node *temp =new Node(data);
      tail=head=temp;
    }
    else{
  Node *temp =new Node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


void insertAtPosition(Node* &head,Node* &tail,int position,int d){
    if(position==1){
        insertAtHead(head,tail,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(head,tail,d);
        return;
    }

    Node* nodeToInsert=new Node(d);
    nodeToInsert->next = temp->next;
    nodeToInsert->prev=temp;

    temp->next->prev =nodeToInsert;
    temp->next=nodeToInsert;  
}




void deleteNode(Node* &head ,Node* &tail, int position){
  if(position ==1){
     Node * temp =head;
     temp->next->prev=NULL;
     head=temp->next;
     temp->next=NULL;
     delete temp;
     return;
  }

    Node *curr=head;
    Node* prev =NULL;
    int cnt =1;
    while(cnt<position &&curr!=NULL){
      prev=curr;
      curr=curr->next;
      cnt++;
    }
    if(curr->next ==NULL){
      tail=prev;
      tail->next =NULL;
      delete curr;
      return;
    }
    curr->prev=NULL;
    prev->next=curr->next;
    curr->next =NULL;
    delete curr;
  }





int main(){
    
    Node* head=NULL;
    Node* tail=NULL;
    print(head);
    insertAtHead(head,tail,100);
    print(head);
    insertAtTail(head,tail,60);
    print(head);
     insertAtHead(head,tail,50);
    print(head);
    insertAtTail(head,tail,80);
    print(head);
     insertAtHead(head,tail,70);
    print(head);
     insertAtTail(head,tail,100);
    print(head);
     insertAtTail(head,tail,120);
    print(head);
    insertAtPosition(head,tail,1,66);
    print(head);
     insertAtPosition(head,tail,9,99);
    print(head);
    insertAtPosition(head,tail,3,999);
    print(head);
    deleteNode(head,tail,1);
    print(head);
    deleteNode(head,tail,9);
    print(head);
}