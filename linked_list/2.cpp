// program to merge and concatenate 2 LL

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

Node* first=NULL;
Node* second=NULL;
Node* third=NULL;

void create1(int A[], int n){
    
    Node* temp = NULL;
    Node* last = NULL;
    
    first = new Node();
    first->data = A[0];
    first->next = NULL;
    last = first;

   for(int i=1; i<n; i++){
        temp = new Node();
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
};

void create2(int A[], int n){
    
    Node* temp = NULL;
    Node* last = NULL;
    
    second = new Node();
    second->data = A[0];
    second->next = NULL;
    last = second;

   for(int i=1; i<n; i++){
        temp = new Node();
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
};

void display(Node* ptr){
    while( ptr != NULL){
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }
    cout<<"NULL"<<endl;
};

void Append(Node *p, Node *q){
    while( p->next != NULL){
        p=p->next;
    }
    p->next = q;
};

void Merge(Node *p, Node *q){ // only for sorted
    Node* last = NULL;
    if ( p->data < q->data ){
        third = last = p;
        p = p->next;
        third->next = NULL;
    } else{
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while( p != NULL && q != NULL ){
        if( p->data < q->data  ){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        } else{
            last->next = q;
            last  = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if( p!= NULL ){
        last->next = p;
    };
    if( q != NULL ){
        last->next = q;
    }
};

int main(){
    int A1[5]={1, 5, 7, 8, 10};
    int A2[6]={2, 3, 4, 6, 9, 15};

    create1(A1, 5);
    create2(A2, 6);

    display(first);
    display(second);

    Merge(first, second);
    display(third); // alt- display(first);
}