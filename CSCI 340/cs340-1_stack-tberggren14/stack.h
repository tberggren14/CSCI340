
#ifndef STACK_H
#define STACK_H
#include <queue>
using namespace std;

class Stack
{
private:
    std::queue<int> q1, q2;

public:
    bool empty() const;
    int size() const;
    int top();
    void push(const int &val);
    void pop();
};

#endif // STACK_H
