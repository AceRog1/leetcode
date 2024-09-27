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

    delete head10;
    delete node11;
    delete node12;
    delete node13;
    delete node14;
    delete node15;
    delete node16;

    // Test 2

    auto *head20 = new ListNode(1);
    auto *node21 = new ListNode(2);
    auto *node22 = new ListNode(3);
    auto *node23 = new ListNode(4);

    head20->next = node21;
    node21->next = node22;
    node22->next = node23;
    
    delete head20;
    delete node21;
    delete node22;
    delete node23;

    // Test 3

    auto *head30 = new ListNode(2);
    auto *node31 = new ListNode(1);

    head30->next = node31;

    delete head30;
    delete node31;

    return 0;
}
