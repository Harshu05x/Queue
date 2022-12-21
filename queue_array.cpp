#include <iostream>
using namespace std;

class Queue{
    int size,front,rear;
    int *Q;

    public:
    Queue(){
        cout<<"Enter size: ";
        cin>>this->size;
        this->front = this->rear = -1;
        Q = new int[this->size];
    }
    void enqueue(int ele);
    void dequeue();
    int isEmpty(){ (this->front == this->rear) ? 1 : 0 ; };
    int isFull(){ (this->rear == this->size -1 ) ? 1 : 0 ; };
    int first();
    int last();
    friend void display(Queue *q);
};

void Queue :: enqueue(int ele){
    if(this->rear == this->size-1) cout<<"Queue is Full"<<endl;
    else {
        this->rear ++;
        this->Q[this->rear] = ele;
    }
}

void Queue :: dequeue(){
    int x = -1;
    if(this->front == this->rear) cout<<"Queue is empty"<<endl;
    else {
        this->front ++;
        x = this->Q[this->front];
        cout<<"Deleted ele: "<<x<<endl;
    }
}

void display(Queue *q){
    if(q->front == q->rear) cout<<"Queue is empty"<<endl;
    for(int i = q->front+1;i <= q->rear;i++){
        cout<<q->Q[i]<<" ";

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
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    // cout<<q1.isEmpty();
    // cout<<q1.isFull();
    display(&q1);
    return 0;
}