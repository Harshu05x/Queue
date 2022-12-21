#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class Queue{
    Node *front;
    Node *rear;

    public: 
    Queue(){
        front = rear = nullptr;
    }
    ~Queue(){
        Node *p = this->front;
        while(front){
            front = front->next;
            delete p;
            p = front;
        }
    }
    void enqueue(int x);
    void dequeue();
    void display();
    bool isFull();
    bool isEmpty();

};
bool Queue :: isEmpty(){
    (this->front == nullptr) ? true : false ;
}
bool Queue :: isFull(){
    Node *t = new Node;
    (t == nullptr) ? true : false ; 
}

void Queue :: enqueue(int x){
    Node *t = new Node;
    if(t == nullptr) cout<<"Queue is full"<<endl;
    else {
        t->data = x;
        t->next = nullptr;
        if(this->front == nullptr) {this->front = t; this->rear = t;}
        else {
            this->rear->next = t;
            this->rear = t;
        }
    }
}

void Queue :: dequeue(){
    int x = -1;
    Node *p ;
    // if(!this->isEmpty()) cout<<"Queue is empty"<<endl;
    {
        p = this->front;
        this->front = this->front->next;
        x = p->data;
        delete p;
    }
    cout<<x<<" deleted"<<endl;
}

void Queue :: display(){
    Node *p = this->front;
    p = this->front;
    while(p) {
        cout<<p->data<<" ";
        p = p->next;
    }
}
int main()
{
    Queue q1;
    q1.enqueue(12);
    q1.enqueue(13);
    q1.enqueue(14);
    q1.enqueue(15);
    // q1.dequeue();
    // q1.dequeue();
    // q1.dequeue();
    // q1.dequeue();
    q1.dequeue();
    q1.display();
    return 0;
}