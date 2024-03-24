#include <iostream>

// struct
struct QueueNode {
    int data;
    QueueNode* next;
    QueueNode(int d) : data(d), next(nullptr) {}
};

// define struct
class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // enqueue
    void enqueue(int data) {
        QueueNode* newNode = new QueueNode(data);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // dequeue
    int dequeue() {
        if (front == nullptr) {
            std::cerr << "Queue is empty" << std::endl;
            exit(EXIT_FAILURE);
        }
        int data = front->data;
        QueueNode* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return data;
    }

    // empty queue
    bool isEmpty() {
        return front == nullptr;
    }

    // print queue
    void printQueue() {
        QueueNode* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // free
    ~Queue() {
        while (front != nullptr) {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};

// main function 
int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Queue: ";
    queue.printQueue();

    std::cout << "Dequeued element: " << queue.dequeue() << std::endl;
    std::cout << "Dequeued element: " << queue.dequeue() << std::endl;

    std::cout << "Queue after dequeue: ";
    queue.printQueue();

    return 0;
}
