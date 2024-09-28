//
// Created by acerog on 28/09/24.
//

#include <iostream>

using namespace std;

/**
 * Beats 69.68% in Runtime (598ms)
 * Beats 84.25% in Memory (299.65mb)
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
    ListNode* deleteMiddle(ListNode* head) {
        size_t size = 0;
        ListNode *tempCount = head;
        while (tempCount != nullptr){
            size++;
            tempCount = tempCount->next;
        }
        delete tempCount;

        if (size == 1){
            ListNode *popNode = head;
            head = nullptr;
            delete popNode;
            return head;
        }

        size_t midPoss = (size-1)/2;

        ListNode *temp = head;

        if (size%2 == 0){
            for (size_t i = 0; i < midPoss; i++)
                temp = temp->next;
            ListNode *deleteNode = temp->next;
            temp->next = deleteNode->next;
            delete deleteNode;
            temp = nullptr;
            delete temp;
        } else if (size%2 != 0){
            for (size_t i = 0; i < midPoss-1; i++)
                temp = temp->next;
            ListNode *deleteNode = temp->next;
            temp->next = deleteNode->next;
            delete deleteNode;
            temp = nullptr;
            delete temp;
        }

        return head;
    }
};

int main() {

    Solution sol;

    // Test 1

    auto *head10 = new ListNode(1);
    auto *node11 = new ListNode(3);
    auto *node12 = new ListNode(4);
    auto *node13 = new ListNode(7);
    auto *node14 = new ListNode(1);
    auto *node15 = new ListNode(2);
    auto *node16 = new ListNode(6);

    head10->next = node11;
    node11->next = node12;
    node12->next = node13;
    node13->next = node14;
    node14->next = node15;
    node15->next = node16;

    sol.deleteMiddle(head10);

    ListNode *temp1 = head10;
    while (temp1 != nullptr){
        cout << temp1->val << " ";
        temp1 = temp1->next;
    }

    cout << endl;

    // Test 2

    auto *head20 = new ListNode(1);
    auto *node21 = new ListNode(2);
    auto *node22 = new ListNode(3);
    auto *node23 = new ListNode(4);

    head20->next = node21;
    node21->next = node22;
    node22->next = node23;

    sol.deleteMiddle(head20);

    ListNode *temp2 = head20;
    while (temp2 != nullptr){
        cout << temp2->val << " ";
        temp2 = temp2->next;
    }

    cout << endl;

    // Test 3

    auto *head30 = new ListNode(2);
    auto *node31 = new ListNode(1);

    head30->next = node31;

    sol.deleteMiddle(head30);

    ListNode *temp3 = head30;
    while (temp3 != nullptr){
        cout << temp3->val << " ";
        temp3 = temp3->next;
    }

    cout << endl;

    return 0;
}
