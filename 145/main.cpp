#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val; // valor
    TreeNode *left; // nodo izquierdo
    TreeNode *right; // nodo derecho
    TreeNode() : val(0), left(nullptr), right(nullptr) {} // constructor por default
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // constructor con variable inicializada
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // constructor con todas las variables inicializadas
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;

        return postorder;
    }

    void postOrder(vector<int>& postorder, TreeNode* node){
        if (node == nullptr)
            return;
        postOrder(postorder, node->left);
        postOrder(postorder, node->right);
        postorder.push_back(node->val);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
