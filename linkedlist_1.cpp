#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data)
     {
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
      int value = this->data;
      //memory free
      if(this->next !=NULL){
        delete next;
        this->next =NULL;
      }
      cout<<"memory is free for"<<data<<endl; 
    }
    };

    //Inserting in the start from head
    void insertAtHead(Node* &head,int d){
      //step1 :Create a new node temp
      Node* temp= new Node(d);
      temp -> next=head;
      head= temp;
    }

    //Inserting in the end from tail
    void insertAtTail(Node* &tail,int d){
      Node* temp =new Node(d);
      tail->next=temp;
      tail=temp;
    }


    //Insert at the position
    void insertAtPosition(Node* &head,Node* &tail, int position,int d){
     //starting edge case
      if (position==1){
        insertAtHead(head,d);
        return;
      }
      
      Node* temp= head;
      int cnt =1;
      while(cnt<position-1){
        temp=temp->next;
        cnt++;
      }
      //tail edge case
      if (temp->next ==NULL){
        insertAtTail(tail,d);
        return;
      }
            //creating a new node for data
      Node * datatoinsert =new Node(d);
      datatoinsert->next = temp->next;
      temp->next = datatoinsert;
    }


    //Printig the Linked List
void print(Node* head){
      Node* temp= head;
      while(temp!=NULL){
        cout<< temp-> data<<" ";
        temp=temp->next;
         }  
        cout<<endl;  
    }

 void deleteNode(Node* &head ,Node* &tail, int position){
  if(position ==1){
     Node * temp =head;
     head=head->next;
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
    prev->next=curr->next;
    curr->next =NULL;
    delete curr;
  }


  //  Delete by value
  void deleteByValue(Node* &head, Node* &tail,int value){
    if(head->data==value){
      Node* temp =head;
      head=head->next;
      delete temp;
      return;
    }

    Node*curr=head->next;
    Node* prev=head;
    while(curr!=NULL &&curr->data!=value){
      prev = curr;
      curr=curr->next;
    }

    if (curr==tail){
        tail=prev;
        tail->next=NULL;
        delete curr;
        return;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
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
  Node* node1 =new Node(10);
  cout<< node1->data<<endl;
  // cout<< node1->next<<endl;
   Node* head =node1;
  // insertAtHead(head,20);
  // print(head);
  // insertAtHead(head,30);
  // print(head);
  Node* tail = node1;
  insertAtTail(tail,20);
  print(head);
  insertAtTail(tail,30);
  print(head);

  insertAtPosition(head,tail,1,50);
  insertAtPosition(head,tail,5,60);
  print(head);
  // cout<<head->data<<" "<<head->next<<endl;
  // cout<<tail->data<<" "<<tail->next<<endl;
  // deleteNode(head,tail,5);
  // print(head);
 

  deleteByValue(head,tail,60);
  print(head);
  cout<<head->data<<" "<<head->next<<endl;
  cout<<tail->data<<" "<<tail->next<<endl;
  if(isCircular(tail)){
        cout<<"Linked list is circular"<<endl;
    }
    else{
        cout<<"Linked List is not circular";
    }
}

