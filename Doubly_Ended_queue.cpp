// In Doubly Ended Queue We can do pop_back(),pop_front() and push_back(data),push_front(data) operations
#include<iostream>
#include<queue>
using namespace std;
int main(){

    deque<int>q;
    q.push_front(12);
    q.push_back(14);
    cout<<"Front Element is:"<<q.front()<<endl;
    cout<<"Back Element is:"<<q.back()<<endl;
      
      q.pop_front();

    cout<<"Front Element is:"<<q.front()<<endl;
    cout<<"Back Element is:"<<q.back()<<endl;

    q.pop_back();

    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }

    return 0;
}
