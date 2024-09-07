#include <iostream>
#include <vector>
#include <stack>

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
    int val; // value
    TreeNode *left; // left node
    TreeNode *right; // right node
    TreeNode() : val(0), left(nullptr), right(nullptr) {} // default constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // constructor with parameter x
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // constructor with parameters x *left *right
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) { // Aqui se hace un DFS

    }
};

int main() {

    Solution sol1, sol2;

    // Arbol 1
    auto *tree11 = new TreeNode(1);
    auto *tree12 = new TreeNode(2);
    auto *tree13 = new TreeNode(3);

    tree11->right = tree12;
    tree12->left = tree13;

    vector<int> inorderTree1 = sol1.inorderTraversal(tree11);

    for (int i : inorderTree1){
        if (i == 0)
            cout << "[" << i << " ";
        if (i == inorderTree1.size()-1)
            cout << i << "]";
        cout << i << " ";
    }
    cout << endl;

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

    vector<int> inorderTree2 = sol1.inorderTraversal(tree12);

    for (int i : inorderTree2){
        if (i == 0)
            cout << "[" << i << " ";
        if (i == inorderTree2.size()-1)
            cout << i << "]";
        cout << i << " ";
    }



    return 0;
}
