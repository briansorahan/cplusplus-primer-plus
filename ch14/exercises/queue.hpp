#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstddef>

template <typename T>
class Queue {
private:
    enum {
        QSIZE = 10
    };

    struct Node {
        T item;
        struct Node * next;
    };

    Node * first;
    Node * last;
    int items;
    const int qsize;
public:
    Queue(int qs = QSIZE)
        : qsize(qs), items(0), first(NULL), last(NULL) {}
    ~Queue() {}
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const T & t);
    bool dequeue(T & t);
};

template <typename T>
bool Queue<T>::isempty() const {
    return items == 0;
}

template <typename T>
bool Queue<T>::isfull() const {
    return items == qsize;
}

template <typename T>
int Queue<T>::queuecount() const {
    return items;
}

template <typename T>
bool Queue<T>::enqueue(const T & item) {
    if (isfull()) {
        return false;
    }

    Node * add = new Node;
    add->item = item;
    add->next = NULL;
    items++;

    if (first == NULL) {
        first = add;
    } else {
        last->next = add;
    }

    last = add;
    return true;
}

template <typename T>
bool Queue<T>::dequeue(T & item) {
    if (isempty()) {
        return false;
    }

    item = first->item;
    items--;
    Node * temp = first;
    first = first->next;
    delete temp;
    if (items == 0) {
        last = NULL;
    }
    return true;
}

#endif
