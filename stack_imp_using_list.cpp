#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int x)// It will create a new node and data of node =x and node->next=NULL;
    {
        data = x;
        next = NULL;
    }
};
class MyStack
{
private:
    Node *top;// top pointer counts the number of element in stack

public:
    MyStack()
    {
        top = NULL;
    }
    void push(int x)
    {
        Node *temp = new Node(x);// create a new node 
        temp->next = top;// here top means the value in top pointer (NULL)
        top = temp;
    }
    void peek()
    {
        if (top != NULL)
        {
            cout << top->data << endl;
        }
        else
        {
            cout << "satck is empty" << endl;
        }
    }
    void pop()
    {
        if (top != nullptr)
        {
            top = top->next;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }
    bool Isempty()
    {

        if (top == NULL)
        {
            return 1;
        }
        else
        {

            return 0;
        }
    }
};
int main()
{
    MyStack s;
    s.push(10);
    s.push(1);
    s.push(19);
    s.peek();//19
    s.pop();
    s.peek();//1
    s.pop();
    s.peek();//10 
     s.pop();// stack empty
    s.peek();// it will show that stack is empty
    cout<< s.Isempty();
    return 0;
}
