#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int start;
    int end;
    int currSize;
    int maxSize;

public:
    Queue()
    {
        arr = new int[100];
        start = -1;
        end = -1;
        currSize = 0;
    }

    Queue(int maxSize)
    {
        (*this).maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }
    void push(int x)
    {
        if (currSize == maxSize)
        {
            cout << "Queue is Full" << endl;
        }
        exit(1);

        if (end == -1)
        {
            start = 0;
            end = 0;
        }
        else
        {
            end = (end + 1) % maxSize;
        }

        arr[end] = x;
        cout << " The Element is Pusshed" << endl;
        currSize++;
    }
    int pop()
    {
        if (start == -1)
        {
            cout << "Queue is Empty" << endl;
        }
        int popped = arr[start];
        if (currSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            start = (start + 1) % maxSize;
        }
        currSize--;
        return popped;
    }
    int top()
    {
        if (start == -1)
        {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }
    int size()
    {
        return currSize;
    }
};
int main()
{
    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);

    return 0;
}