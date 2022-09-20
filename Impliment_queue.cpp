// T.C-> O(1)
// S.C-> O(N)
#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int f;
    int rear;
    int size;
public:
    Queue() {
        size=10001;
        arr=new int[size];
        f=0;
        rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(f== rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data) {
       if(rear==size){
           cout<<"queue is full"<<endl;
       }
        else{
        arr[rear]=data;
        rear++;
        }
    }

    int dequeue() {
         if(isEmpty()){
             return -1;
         }
        else{
       int ans=arr[f];
        arr[f]=-1;
            f++;
        if(f==rear){
            f=0;
            rear=0;
        }
          return ans;
        }

    }

    int front() {
          if(isEmpty()){
              return -1;
          }
        else{
            return arr[f];
        }
    }
};