// program to check if LL has a loop

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

Node* first=NULL;

void create(int A[], int n){
    
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

void display(Node* ptr){
    while( ptr != NULL){
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }
    cout<<"NULL"<<endl;
};

void isLoop(Node * ptr){
    Node* ptr2=NULL;
    ptr2 = ptr; // ptr will jump 1 node and ptr2 will jump 2 nodes
    ptr = ptr->next;
    ptr2 = ptr2->next->next;
    while( ptr != NULL && ptr2 != NULL && ptr != ptr2){
        ptr = ptr->next;
        ptr2 = ptr2->next;
        if(  ptr2 != NULL){
            ptr2 = ptr2->next;
        }
    }
    if( ptr == ptr2 ){
        cout<<"This LL has a loop"<<endl;
    } else{
        cout<<"This LL DOES NOT have a loop"<<endl;
    }
};

int main(){
    int A[5] = {1, 2, 3, 4, 5 };
    create(A, 5);
    isLoop(first);
    display(first);

    // making it loop
    Node * t1;
    Node * t2;

    t1 = first->next->next; // pointing at 3
    t2 = first->next->next->next->next; // pointing at 5
    t2->next = t1;

    isLoop(first);
}