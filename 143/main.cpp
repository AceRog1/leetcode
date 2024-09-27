//
// Created by acerog on 27/09/24.
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/**
 * Beats 92.25% in Runtime (21ms)
 * Beats 27.44% in Memory (23.47mb)
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
        stack<ListNode*> stk;
        queue<ListNode*> qeu;
        while (tempBack != nullptr){
            if (cont < half){
                qeu.push(tempFront);
                tempFront = tempFront->next;
                tempBack = tempBack->next;
            } else {
                stk.push(tempBack);
                tempBack = tempBack->next;
            }
            cont++;
        }
        ListNode *temp = head;
        while(!stk.empty() || !qeu.empty()){
            if (!qeu.empty()){
                if (temp == nullptr && head == nullptr){
                    head = qeu.front();
                    temp = qeu.front();
                } else {
                    temp->next = qeu.front();
                    temp = qeu.front();
                }
                qeu.pop();
            }
            if (!stk.empty()){
                temp->next = stk.top();
                temp = stk.top();
                stk.pop();
            }
        }
        temp->next = nullptr;
    }
};

int main() {

    Solution sol;

    // test 1 y 2
    auto *head = new ListNode(1);
    auto *node2 = new ListNode(2);
    auto *node3 = new ListNode(3);
    auto *node4 = new ListNode(4);
    auto *node5 = new ListNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

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
    delete node5;

    return 0;
}
