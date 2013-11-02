// Queue template with a nested class

#ifndef QUEUETP_HPP
#define QUEUETP_HPP

template <class Item>
class QueueTP {
private:
    enum { Q_SIZE = 10 };
    class Node {
    public:
        Item item;
        Node * next;
        Node(const Item & i) : item(i), next(0) {}
    };
    Node * first;
    Node * last;
    int items;
    const int qsize;
    QueueTP(const QueueTP & q) : qsize(0) {}
    QueueTP & operator=(const QueueTP & q) { return *this; }
public:
    QueueTP(int qs = Q_SIZE);
    ~QueueTP();
    bool isempty() const { return items == 0; }
    bool isfull() const { return items == qsize; }
    int queuecount() const { return items; }
    bool enqueue(const Item & item);
    bool dequeue(Item & item);
};

template <class Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs) {
    first = last = nullptr;
    items = 0;
}

template <class Item>
QueueTP<Item>::~QueueTP() {
    Node * temp;
    while (first != nullptr) {
        temp = first;
        first = first->next;
        delete temp;
    }
}

// add item to queue
template <class Item>
bool QueueTP<Item>::enqueue(const Item & item) {
    if (isfull()) {
        return false;
    }

    Node * add = new Node(item);
    items++;

    if (first == 0) {
        first = add;
    } else {
        last->next = add;
    }

    last = add;
    return true;
}

// place first item into item variable and remove from queue
template <class Item>
bool QueueTP<Item>::dequeue(Item & item) {
    if (first == 0) {
        return false;
    }

    item = first->item;
    items--;

    Node * temp = first;
    first = first->next;
    delete temp;

    if (items == 0) {
        last = nullptr;
    }

    return true;
}

#endif
