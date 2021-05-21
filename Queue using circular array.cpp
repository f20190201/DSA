// Idea is to bring the rear pointer back to the first array index using modulo, after reaching the last array index.[definition of circular]

#define SIZE 10
int front = -1;
int rear = -1;

bool isEmpty(){
    if((front == -1) && (rear == -1))
        return true;
    return false;
}

void enqueue( int val){
    if((rear+1)%size == front)
        cout<<"Queue is full\n";
    
    else{
        if(front == -1)
            front++;
        rear = (rear+1)%size;
        arr[rear] = value;
    }
    return;
}

void dequeue(){
    if(isEmpty())
        cout<<"Queue is empty\n";
        
    else{
        if(front==rear)
            front=rear=-1;
        else{
            front = (front+1)%size;
        }
    }
    return;
}

