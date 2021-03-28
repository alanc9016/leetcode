#include <iostream>
#include <climits>

class Node {
public:
    int x;
    Node *next;
};

class LinkedList {
public:
    LinkedList()
        : head(nullptr) {}
    int size();
    bool empty();
    void push_front(int);
    int pop_front();
    void push_back(int);
    int pop_back();
    int front();
    int back();
    void erase(int);
    void reverse();
private:
    Node *head;
};

class Queue {
public:
    void enqueue(int);
    int dequeue();
    bool empty();
private:
    LinkedList list;
};

int main() {
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.empty() << std::endl;
}

void Queue::enqueue(int x) {
    if (list.empty())
        list.push_front(x);
    else 
        list.push_back(x);
}

int Queue::dequeue() {
    if (list.empty()) {
        std::cout << "(full) ERROR\n";
        return INT_MIN;
    }
    else 
        return list.pop_front();
}

bool Queue::empty() {
    return list.empty();
}

int LinkedList::size() {
    int res = 0;
    for (Node *temp = head; temp != nullptr; temp = temp->next) 
        res++;
    return res;
}

bool LinkedList::empty() {
    return head == nullptr;
}

void LinkedList::push_front(int x) {
    Node *new_node = new Node;
    new_node->x = x;
    new_node->next = nullptr;
    if (head == nullptr) {
        head = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
}

int LinkedList::pop_front() {
    int res = -1;
    if (head != nullptr) {
        res = head->x;
        head = head->next;
    }

    return res;
}

void LinkedList::push_back(int x) {
    Node *new_node = new Node;
    new_node->x = x;
    new_node->next = nullptr;
    if (head == nullptr) {
        head = new_node;
    } else {
        Node *temp = head;
        Node *prev = temp;

        while (temp != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = new_node;
    }
}

int LinkedList::pop_back() {
    int res = -1;
    if (head != nullptr) {
        Node *temp = head;
        Node *prev = temp;
        Node *next = head->next;
        
        if (next == nullptr) {
            res = head->x;
            head = nullptr;
        }

        while (next != nullptr) {
            prev = temp;
            temp = temp->next;
            next = next->next;
        }
        res = temp->x;
        prev->next = nullptr;
    }

    return res;
}

int LinkedList::front() {
    if (head == nullptr)
        return -1;
    return head->x;
}

int LinkedList::back() {
    if (head == nullptr)
        return -1;
    Node *temp = head;

    while (temp->next != nullptr)
        temp = temp->next;
    return temp->x;
}

void LinkedList::erase(int x) {
    if (head == nullptr)
        return;

    if (head->x == x) {
        head = head->next;
        return;
    }

    Node *prev = head;
    Node *temp = head;

    while (temp != nullptr) {
        if (temp->x == x) 
            prev->next = temp->next;
        prev = temp;
        temp = temp->next;
    }
}

