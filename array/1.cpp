// program to demonstrate operations on array

#include<iostream>
using namespace std;
int mid;
class Array{
    private:
        int size, length;
        int *A;
    public:
        Array( int s, int l){
            size = s;
            length = l;
            A = new int [size];
        };
        ~Array(){
            delete []A;
        };
        void display(){
            cout<<"Hey!! This is your array "<<endl;
            if(length == 0){
                cout<<"Which is empty :<"<<endl;
            };
            for(int i=0; i<length; i++){
                cout<<A[i]<<" ";
            }
            cout<<endl;
        };
        void fill(){
            cout<<"Enter the numbers "<<endl;
            for(int i=0; i<length; i++){
                cin>>A[i];
            };
        };
        void Delete() {
            int index;
            cout<<"Enter the index you want to delete "<<endl;
            cin>>index;
            for(int i = index; i<length-1; i++){
                A[i] = A[i+1];
            };
            length--;
        };
        void Insert(){
            int index, num;
            cout<<"Enter the index at which you want to insert"<<endl;
            cin>>index;
            cout<<"Enter the no to insert"<<endl;
            cin>>num;

            for(int i = length ; i > index; i--){
                A[i] = A[i-1];
            };
            A[index] = num;
            length++;
        };
        void linearSearch(){
            int key;
            cout<<"Enter the number you want to find"<<endl;
            cin>>key;
            for(int i=0; i<length; i++){
                if(A[i] == key){
                    cout<<key<<" found at "<<i<<endl;
                    return;
                }
                
            };
            cout<<key<<" not found :<"<<endl;
        };
        void binarySearch(){
            // condition :- Array should be sorted
            int key;
            cout<<"Enter the number you want to find"<<endl;
            cin>>key;

            int start =0, end = length-1, mid;
            while(start <= end){
                mid = (start + end)/2;
                if(key == A[mid]){
                    cout<<key<<" found at "<<mid;
                    return;
                } else if(key > mid){
                    start = mid +1;
                } else{
                    end = mid-1;
                }
            };
            cout<<key<<" not found :<"<<endl;
            /*Time Complexity = O(logn)*/
        };
        void R_binarySearch(int key, int start, int end){
            mid = (start + end)/2; 
            // base case
            if(end < start){
                cout<<key<<" not found"<<endl; 
                return;
            };
            if(key == A[mid]){
                cout<<key<<" found at "<<mid<<endl;
                return;
            }
            //recursive case
            else if(key > A[mid]){
                R_binarySearch(key, mid+1, end);
            } else {
                R_binarySearch(key, start, mid-1);
            };
            /*Time Complexity = O(logn)*/
        };
        void Get(){
            int index;
            cout<<"Enter the index you want to get"<<endl;
            cin>>index;
            
            cout<<A[index]<<" is present at index position "<<index<<endl;
        };
        void Set(){
            int index, num;
            cout<<"Enter the index you want to change"<<endl;
            cin>>index;
            cout<<"Enter the number"<<endl;
            cin>>num;

            A[index] = num;

            display();
        };
        void Sum(){
            int sum = 0;
            for(int i=0; i<length; i++){
                sum = sum + A[i];
            };
            cout<<"Sum of the array is :- "<<sum<<endl;
            return;
        };
        void Max(){
            int max = A[0];
            for(int i=0; i<length; i++){
                if(A[i] > max){
                    max = A[i];
                };
            };
            cout<<"The number with maximum value in this array is :- "<<max<<endl;
            return;
        };
        void Min(){
            int min = A[0];
            for(int i=0; i< length; i++){
                if(A[i] < min){
                    min = A[i];
                };
            };
            cout<<"The number with minimum value in this array is :- "<<min<<endl;
            return;
        };
        void Average(){
            int sum = 0;
            for(int i=0; i<length; i++){
                sum = sum + A[i];
            };
            cout<<"Average number of the array is :- "<< (float)sum/length<<endl;
            return;
        };
        void Reverse1(){ // extra array is required
            int *B = new int [length];
            for(int i = length-1, j=0; i>=0; i--, j++){
                B[j] = A[i];  // copying all element of A from back to front of B
            };
            for(int i=0; i<length; i++){
                A[i] = B[i]; // copying all element of B to A both from front to back
            };
            delete []B;
        };
        void Reverse2(){
            for(int i=0, j=length-1; i<= j; i++, j--){
                swap(A[i],A[j]);
            }
        };
        void LeftShift1(){
            // Eg:- 1 2 3 4 5 => 2 3 4 5 0
            for(int i = 1; i < length; i++ ){
                A[i-1] = A[i];
            };
            A[length-1] = 0;
        };
        void LeftShift2(){
            int num;
            cout<<"Enter the number by which you want to left shift the array :-"<<endl;
            cin>>num;

            // 1 2 3 4 5 => 3 4 5 0 0
            for(int i = 0; i < length-num; i++){
                A[i] = A[i+num];
            };
            for(int i = length-num; i<length; i++){
                A[i] = 0;
            }
        };
        void LeftRotate1(){
            int temp;
            temp = A[0];
            for(int i = 1; i<length; i++){
                A[i-1] = A[i];
            };
            A[length-1] = temp;
        };
        void LeftRotate2(){
            // 1 2 3 4 5 => 4 5 1 2 3 (num = 3)
            int num;
            cout<<"Enter the number by which you want to left rotate the array :-"<<endl;
            cin>>num;

            num = num%length;

            int* temp = new int[num];
            for(int i=0; i<num; i++){
                temp[i] = A[i]; // copy num elements from A to temp to put at the end
            };
            for(int i=num;i<length;i++){
                A[i-num] = A[i]; // copy element to front of A
            };
            for(int i=0; i<num; i++){
                A[length-num+i] = temp[i];
            };
            delete []temp;
        };
        void isSorted(){
            for(int i=0; i<length-1; i++){
               if(A[i+1] < A[i]){
                cout<<"Array is not sorted peeps :<"<<endl;
                return;
               } 
            }
            cout<<"Array is sorted!! Wohho :>"<<endl;
        };
        void MergeUnsorted(){
            
            int bs, bl;
            cout<<"Enter the size of second array "<<endl;
            cin>>bs;
            
            cout<<"Enter the length of second array "<<endl;
            cin>>bl;

            Array B(bs, bl);
            B.fill();
            B.display();

            Array C(length+B.length, length+B.length);
            for(int i=0; i<length; i++){
                C.A[i] = A[i];
            };
            for(int i=0; i<B.length;i++){
                C.A[length+i] = B.A[i];
            };
            cout<<"Merged array"<<endl;
            C.display();
        };
        void MergeSorted(){
            int bs, bl;
            cout<<"Enter the size of second array "<<endl;
            cin>>bs;
            
            cout<<"Enter the length of second array "<<endl;
            cin>>bl;

            Array B(bs, bl);
            B.fill();
            B.display();

            Array C(length+B.length, length+B.length);
            
            int i=0, j=0, k=0;
            while(i<length && j<B.length){
                if(A[i] < B.A[j]){
                    C.A[k] = A[i];
                    i++;
                    k++;
                } else if(A[i] == B.A[j]) {
                    C.A[k] = A[i];
                    k++;
                    C.A[k] = B.A[j];
                    i++;
                    j++;
                    k++;
                    
                } else{
                    C.A[k] = B.A[j];
                    j++;
                    k++;
                }
            }
            if(i>=length){
                while(j<B.length){
                    C.A[k] = B.A[j];
                    k++;
                    j++;
                }
            } else{
                while (i<length){
                    C.A[k] = A[i];
                    i++;
                    k++;
                }   
            };
            cout<<"Sorted Merged Array"<<endl;
            C.display();
            C.~Array();
            B.~Array();
        };
        void UnionUnsorted(){
            /* TIME COMPLEXITY = O(n^2) */
            int bs, bl;
            cout<<"Enter the size of second array "<<endl;
            cin>>bs;
            
            cout<<"Enter the length of second array "<<endl;
            cin>>bl;

            Array B(bs, bl);
            B.fill();
            B.display();

            Array C(length+B.length, length);

            for(int i=0; i<length; i++){
                C.A[i] = A[i]; // copy all the elements of A to C
            };
            int j;
            for(int i=0; i<B.length; i++){
                for(j=0; j<C.length; j++){
                    if(B.A[i] == C.A[j]){
                        break;
                    }
                };
                if(j == C.length){
                    C.length++;
                    C.A[j] = B.A[i];
                }
            }

            C.display();
            C.~Array();
            B.~Array();
        };
        void UnionSorted(){
            /* TIME COMPLEXITY = O(n)*/
            int bs, bl;
            cout<<"Enter the size of second array "<<endl;
            cin>>bs;
            
            cout<<"Enter the length of second array "<<endl;
            cin>>bl;

            Array B(bs, bl);
            B.fill();
            B.display();

            Array C(length+B.length, length+B.length);
            int i=0, j=0, k=0;
            while( i < length && j < B.length ){
                if( A[i] < B.A[j] ){
                    C.A[k] = A[i];
                    i++;
                    k++;
                } else if( B.A[j] < A[i] ){
                    C.A[k] = B.A[j];
                    j++;
                    k++;
                } else{
                    C.A[k] = A[i];
                    i++;
                    j++;
                    k++;
                }
            }
            if( i >= length){
                while( j < B.length ){
                    C.A[k] = B.A[j];
                    k++;
                    j++;
                }
            } else{
                while( i < length ){
                    C.A[k] = A[i];
                    k++;
                    i++;
                }
            }

            C.display();
        };
        void IntersectionUnsorted(){
            /* TIME COMPLEXITY = O(n^2) */
            int bs, bl;
            cout<<"Enter the size of second array "<<endl;
            cin>>bs;
            
            cout<<"Enter the length of second array "<<endl;
            cin>>bl;

            Array B(bs, bl);
            B.fill();
            B.display();

            Array C(length+B.length, 0);
            int k=0;
            for(int i=0; i<length; i++){
                for(int j=0; j<B.length; j++){
                    if( A[i] == B.A[j] ){
                        C.length++;
                        C.A[k] = A[i];
                        k++;
                        break;
                    }
                }
            }

            C.display();
        };
        void IntersectionSorted(){
            /* TIME COMPLEXITY = O(n) */
            int bs, bl;
            cout<<"Enter the size of second array "<<endl;
            cin>>bs;
            
            cout<<"Enter the length of second array "<<endl;
            cin>>bl;

            Array B(bs, bl);
            B.fill();
            B.display();

            Array C(length+B.length, 0);

            int i=0, j=0, k=0;
            while(i<length && j<B.length){
                if(A[i] < B.A[j]){
                    i++;
                }else if( B.A[j] < A[i] ){
                    j++;
                } else{
                    C.length++;
                    C.A[k] = A[i];
                    i++;
                    j++;
                    k++;
                }
            }

            C.display();
        };
        void DifferenceUnsorted(){
            /* TIME COMPLEXITY = O(n^2) */
            // A-B all element of A that are not in B
            int bs, bl;
            cout<<"Enter the size of second array "<<endl;
            cin>>bs;
            
            cout<<"Enter the length of second array "<<endl;
            cin>>bl;

            Array B(bs, bl);
            B.fill();
            B.display();

            Array C(length+B.length, 0);
            int k=0, j;
            for(int i=0; i<length; i++){
                for(j=0; j<B.length; j++){
                    if(A[i] == B.A[j]){
                        break;
                    }
                }
                if(j == B.length){
                    C.length++;
                    C.A[k] = A[i];
                    k++;
                }
            }

            C.display();
        };
        void DifferenceSorted(){
            /* TIME COMPLEXITY = O(n) */
            // A-B all element of A that are not in B
            int bs, bl;
            cout<<"Enter the size of second array "<<endl;
            cin>>bs;
            
            cout<<"Enter the length of second array "<<endl;
            cin>>bl;

            Array B(bs, bl);
            B.fill();
            B.display();

            Array C(length+B.length, 0);
            int i=0, j=0, k=0;
            while( i < length){
                if( A[i] > B.A[j] ){
                    j++;
                } else if( B.A[j] < A[i] ){
                    C.length++;
                    C.A[k] = A[i];
                    i++;
                    k++;
                } else{
                    i++;
                    j++;
                }
            }

            C.display();
        };
};

int main(){
    int size, length;
    cout<<"Enter the size of array "<<endl;
    cin>>size;
    
    cout<<"Enter the length of array "<<endl;
    cin>>length;

    Array A(size, length);
    
    A.fill();
    A.display();

    cout<<"Hey!! Here are all the operations you can do :-"<<endl;
    cout<<"1.   "<<"Delete"<<endl;
    cout<<"2.   "<<"Insert"<<endl;
    cout<<"3.   "<<"linearSearch"<<endl;
    cout<<"4.   "<<"binarySearch"<<endl;
    cout<<"5.   "<<"Get"<<endl;
    cout<<"6.   "<<"Set"<<endl;
    cout<<"7.   "<<"Sum"<<endl;
    cout<<"8.   "<<"Max"<<endl;
    cout<<"9.   "<<"Min"<<endl;
    cout<<"10.  "<<"Average"<<endl;
    cout<<"11.  "<<"Reverse1"<<endl;
    cout<<"12.  "<<"Reverse2"<<endl;
    cout<<"13.  "<<"LeftShift1"<<endl;
    cout<<"14.  "<<"LeftShift2"<<endl;
    cout<<"15.  "<<"LeftRotate"<<endl;
    cout<<"16.  "<<"LeftRotate2"<<endl;
    cout<<"17.  "<<"isSorted"<<endl;
    cout<<"18.  "<<"MergeUnsorted"<<endl;
    cout<<"19.  "<<"MergeSorted"<<endl;
    cout<<"20.  "<<"UnionUnsorted"<<endl;
    cout<<"21.  "<<"UnionSorted"<<endl;
    cout<<"22.  "<<"IntersectionUnsorted"<<endl;
    cout<<"23.  "<<"IntersectionSorted"<<endl;
    cout<<"24.  "<<"DifferenceUnsorted"<<endl;
    cout<<"25.  "<<"DifferenceSorted"<<endl;
    cout<<"26.  "<<"Display"<<endl;
    cout<<"27.  "<<"End"<<endl;

    int choice=0;
    while(choice < 27){
        cout<<"Enter your instruction number :-"<<endl;
        cin>>choice;
        switch(choice){
            case 1: A.Delete();
                break;
            case 2: A.Insert(); 
                break;
            case 3: A.linearSearch();
                break;
            case 4: A.binarySearch();
                break;
            case 5: A.Get(); 
                break;
            case 6: A.Set(); 
                break;
            case 7: A.Sum(); 
                break;
            case 8: A.Max(); 
                break;
            case 9: A.Min(); 
                break;
            case 10: A.Average();
                break;
            case 11: A.Reverse1(); 
                break;
            case 12: A.Reverse2(); 
                break;
            case 13: A.LeftShift1(); 
                break;
            case 14: A.LeftShift2(); 
                break;
            case 15: A.LeftRotate1(); 
                break;
            case 16: A.LeftRotate2(); 
                break;
            case 17: A.isSorted(); 
                break;
            case 18: A.MergeUnsorted(); 
                break;
            case 19: A.MergeSorted(); 
                break;
            case 20: A.UnionUnsorted(); 
                break;
            case 21: A.UnionSorted(); 
                break;
            case 22: A.IntersectionUnsorted();
                break;
            case 23: A.IntersectionSorted(); 
                break;
            case 24: A.DifferenceUnsorted();
                break;
            case 25: A.DifferenceSorted();
                break;
            case 26: A.display();
                break;
        }
    }
    
}