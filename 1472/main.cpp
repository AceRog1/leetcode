//
// Created by acerog on 14/09/24.
//

#include <iostream>
#include <string>
#include <utility>

using namespace std;

/**
 * Beats 80.49% in Runtime (108ms)
 * Beats 72.44% in Memory (62.02mb)
 */

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
    size_t toTail, toHead;
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
                size--;
                popNode->kill();
            }
            head = current;
            toHead = 0;
            head->next = nullptr;
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
            toTail = 0;
            toHead = size-1;
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
            toHead = 0;
            toTail = size-1;
        } else {
            for (int i = 0; i < steps; i++){
                current = current->next;
                toHead--;
                toTail++;
            }
        }
        return current->url;
    }
};

int main() {

    auto history1 = new BrowserHistory("leetcode.com");

    history1->visit("google.com");
    history1->visit("facebook.com");
    history1->visit("youtube.com");
    cout << history1->back(1) << " ";
    cout << history1->back(1) << " ";
    cout << history1->forward(1) << " ";
    history1->visit("linkedin.com");
    cout << history1->forward(2) << " ";
    cout << history1->back(2) << " ";
    cout << history1->back(7) << " ";

    delete history1;

    cout << endl;
    cout << endl;

    auto history2 = new BrowserHistory("rlglu.com");

    cout << history2->back(2) << " ";
    history2->visit("zxowmd.com");
    cout << history2->back(4) << " ";
    history2->visit("gbnssie.com");
    history2->visit("bqo.com");
    cout << history2->back(6) << " ";
    history2->visit("cq.com");
    history2->visit("pbh.com");
    cout << history2->back(5) << " ";
    history2->visit("ijt.com");
    history2->visit("tnsiso.com");
    cout << history2->back(7) << " ";
    history2->visit("xjxi.com");
    cout << history2->forward(3) << " ";
    cout << history2->forward(9) << " ";
    history2->visit("zlnx.com");
    cout << history2->forward(3) << " ";
    cout << history2->forward(7) << " ";

    delete history2;

    cout << endl;
    cout << endl;

    auto history3 = new BrowserHistory("jrbilt.com");

    history3->visit("uiza.com");
    cout << history3->forward(3) << " ";
    cout << history3->forward(3) << " ";
    history3->visit("fveyl.com");
    history3->visit("hyhqfqf.com");
    cout << history3->back(3) << " ";
    history3->visit("cccs.com");
    history3->visit("bivz.com");
    cout << history3->forward(6) << " ";
    cout << history3->back(1) << " ";
    history3->visit("cmbw.com");
    history3->visit("iywwwfn.com");
    history3->visit("sktbhdx.com");
    cout << history3->forward(8) << " ";
    cout << history3->forward(10) << " ";
    history3->visit("bskj.com");
    history3->visit("thw.com");
    cout << history3->back(6) << " ";
    history3->visit("hgesj.com");
    cout << history3->forward(6) << " ";
    history3->visit("ctb.com");
    history3->visit("fllnc.com");
    history3->visit("fs.com");
    cout << history3->back(7) << " ";

    delete history3;

    return 0;
}
