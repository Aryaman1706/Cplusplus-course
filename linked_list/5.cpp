//program to demonstrate doubly linked list

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
};

class LinkedList{
    public:
        Node* head;

        LinkedList(int A[], int n){
            Node* last = NULL;
            Node* current = NULL;
            
            head = new Node();
            head->data = A[0];
            head->prev = NULL;
            head->next = NULL;
            last = head;

            for(int i=1; i<n; i++){
                current = new Node();
                current->data = A[i];
                last->next = current;
                current->prev = last;
                current->next = NULL;
                last = current;
            }
        };

        void display(){
            Node* ptr = head;
            while(ptr != NULL){
                cout<<ptr->data<<"~";
                ptr = ptr->next;
            }
            cout<<"NULL"<<endl;
        };

        void displayReverse(){
            Node* ptr = head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            while( ptr != NULL ){
                cout<<ptr->data<<"~";
                ptr = ptr->prev;
            }
            cout<<"NULL"<<endl;
        };

        void insert(int pos, int value){
            Node* p = head;
            Node* current = new Node();
            current->data = value;
            
            if( pos == 0 ){
                p->prev = current;
                current->next = p;
                current->prev = NULL;
                head = current;
            } else{
                for(int i=0; i<pos-1; i++){
                    p = p->next;
                }
                current->next = p->next;
                p->next = current;
                current->prev = p;
                if( p->next != NULL ){
                    p->next->prev = current;
                };
            }
        };
        
        void Delete(int pos){
            Node * p = head;
            if( pos == 1 ){
                head = head->next;
                head->prev = NULL;
                delete p;
            }else{
                for(int i=0; i<pos-1; i++){
                    p = p->next;
                }
                p->prev->next = p->next;
                if( p->next != NULL ){
                    p->next->prev = p->prev; 
                };
                delete p;
            }
        };

        void Reverse(){
            Node* p = head;
            Node* temp = NULL; // to help in swaping 
            while ( p != NULL ){
                temp = p->next;
                p->next = p->prev;
                p->prev = temp;

                p = p->prev;
                if (p != NULL && p->next == NULL ){
                    head = p;
                }
            }
        };
};

int main(){
    int A[5] = { 1, 5, 7, 8 ,3 };
    LinkedList LL(A, 5);
    LL.display();
    LL.Reverse();
    LL.display();
}