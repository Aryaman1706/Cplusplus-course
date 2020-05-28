// program to demonstrate basic functions in LL
/*
A[5] = { 1, 2, 3, 4, 5 }
*/
#include<iostream>
#include<climits>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

Node* head=NULL; // why here? because to display we nee head pointer and it should be available in main it gives us the starting of LL
Node* last=NULL; 

void create(int A[], int n){
    Node* current = NULL;
    Node* tail = NULL;

    head = new Node();
    head->data = A[0];
    head->next = NULL;
    tail = head;

    for(int i=1; i<n; i++){
        current = new Node;
        current->data = A[i];
        current->next = NULL;
        tail->next = current;
        tail = current;
    }
};
void display(Node* ptr){
    while( ptr != NULL){
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }
    cout<<"NULL"<<endl;
};
void count(Node* ptr){
    int count = 0;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    };
    cout<<"Total no of elements in LL is:- "<<count<<endl;
};
void sum(Node * ptr){
    int sum =0;
    while(ptr != NULL){
        sum = sum + ptr->data;
        ptr = ptr->next;
    }
    cout<<"Sum of all the elements in LL is :- "<<sum<<endl;
};
void max(Node *ptr){
    int max = INT32_MIN;
    while(ptr != NULL){
        if(ptr->data > max){
            max = ptr->data;
        };
        ptr = ptr->next;
    };
    cout<<"Maximum element in LL is :- "<<max<<endl;
};
void linearSearch(Node *ptr, int key){ // binary search can not be implemented in LL as we can not access middle of LL directly
    while( ptr != NULL ){
        if( ptr->data == key ){
            cout<<"Key found at address "<<ptr<<endl;
            cout<<"value at address "<<ptr<<" = "<<ptr->data<<endl;
            return;    
        }
        ptr = ptr->next;
    }
    cout<<"Key not found"<<endl;
};
// Improving linear search
/*
Now i want that when i search for same key again, it should be found faster
so, i would move the node to starting
*/
void improved_ls(Node *ptr, int key){
    Node * follower = NULL;
    while( ptr != NULL ){
        if( ptr->data == key ){
            cout<<"Key found at address "<<ptr<<endl;
            cout<<"value at address "<<ptr<<" = "<<ptr->data<<endl;

            // move this node to front
            follower->next = ptr->next;
            ptr->next = head;
            head = ptr;
            return;
        }
        follower = ptr;
        ptr = ptr->next;
    }
};
/*
LL->  1 -> 2 -> 3 -> 4 -> 5 -> NULL
pos-> 1    2    3    4    5
*/
void insert(Node *ptr, int pos, int value){
    // code will work for all cases except for pos 0
    Node * newNode = new Node();
    newNode->data = value;
    if(pos == 0){    
        newNode->next = head;
        head = newNode;
    }else{
        for(int i=0; i<pos-1; i++){
            ptr= ptr->next;
        };
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
};
void insertAtLast(int value){
    Node * newNode = new Node();
    newNode->data = value;    
    newNode->next = NULL;
    if( head == NULL){
        last = head = newNode;
    } else{
        last->next = newNode;
        last = newNode;
    }  
};
void insertInSorted(Node *ptr, int value){
    Node* follower=NULL;
    Node* newNode= new Node;
    newNode->data = value;
    if(head == NULL){ // if there is no node initially then
        head = newNode;
    }else{
        while(ptr != NULL && ptr->data < value){
            follower = ptr; // moving follower and ptr till we reach the end or
            ptr= ptr->next; // find the ptr such that ptr->data > value
        } if ( ptr == head ){
            newNode->next = ptr;
            head = newNode;
        } else{
            newNode->next = follower->next;
            follower->next = newNode;

        }
    }
};
void isSorted(Node * ptr){
    int temp = INT32_MIN; // this is to store the value of ptr->data
    while(ptr != NULL){
        if( ptr->data < temp ){
            cout<<"Not sorted"<<endl;
            return;
        }
        temp = ptr->data;
        ptr = ptr->next;
    }
    cout<<"Sorted"<<endl;
};
void deleteElement(Node*ptr, int pos){
    int temp = 0;
    Node* follower = NULL;
    if(pos == 1){
        // delete first node
        temp = ptr->data;
        head = ptr->next;
        delete ptr;         
        cout<<"Node with data = "<<temp<<" was deleted"<<endl;
        return;
    } else{
        for(int i=0; i<pos-1; i++){
            follower = ptr;
            ptr= ptr->next;
        }
        follower->next = ptr->next;
        temp = ptr->data;
        delete ptr;
        cout<<"Node with data = "<<temp<<" was deleted"<<endl;
        return;
    }
};
void RemoveDuplicates(Node *ptr){ // will work only in sorted
    Node* follower = new Node;
    follower->data = NULL; // why this?
    follower->next = NULL; // because we need something to compare with at first
    while(ptr != NULL){
        if( follower->data != ptr->data || follower->data == NULL ){
            follower = ptr;
            ptr = ptr->next;
        } else{
            follower->next = ptr->next;
            free(ptr);
            ptr = follower->next;
        }
    }
};
void Reverse(Node *p){
    Node* q = NULL;
    Node* r = NULL;
    while( p != NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    };
    head = q;
};

/*****************************************************************************************/

// Recursive functions
void Rdisplay(Node* ptr){
    // base case
    if(ptr == NULL){
        cout<<"NULL"<<endl;
        return;
    };
    // recursive case
    cout<<ptr->data<<" -> ";
    Rdisplay(ptr->next);
    
    // Try this:-
    // Rdisplay(ptr->next);
    // cout<<ptr->data<<" -> ";
    
};
int Rcount(Node* ptr){
    static int count = 0;
    // base case
    if(ptr == NULL){
        return 0;
    }
    // recursive case
    return Rcount(ptr->next) + 1;
};
int Rsum(Node *ptr){
    static int sum =0;
    // base case
    if(ptr == NULL){
        return 0;
    }
    // recursive case
    return Rsum(ptr->next) + ptr->data;
};
int Rmax(Node * ptr){
    static int max, temp;
    // base case
    if(ptr == NULL){
        return INT32_MIN;
    }
    // recursive case
    temp = Rmax(ptr->next);
    if( ptr->data > temp){
        return ptr->data;
    } else{
        return temp;
    }
};
void RecReverse(Node * p, Node *q){
    if( p != NULL){
        RecReverse(p->next, p);
        p->next = q;
    } else {
        head = q;
    }
}

/*****************************************************************************************/

int main(){
    // int A[5] = { 1, 2, 3, 4, 5 };
    // create(A, 5);
    insertAtLast(1);
    insertAtLast(5);
    insertAtLast(5);
    insertAtLast(7);
    insertAtLast(8);
    insertAtLast(8);
    insertAtLast(9);
    display(head);
    RecReverse(head, NULL);
    display(head);
}