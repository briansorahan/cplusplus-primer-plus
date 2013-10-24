// a stack template

#ifndef __STACK_H
#define __STACK_H

template <typename T> class Stack {
private:
    enum {
        MAX = 10
    };
    T items[MAX];
    int top;
public:
    Stack();
    bool isempty();
    bool isfull();
    bool push(const T& item); // add item to stack
    bool pop(T& item);        // pop top into item
};

template <typename T> Stack<T>::Stack() {
    top = 0;
}

template <typename T> bool Stack<T>::isempty() {
    return top == 0;
}

template <typename T> bool Stack<T>::isfull() {
    return top == MAX;
}

template <typename T> bool Stack<T>::push(const T& item) {
    if (top < MAX) {
        items[top++] = item;
        return true;
    } else {
        return false;
    }
}

template <typename T> bool Stack<T>::pop(T& item) {
    if (this->isempty()) {
        return false;
    } else {
        item = items[--top];
        return true;
    }
}

#endif
