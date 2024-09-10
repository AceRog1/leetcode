//
// Created by acerog on 10/09/24.
//

#include <iostream>

using namespace std;

/**
 * 
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
        ListNode* tempI = head;
        ListNode* tempF = head->next;

        while (tempF != nullptr){
            auto newNode = new ListNode(gcd(tempI->val, tempF->val));
            newNode->next = tempF;
            tempI->next = newNode;
            tempI = tempF;
            tempF = tempF->next;
        }

        return head;
    }

    int static gcd(int a, int b){
        int result = min(a,b);
        while (result > 0){
            if (a%result == 0 && b%result == 0)
                break;
            result--;
        }
        return result;
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
        if (temp1->next == nullptr)
            cout << temp1->val;
        else
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
        if (temp2->next == nullptr)
            cout << temp2->val;
        else
            cout << temp2->val << " -> ";
        temp2 = temp2->next;
    }
    cout << endl;

    delete node21;

    return 0;
}
