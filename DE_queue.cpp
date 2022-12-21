#include <iostream>
using namespace std;

class DE_queue{
    int front,rear,size;
    int *Q;
    public:

    DE_queue(int size){ 
        this->size = size;
        front = rear = -1;
        Q = new int[size];
    }

    ~DE_queue(){ delete [] Q;}
    void display();
    void enqueueFront(int x);
    void enqueueRear(int x);
    void dequeueFront();
    void dequeueRear();
    bool isFull();
    bool isEmpty();
};

bool DE_queue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
} 
bool DE_queue::isFull() {
    if (rear == size - 1){
        return true;
    }
    return false;
}

void DE_queue :: enqueueFront(int x){
    if(front == -1) cout<<"DE_Queue Overflow\n";
    else {
        Q[front] = x;
        front -- ;
    }
}
void DE_queue :: enqueueRear(int x){
    if(isFull()) cout<<"DE_Queue Overflow\n";
    else{
        rear ++ ;
        Q[rear] = x;
    }
}

void DE_queue :: dequeueFront(){
    int x = -1;
    if(isEmpty()) cout<<"DE_Queue Underflow\n";
    else{
        front ++ ;
        x = Q[front];
    }
    cout<<x<<" deleted\n";
}

void DE_queue :: dequeueRear(){
    int x = -1;
    if(rear == -1) cout<<"DE_Queue Underflow\n";
    else {
        x = Q[rear];
        rear -- ;
    }
    cout<<x<<" deleted\n";
}

void DE_queue :: display(){
    if(front == rear) cout<<"DE_Queue is empty\n";
    else{ 
        for(int i=front+1;i<=rear;i++){
            cout<<Q[i]<<" ";
            if(i < rear ) cout<<"<-";
    }
    cout<<endl;}
}

int main()
{
    int A[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(A)/sizeof(A[0]);
    DE_queue d1(size);

    for(int i=0;i<size;i++) d1.enqueueRear(A[i]);
    d1.display();

    for(int i=0;i<size;i++) d1.dequeueFront();
    d1.display();

    int B[] = {2,4,6,8,20};
    size = sizeof(B)/sizeof(B[0]);
    for(int i=0;i<size;i++) d1.enqueueFront(B[i]);
    d1.display();

    for(int i=0;i<size;i++) d1.dequeueRear();
    d1.display();
    cout<<"\nThank You :)\n";
    return 0;
}