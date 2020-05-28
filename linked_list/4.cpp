// program for operations on circular linked list

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
    // for linear LL
    /*
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
    */
    // for circular LL

        // eg:- (head)1 -> 2 -> 3 -> 4 -> 5 -> 1(head)
        LinkedList(int A[], int n){
            Node * current = NULL;
            Node * last = NULL;
            
            head = new Node();
            head->data = A[0];
            head-> next = head;
            last = head;

            for(int i=1; i<n; i++){
                current = new Node();
                current->data = A[i];
                current->next = NULL;
                last->next = current;
                last = current;
                last->next = head; 
            }
        };
        Node* pointerToHead(){
            Node* ptr = head;
            return ptr; 
        };
        void isLoop(){
            Node* ptr = head;
            Node* ptr2 = ptr;
            ptr = ptr->next;
            ptr2 = ptr2->next->next;
            while(ptr != NULL && ptr2 != NULL && ptr != ptr2){
                ptr = ptr->next;
                ptr2 = ptr2->next;
                if( ptr2 != NULL ){
                    ptr2 = ptr2->next;
                }
            } 
            if( ptr == ptr2 ){
                cout<<"This LL has a loop"<<endl;
            } else{
                cout<<"This LL does not have a loop"<<endl;
            }
        };
        /*
            working on LL which have a loop with first element
            (head)1 -> 2 -> 3 -> 4 -> 5 -> 1(head)
        */
        void displayCircular(){ 
            Node * ptr = head;
            // while loop wont work as ptr in starting only = head
            // hence we would use do while loop
            do{
                cout<<ptr->data<<" -> ";
                ptr = ptr->next;
            }while( ptr != head ) ;
            cout<<"Circle"<<endl;
        };
        void insert(int pos, int value){
            Node* p = head;
            if(pos == 0){
                Node* current = new Node();
                current->data = value;
                while ( p->next != head ){
                    p = p->next;
                }
                p->next = current;
                current->next = head;
                head = current;
            } else{
                for(int i=0; i<pos-1; i++){
                    p = p->next;
                };
                Node* current = new Node();
                current->data = value;
                current->next = p->next;
                p->next = current;
            }
        };
        void Delete(int pos){
            Node* p = head;
            if(pos == 1){
                while ( p->next != head ){
                    p = p->next;
                };
                Node* q = head;
                q = q->next;
                p->next = q;
                delete head;
                head = q;
            }else{
                Node* follower = NULL;
                for(int i=0; i<pos-1; i++){
                    follower = p;
                    p = p->next;
                }
                follower->next = p->next;
                delete p;
            }
        }
};

int main(){
    int A[5] = { 1, 2, 3, 4, 5 };
    LinkedList LL1(A, 5);
    LL1.isLoop();
    LL1.displayCircular();
    LL1.insert(2,15);
    LL1.displayCircular();
    LL1.insert(0, 80);
    LL1.displayCircular();
    LL1.Delete(3);
    LL1.displayCircular();
    LL1.Delete(1);
    LL1.displayCircular();
}