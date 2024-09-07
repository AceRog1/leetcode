//
// Created by acerog on 7/09/24.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * Beats 100.00% in Runtime (0ms)
 * Beats 25.49% in Memory (10.15mb)
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if (root == nullptr)
            return inorder;
        if (root->right == nullptr && root->left == nullptr){
            inorder.push_back(root->val);
            return inorder;
        }
        inOrder(inorder, root);
        return inorder;
    }

    void inOrder(vector<int> &inorder, TreeNode* node){
        if (node == nullptr)
            return;
        inOrder(inorder, node->left);
        inorder.push_back(node->val);
        inOrder(inorder, node->right);
    }
};

int main() {

    Solution sol;

    // Arbol 1
    auto *tree11 = new TreeNode(1);
    auto *tree12 = new TreeNode(2);
    auto *tree13 = new TreeNode(3);

    tree11->right = tree12;
    tree12->left = tree13;

    vector<int> inorderTree1 = sol.inorderTraversal(tree11);

    for (int i : inorderTree1)
        cout << i << " ";
    cout << endl;

    delete tree11;
    delete tree12;
    delete tree13;

    // Arbol 2
    auto *tree21 = new TreeNode(1);
    auto *tree22 = new TreeNode(2);
    auto *tree23 = new TreeNode(3);
    auto *tree24 = new TreeNode(4);
    auto *tree25 = new TreeNode(5);
    auto *tree26 = new TreeNode(6);
    auto *tree27 = new TreeNode(7);
    auto *tree28 = new TreeNode(8);
    auto *tree29 = new TreeNode(9);

    tree21->left = tree22;
    tree21->right = tree23;
    tree22->left = tree24;
    tree22->right = tree25;
    tree25->left = tree26;
    tree25->right = tree27;
    tree23->right = tree28;
    tree28->left = tree29;

    vector<int> inorderTree2 = sol.inorderTraversal(tree21);

    for (int i : inorderTree2)
        cout << i << " ";
    cout << endl;

    delete tree21;
    delete tree22;
    delete tree23;
    delete tree24;
    delete tree25;
    delete tree26;
    delete tree27;
    delete tree28;
    delete tree29;

    // Arbol 3

    TreeNode *tree31;

    vector<int> inorderTree3 = sol.inorderTraversal(tree31);

    for (int i : inorderTree3)
        cout << i << " ";
    cout << endl;

    delete tree31;

    // Arbol 4

    auto *tree41 = new TreeNode(1);

    vector<int> inorderTree4 = sol.inorderTraversal(tree41);

    for (int i : inorderTree4)
        cout << i << " ";

    delete tree41;

    return 0;
}
