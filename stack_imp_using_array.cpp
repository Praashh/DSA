#include <iostream>
using namespace std;
class MyStack
{
public:
    int arr[10];
    int top = -1;
    void push(int x)
    {
        if (top < 10)
        {
            top++;
            arr[top] = x;
        }
        else
        {
            cout << "Stack is Full" << endl;
        }
    }
    void peek()
    {
        if (top > -1)
        {
            cout << arr[top] << endl;
        }
        else
        {
            cout << "Stack have no element" << endl;
        }
    }
    int size()
    {
        return top + 1;
    }
    void pop()
    {
        if (top > -1)
        {
            top--;
            top = arr[top];
        }
        else
        {
            cout << "Can not perform this operation" << endl;
        }
    }
    bool Isempty()
    {
        if (top > -1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    bool Isfull()
    {
        if (top ==-1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
int main()
{
    MyStack s;
    s.push(21);
    s.push(2);
    s.push(23);
    s.push(3);
    s.push(20);
    s.peek();
    s.pop();
    s.peek();
    cout<<s.Isempty()<<endl;
    cout<<s.Isfull()<<endl;
    // s.peek();
    // cout<<s.size();

    return 0;
}