#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(int A[], int n){
            Node* current = NULL;
            Node* last = NULL;

            head = new Node();
            head->data = A[0];
            head->next = head;
            head->prev = head;
            last = head;
            for(int i=1; i<n; i++){
                current = new Node();

                current->data = A[i];
                current->prev = last;
                current->next = NULL;
                
                last->next = current;
                last = current;
                last->next = head;
                head->prev = last;
            }
        };
        void Display(){
            Node * p = head;
            do{
                cout<<p->data<<" ~ ";
                p = p->next;
            } while(p != head);
            cout<<" Circle "<<endl;
        };
        void Insert(int pos, int value){
            Node* p = head;
            Node* newNode = new Node();
            newNode->data = value;
            if(pos == 0){
                newNode->next = p;
                newNode->prev = p->prev;
                p->prev->next = newNode;
                p->prev = newNode;
                head = newNode;
            }else{
                for(int i=0; i<pos-1; i++){
                    p = p->next;
                }
                newNode->next = p->next;
                newNode->prev = p;
                p->next->prev = newNode;
                p->next = newNode;
            }
        };
        void Delete(int pos){
            Node* p = head;
            if( pos == 1){
                p->next->prev = p->prev;
                p->prev->next = p->next;
                head = head->next;
                delete p;
            }else{
                for(int i=0; i<pos-1; i++){
                    p = p->next;
                }
                p->prev->next = p->next;
                p->next->prev = p->prev;
                delete p;
            }
        };
};
int main(){
    int A[5] = { 4, 6, 8, 9, 2};
    LinkedList LL(A, 5);
    LL.Display();
    
}