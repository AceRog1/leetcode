#include <iostream>
#include <string>
#include <utility>

using namespace std;

class BrowserHistory {
private:
    struct Node{
        string url;
        Node* next;
        Node* prev;
        Node(){
            next = nullptr;
            prev = nullptr;
        }
        explicit Node(string newUrl){
            url = std::move(newUrl);
            next = nullptr;
            prev = nullptr;
        }
        void kill(){
            next = nullptr;
            prev = nullptr;
            delete this;
        }
    };
private:
    Node* head;
    Node* tail;
    Node* current;
    int toTail, toHead;
    size_t size;
public:
    BrowserHistory(string homepage) {
        Node* newSearch = new Node(std::move(homepage));
        head = newSearch;
        tail = newSearch;
        current = newSearch;
        size = 1;
        toHead = 0;
        toTail = 0;
    }

    void visit(string url) {
        if (current->next != nullptr){
            Node* temp = current->next;
            while (temp != nullptr){
                Node* popNode = temp;
                temp = temp->next;
                popNode->kill();
            }
            head = current;
            toHead = 0;
        }
        Node* newSearch = new Node(std::move(url));
        newSearch->prev = head;
        head->next = newSearch;
        head = newSearch;
        current = newSearch;
        size++;
        toTail++;
    }

    string back(int steps) {
        if (toTail < steps){
            current = tail;
        } else {
            for (int i = 0; i < steps; i++){
                current = current->prev;
                toHead++;
                toTail--;
            }
        }
        return current->url;
    }

    string forward(int steps) {
        if (toHead < steps){
            current = head;
        } else {
            for (int i = 0; i < steps; i++){
                current = current->next;
                toHead--;
                toTail++;
            }
        }
        return current->url;
    }

//    ~BrowserHistory(){
//        current = head;
//        head = nullptr;
//        tail = nullptr;
//        while (current != nullptr){
//            Node* popNode = current;
//            current = current->prev;
//            popNode->kill();
//        }
//    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main() {

    auto history = new BrowserHistory("leetcode.com");

    history->visit("google.com");
    history->visit("facebook.com");
    history->visit("youtube.com");
    cout << history->back(1) << " ";
    cout << history->back(1) << " ";
    cout << history->forward(1) << " ";
    history->visit("linkedin.com");
    cout << history->forward(2) << " ";
    cout << history->back(2) << " ";
    cout << history->back(7) << " ";

    delete history;



    return 0;
}
