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

    Solution sol;

    // Arbol 1
    auto *tree11 = new TreeNode(1);
    auto *tree12 = new TreeNode(2);
    auto *tree13 = new TreeNode(3);

    tree11->right = tree12;
    tree12->left = tree13;

    vector<int> inorderTree1 = sol.postorderTraversal(tree11);

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

    vector<int> inorderTree2 = sol.postorderTraversal(tree21);

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

    vector<int> inorderTree3 = sol.postorderTraversal(tree31);

    for (int i : inorderTree3)
        cout << i << " ";
    cout << endl;

    delete tree31;

    // Arbol 4

    auto *tree41 = new TreeNode(1);

    vector<int> inorderTree4 = sol.postorderTraversal(tree41);

    for (int i : inorderTree4)
        cout << i << " ";

    delete tree41;

    return 0;
}
