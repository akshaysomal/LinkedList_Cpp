#include <iostream>

using namespace std;

class node{

    public:
        int data ;

        node *next;  // this next pointer is pointing to next node so this next pointer should be of node type

        node(int data){
            this->data = data;
            this->next = NULL;
        }

        ~node(){
          if(this->next != NULL){
              this->next = NULL;
              delete next;    
          }
          cout<<"we delete the node of data "<<this->data;
        }
};

void insertAtHead(node * &head , int data){
    node *temp = new node(data);
    temp->next = head;   // link with previous node
    head = temp; // set new node as head or top node
}

void insertAtTail(node * &tail , int data){
    node *temp = new node(data);
    tail->next = temp;
    tail=temp;
}

void insertAtPosition(node * &head , node * &tail , int position , int data){

    if(position == 1){
        insertAtHead(head,data);
        return;
    }
    int count = 1;
    node *temp = head;
    while(count<position-1){
        temp = temp->next;
        count++;
    }
    if(temp->next == NULL){   // without this condition ,,,this function can insert at last position 
        insertAtTail(tail,data); // but tail was not updated . so we use this condition
        return;
    }
    node *newnode = new node(data);
    newnode->next = temp->next;
    temp->next = newnode;
}


void deleteAtHead(node * &head){
    node *temp = head;
    head = head->next;
    delete temp;

}

void deleteAtTail(node * &head , node * &tail){

    node *temp = head;

    cout<<"tail data "<<tail->data<<endl;
   
    while(temp->next!=tail){
        temp=temp->next;
    }
    temp->next=NULL;
    delete tail;
    tail = temp;

}

void deleteAtPosition(node * &head , node * &tail , int position){
    
    if(position == 1){
        deleteAtHead(head);
        return;
    }
    int count = 1;
    node *curr = head;
    node *prev = NULL;
    while(count<=position - 1){  //two pointer approach
        prev = curr;
        curr = curr->next;
        count++;
    }

    if(curr->next==NULL){
        deleteAtTail(head,tail);
        return;
    }


    prev->next = curr->next;
    delete curr;

}

void printLinkedList(node * &head ){

    cout<<endl;

    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

    node *node1 = new node(100);

    node *head = node1;

    node *tail = node1;

    // cout<<"Data at node 1 : "<<node1->data<<endl;
    // cout<<"Next of node 1 : "<<node1->next<<endl;

    // Insertion at head

    cout<<endl<<"Inserting at head"<<endl<<endl;

    insertAtHead(head,200);

    cout<<endl<<"Linked List after inserting one node : ";

    printLinkedList(head);

    insertAtHead(head,300);

    
    cout<<endl<<"Linked List after inserting one node : ";
    printLinkedList(head);

    cout<<endl<<endl;

    // insertion at tail

    cout<<"Insert at Tail "<<endl<<endl;

    insertAtTail(tail,500);

    cout<<"Nodes values after tail insertion is : ";

    printLinkedList(head);

    cout<<endl<<endl;


    // Insertion at any position

    cout<<endl<<"Insertion at any position "<<endl<<endl;

    insertAtPosition(head,tail,5,1000);

    //but if we enter position as 1 it does not work because we are starting from position 1 .
    // so we can add only after node 1;

    //to overcome this problem , we add a condition in that function . 

    printLinkedList(head);

    cout<<endl<<endl;




    // deletion 

    cout<<"delete at position "<<endl<<endl;

    deleteAtPosition(head,tail,2);

    printLinkedList(head);




    cout<<"\ndelete at head"<<endl;

    deleteAtHead(head);

    cout<<endl<<endl;
    printLinkedList(head);
    cout<<endl<<endl;

    deleteAtTail(head,tail);

    cout<<endl<<endl;
    cout<<"delete at tail \n";

    printLinkedList(head);
    
    cout<<endl<<endl;

    cout<<"head data "<<head->data<<endl;

    cout<<"tail data "<<tail->data<<endl;


    return 1;
}