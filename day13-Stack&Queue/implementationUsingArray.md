# Implementation of Stack And Queue using Array 
## Stack
```cpp
#include<iostream>
using namespace std;
class stack{
    int size;
    int top;
    int *a;
    public:
    stack(int size){
        this->size=size;
        top=-1;
        a=new int[size];
    }
    void push(int);
    int pop();
    void display();
    int isFull();
    int isEmpty();
    int peek();
};

// Time : O(1)
// space : O(1) 
void stack::push(int x){
    if(top==size-1)
        cout<<"stack OVERFLOW\n";
    else
        a[++top]=x;    
}

// Time : O(1)
// space : O(1)
int stack::pop(){
    if(top<=-1){
        cout<<"stack UNDERFLOW\n";
        return -1;
    }
    return a[top--];
}

// Time : O(N)
// space : O(1)
void stack::display(){
    if(top==-1)
        cout<<"stack UNDERFLOW\n";
    else{
        cout<<"\n";
        for(int i=0;i<=top;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
}

// Time : O(1)
// space : O(1)
int stack::isFull(){
    return (top==size-1)?1:0;
}
int stack::isEmpty(){
    return (top==-1)?1:0;
}
int stack::peek(){
    if(top!=-1)
        return a[top];
    else return -1;
}
```

## Queue
```cpp
class circularQueue{
    int size;
    int *a;
    int rear,front;
    public: 
    circularQueue(int size){
        this->size=size;
        rear=front=-1;
        a=new int[size];
    }
    void encircularQueue(int);
    void decircularQueue();
    int first();
    int last();

};
// Time : O(1)
// space : O(1)
void circularQueue::encircularQueue(int x){
    if( (rear+1)%size==front)
        cout<<"circularQueue full\n";
    else{
        if(front==-1)
            front++;
        rear=(rear+1)%size;
        a[rear]=x;
    }
}
// Time : O(1)
// space : O(1)
void circularQueue::decircularQueue(){
        if(front==-1 )
            cout<<"circularQueue empty\n";    
        else if(front==rear)
            front=rear=-1;
        else
            front=(front+1)%size;
    }
// Time : O(1)
// space : O(1)
int circularQueue::first(){
    if(front==-1 )
        return -1;
    return a[front]; 
    }
// Time : O(1)
// space : O(1)
int circularQueue::last(){
    if(front==-1 )
        return -1;
    return a[rear];
    }
```

