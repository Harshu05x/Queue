#include <iostream>
using namespace std;

class Queue{
    int size,front,rear;
    int *Q;

    public:
    Queue(){
        cout<<"Enter size: ";
        cin>>this->size;
        this->front = this->rear = 0;
        Q = new int[this->size];
    }
    ~Queue(){ delete []Q;}
    void enqueue(int ele);
    void dequeue();
    bool isEmpty();
    bool isFull();
    int first();
    int last();
    friend void display(Queue *q);
};

bool Queue :: isEmpty(){
    (this->front == this->rear) ? true : false ; 
}

bool Queue :: isFull(){
    ((this->rear + 1) % this->size == this->size ) ? true : false ;
}

void Queue :: enqueue(int ele){
    if(this->isFull()) cout<<"Queue is Full"<<endl;
    else {
        this->rear = (this->rear + 1) % this->size;
        this->Q[this->rear] = ele;
    }
}

void Queue :: dequeue(){
    int x = -1;
    if(this->isEmpty()) cout<<"Queue is empty"<<endl;
    else {
        this->front = (this->front + 1) % this->size;
        x = this->Q[this->front];
        cout<<"Deleted ele: "<<x<<endl;
    }
}

void display(Queue *q){
    {
        int i = q->front + 1;
        do{
            cout<<q->Q[i]<<" ";
            i = (i + 1) % q->size;
        }while(i != ((q->rear+1) % q->size));
    }
}

int main()
{
    Queue q1;
    int ele;
    // cout<<q1.isEmpty();
    // cout<<q1.isFull();
    cout<<"Enter ele: ";
    cin>>ele;
    q1.enqueue(ele);
    cout<<"Enter ele: ";
    cin>>ele;
    q1.enqueue(ele);
    cout<<"Enter ele: ";
    cin>>ele;
    q1.enqueue(ele);
    // q1.dequeue();
    // q1.dequeue();
    // q1.dequeue();
    cout<<"Enter ele: ";
    cin>>ele;
    q1.enqueue(ele);
    cout<<"Enter ele: ";
    cin>>ele;
    q1.enqueue(ele);

    cout<<"Enter ele: ";
    cin>>ele;
    q1.enqueue(ele);
    // cout<<q1.isEmpty();
    // cout<<q1.isFull();
    display(&q1);
    return 0;
}