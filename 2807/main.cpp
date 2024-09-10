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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* node = head;
        return node;
    }
};

int main() {

    Solution sol;

    // List 1
    auto node11 = new ListNode(18);
    auto node12 = new ListNode(6);
    auto node13 = new ListNode(10);
    auto node14 = new ListNode(3);

    node11->next = node12;
    node12->next = node13;
    node13->next = node14;

    ListNode* head1 = sol.insertGreatestCommonDivisors(node11);

    ListNode* temp1 = head1;
    while(temp1 != nullptr){
        cout << temp1->val << " -> ";
        temp1 = temp1->next;
    }
    cout << endl;

    delete node11;
    delete node12;
    delete node13;
    delete node14;


    // List 2

    auto node21 = new ListNode(7);

    ListNode* head2 = sol.insertGreatestCommonDivisors(node21);

    ListNode* temp2 = head2;
    while(temp2 != nullptr){
        cout << temp2->val << " -> ";
        temp2 = temp2->next;
    }
    cout << endl;

    delete node21;

    return 0;
}
