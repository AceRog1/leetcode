#include <iostream>

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
    ListNode* deleteMiddle(ListNode* head) {
        size_t size = 0;
        ListNode *tempCount = head;
        while (tempCount != nullptr){
            size++;
            tempCount = tempCount->next;
        }
        delete tempCount;

        size_t midPoss = (size-1)/2;

        ListNode *temp = head;
        for (size_t i = 0; i < midPoss; i++){
            if (i == midPoss-1){
                ListNode *deleteNode = temp->next;
                temp->next = deleteNode->next;
                delete deleteNode;
            }
            temp = temp->next;
        }
        temp = nullptr;
        delete temp;
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

    //delete head10;
    //delete node11;
    //delete node12;
    //delete node13;
    //delete node14;
    //delete node15;
    //delete node16;

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

    //delete head20;
    //delete node21;
    //delete node22;
    //delete node23;

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

    //delete head30;
    //delete node31;

    cout << endl;

    return 0;
}
