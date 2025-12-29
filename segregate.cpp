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
};
Node * segregate(Node* head) {
        // code here
        int zeroCount=0;
        int oneCount=0;
        int twoCount=0;
         
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data==0)
                zeroCount++;
           else if(temp->data==1)
                oneCount++;
            else if(temp->data==2)
                twoCount++;
            temp=temp->next;    
               
            
        }
        temp=head;
        while(temp!=NULL){
            if(zeroCount!=0){
                temp->data=0;
                zeroCount--;
            }
             else if(oneCount!=0){
                temp->data=1;
                oneCount--;
            }
            else if(twoCount!=0){
                temp->data=2;
                twoCount--;
            }
            temp=temp->next;
        }
        return head;
    }
 void insertAtHead(Node* &head,int d){
      //step1 :Create a new node temp
      Node* temp= new Node(d);
      temp -> next=head;
      head= temp;
    }
void print(Node* head){
      Node* temp= head;
      while(temp!=NULL){
        cout<< temp-> data<<" ";
        temp=temp->next;
         }  
        cout<<endl;  
    }    
int main(){
     Node* node1 =new Node(1);
   //cout<< node1->data<<endl;
  // cout<< node1->next<<endl;
   Node* head =node1;
   insertAtHead(head,2);
   insertAtHead(head,0);
   insertAtHead(head,1);
   insertAtHead(head,0);
   insertAtHead(head,2);
   insertAtHead(head,1);
   insertAtHead(head,2);
   insertAtHead(head,0);
   insertAtHead(head,1);
   insertAtHead(head,0);
   cout << "Before segregation:\n";
    print(head);

    head = segregate(head);

    cout << "After segregation:\n";
    print(head);
}    
//The Approach here is to count the number of 0s and 1s present in the linked list and then first place 0s in their right position then 1s and then 2s 