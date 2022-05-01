#include <iostream>

using namespace std;

class node{

    public:
        int data;
        node *next;

        node(int d){
            this->data = d;
            this->next = NULL;
        }

        ~node(){
            if(this->next !=NULL){
                this->next = NULL;
                delete next;
            }
            cout<<endl<<"delete node of data value : "<<this->data<<endl<<endl;
        }

};

void insert(node * &tail , int positionData , int data){  //isme ek hi pointer hota hai --> head ya tail

    if(tail == NULL){
        node *newnode = new node(data);
        tail = newnode;
        newnode->next = newnode;
        return;
    }

    node *newnode = new node(data);
    node *temp = tail;
    while(temp->data != positionData){
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    tail = newnode;

}

void deletion(node * &tail , int data){

    node *prev = tail;
    node *curr = prev->next;
    while(curr->data != data ){
        prev = prev->next;
        curr = curr->next;
    }
    if(prev == curr){ // in this case , there is only single node present in the linked list
        delete curr;
        tail = NULL;
        return;
    }

    if(curr==tail){   // this condition is used because tail may be pointing that node which is going to delete .
    
        tail = tail->next;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;

}

void print(node * &tail){

    if(tail == NULL){
        cout<<"there is no node in linked list"<<endl;
        return;
    }
    node *temp = tail;
    cout<<endl<<endl;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != tail);

    cout<<endl<<endl;
}

int main(){

    // there is no head and no tail in circular linked list (CLL) 
    // but we use a pointer tail or head to traverse a linked list

    node *tail = NULL;

    // INSERTION : CLL me hum node ke data ke next position me insert karte hai.

    insert(tail,20,10);
    print(tail);
    insert(tail,10,20);
    print(tail);
    insert(tail,20,30);
    print(tail);

    //DELETION : 

    cout<<"tail data : "<<tail->data<<endl;
    deletion(tail,30);
    cout<<"tail data : "<<tail->data<<endl;
   
    print(tail);
    deletion(tail,20);
    print(tail);
    deletion(tail,10);
    print(tail);

    return 0;
}