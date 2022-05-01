#include <iostream>

using namespace std;

class node{
    public:
        int data ;
        node *next;
        node *prev;

        node(int d){
            this->data = d;
            this->next = NULL;
            this->prev = NULL;
        }

        ~node(){
            if(this->next!=NULL){
                this->next = NULL;
                delete next;
            }
            cout<<"we delete the node of data "<<this->data<<endl<<endl;
        }
};

void insertAtHead(node * &head , node * &tail , int data){

    if(head == NULL){
        node *newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }

    node *newnode = new node(data);
    newnode->next = head;
    head->prev = newnode;
    head = newnode;

}

void insertAtTail(node * &head , node * &tail , int data){

    if(tail == NULL){
        node *newnode = new node (data);
        head = newnode;
        tail = newnode;
        return;
    }

    node *newnode = new node(data);
    newnode ->prev = tail;
    tail->next = newnode;
    tail = newnode;

}

void insertAtPosition(node * &head , node * &tail , int data , int position){

    if(position == 1){
        insertAtHead(head,tail,data);
        return;
    }
    int count = 1;
    node * temp = head;
    while(count < position-1){
        temp = temp->next;
        count++;
    }
    if(temp->next == NULL){
        insertAtTail(head,tail,data);
        return ;
    }
    node *newnode = new node(data);
    newnode->next = temp->next;
    temp->next->prev = newnode;
    newnode->prev = temp;
    temp->next = newnode;

}

void deleteAtPosition(node * &head , node * &tail , int position){

    if(position == 1){
        node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    node *temp = head;
    int count = 1;

    while(count <= position - 1){  // temp ki position = position
        temp = temp->next;
        count++;
    }

    cout<<"Temp "<<temp->data<<endl<<endl;

    if(temp->next == NULL){  //yaha temp , tail ko point kar raha hai
        tail = temp->prev; 
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->prev = NULL;
    temp->next = NULL;
    delete temp;

}

void print(node * &head , node * &tail){

    cout<<"Elements of Linked List : ";
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl<<"head : "<<head->data;
    cout<<endl<<"tail : "<<tail->data;
    cout<<endl<<endl;
}

void printReverse(node * &head , node * &tail){

    cout<<"Elements in Reverse order : ";
    node* temp = head;
    while(temp->next!=NULL){  // Last tak pahuchne ke liye
        temp = temp->next;
    }

    while(temp!=head->prev){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl<<"head : "<<head->data;
    cout<<endl<<"tail : "<<tail->data;
    cout<<endl<<endl;

}

int main(){

    node *head = NULL;
    node *tail = NULL;

    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);

    print(head,tail);
    //printReverse(head,tail);

    insertAtTail(head,tail,50);
    insertAtTail(head,tail,60);
    insertAtTail(head,tail,70);

    print(head,tail);
    //printReverse(head,tail);

    insertAtPosition(head,tail,80,3);
    insertAtPosition(head,tail,90,7);
    insertAtPosition(head,tail,100,10);

    print(head,tail);
    //printReverse(head,tail);

    // Deletion 

    deleteAtPosition(head,tail,1);

    print(head,tail);
    //printReverse(head,tail);

    deleteAtPosition(head,tail,6);

    print(head,tail);

    deleteAtPosition(head,tail,8);

    print(head,tail);

    return 0;

}