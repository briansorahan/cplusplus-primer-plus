// modified Stack template

#ifndef STACKP1_H
#define STACKP1_H

template <class T>
class Stack {
private:
    enum {
        SIZE = 10
    };
    int stacksize;
    T * items;
    int top;
public:
    explicit Stack(int ss = SIZE);
    Stack(const Stack & st);
    ~Stack() { delete [] items; }
    bool isempty() { return top == 0; }
    bool isfull() { return top == stacksize; }
    bool push(const T & item);
    bool pop(T & item);
    Stack & operator=(const Stack & st);
};

template <typename T>
Stack<T>::Stack(int ss) : stacksize(ss), top(0) {
    items = new T[stacksize];
}

template <typename T>
Stack<T>::Stack(const Stack & st) {
    stacksize = st.stacksize;
    top = st.top;
    items = new T[stacksize];
    for (int i = 0; i < top; i++) {
        items[i] = st.items[i];
    }
}

template <typename T>
bool Stack<T>::push(const T & item) {
    if (this->isfull()) {
        return false;
    } else {
        items[top++] = item;
        return true;
    }
}

template <typename T>
bool Stack<T>::pop(T & item) {
    if (this->isempty()) {
        return false;
    } else {
        item = items[--top];
        return true;
    }
}

template <typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> & st) {
    if (this == &st)
        return *this;
    delete [] items;
    stacksize = st.stacksize;
    top = st.top;
    items = new T[stacksize];
    for (int i = 0; i < top; i++) {
        items[i] = st.items[i];
    }
    return *this;
}

#endif
