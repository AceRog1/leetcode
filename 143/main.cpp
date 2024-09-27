#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        size_t size = 0;
        ListNode *tempSize = head;
        while(tempSize != nullptr){
            size++;
            tempSize = tempSize->next;
        }
        size_t half = size/2;
        ListNode *tempFront = head;
        ListNode *tempBack = head;
        size_t cont = 0;
        stack<int> stk;
        queue<int> qeu;
        while (tempBack != nullptr){
            if (cont < half){
                qeu.push(tempFront->val);
                tempFront = tempFront->next;
                tempBack = tempBack->next;
            } else {
                stk.push(tempBack->val);
                tempBack = tempBack->next;
            }
            cont++;
        }
        while (head != nullptr){
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
        ListNode *temp = head;
        while(!stk.empty() || !qeu.empty()){
            if (!qeu.empty()){
                auto *newNode = new ListNode(qeu.front());
                if (temp == nullptr && head == nullptr){
                    head = newNode;
                    temp = newNode;
                } else {
                    temp->next = newNode;
                    temp = newNode;
                }
                qeu.pop();
            }
            if (!stk.empty()){
                auto *newNode = new ListNode(stk.top());
                temp->next = newNode;
                temp = newNode;
                stk.pop();
            }
        }
    }
};

int main() {

    Solution sol;

    auto *head = new ListNode(1);
    auto *node2 = new ListNode(2);
    auto *node3 = new ListNode(3);
    auto *node4 = new ListNode(4);
    //ListNode *node5 = new ListNode(5);
    //ListNode *node6 = new ListNode(6);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    sol.reorderList(head);

    ListNode *temp = head;
    while (temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }

    delete head;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
