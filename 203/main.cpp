#include <iostream>
#include <cassert>

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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return head;
        ListNode *temp;
        auto sentinel = new ListNode(99);
        sentinel->next = head;
        temp = sentinel;
        while (temp != nullptr){
            if (temp->next != nullptr && temp->next->val == val){
                ListNode* popNode = temp->next;
                temp->next = popNode->next;
                popNode->next = nullptr;
                delete popNode;
                if (temp == sentinel)
                    head = temp->next;
            } else {
                temp = temp->next;
            }
        }
        sentinel->next = nullptr;
        sentinel = nullptr;
        delete sentinel;
        return head;
    }
};


int main() {

    Solution sol;

    // Test 1
    auto *head10 = new ListNode(1);
    auto *node11 = new ListNode(2);
    auto *node12 = new ListNode(3);
    auto *node13 = new ListNode(6);
    auto *node14 = new ListNode(4);
    auto *node15 = new ListNode(5);
    auto *node16 = new ListNode(6);

    head10->next = node11;
    node11->next = node12;
    node12->next = node13;
    node13->next = node14;
    node14->next = node15;
    node15->next = node16;

    sol.removeElements(head10, 6);

    ListNode *temp = head10;
    while (temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;


    // Test 2
    ListNode *head20 = nullptr;

    sol.removeElements(head20, 1);

    if (head20 == nullptr)
        cout << "NULL";
    else
        cout << "Error";
    cout << endl;


    // Test 3 (Este test solo funciona en LeetCode)
//    auto *head30 = new ListNode(7);
//    auto *node31 = new ListNode(7);
//    auto *node32 = new ListNode(7);
//    auto *node33 = new ListNode(7);
//
//    head30->next = node31;
//    node31->next = node32;
//    node32->next = node33;
//
//    sol.removeElements(head30, 7);
//
//    if (head30 == nullptr)
//        cout << "NULL";
//    else
//        cout << "Error";


    return 0;
}
