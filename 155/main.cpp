#include <iostream>

using namespace std;

class MinStack {
public:
    struct Node{
        int val;
        Node* next;
        Node(){
            next = nullptr;
        }
        Node(int data){
            val = data;
            next = nullptr;
        }
        void killself(){
            next = nullptr;
            delete this;
        }
    };
    int min;
    int size;
    Node* head;
    MinStack() { // Inicializar el Stack
        min = 0;
        size = 0;
        head = nullptr;
    }

    void push(int val) { // push element

    }

    void pop() { // delete element

    }

    int top() { // gets the top element

    }

    int getMin() { // gets the min element

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
