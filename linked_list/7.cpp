// program to find midpoint of LL

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class LinkedList{
    private:
        Node * head = NULL;
    public:
        LinkedList(int A[], int n){
            Node * current = NULL;
            Node * last = NULL;
            
            head = new Node();
            head->data = A[0];
            head-> next = NULL;
            last = head;

            for(int i=1; i<n; i++){
                current = new Node();
                current->data = A[i];
                current->next = NULL;
                last->next = current;
                last = current; 
            }
        };

        void display(){
            Node* ptr = head;
            while(ptr != NULL){
                cout<<ptr->data<<" -> ";
                ptr = ptr->next;
            }
            cout<<"NULL"<<endl;
        };
        void Midpoint(){
            Node* p = head; // speed = X
            Node* q = head; // speed = 2X
            while( q->next != NULL ){
                q = q->next;
                p = p->next;
                if( q->next != NULL){
                    q = q->next;
                }
            }
            cout<<"Value at Midpoint is "<<p->data<<endl;
        };
};

int main(){
    int A[6] = {5, 7, 8, 12, 15, 20};
    LinkedList LL(A, 6);
    LL.display();
    LL.Midpoint();
}