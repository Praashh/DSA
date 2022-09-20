// T.C->O(1)

#include <bits/stdc++.h> 
class CircularQueue{
    vector<int>arr;
    int size;
    int front;
    int rear;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
         size=n;
        arr=vector<int>(size);
        front=-1;
        rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
       if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            
            return false; 
        } 
        else if (front == -1) { 
            // Queue is empty, hence insert the first element.
            front = rear = 0; 
            arr[rear] = value; 
        } 
       else if(rear==size-1 && front!=0){
           rear=0;
           arr[rear]=value;
       }
        else{
            rear++;
          arr[rear]=value;
        }
//         arr[rear]=value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
         if(front==-1 && rear==-1){
             return -1;
         }
        int ans=arr[front];
        arr[front]=-1;
        if(front == rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
        return ans;
    }
};