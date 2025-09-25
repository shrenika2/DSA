#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>

using namespace std ;

struct TreeNode{
    int val ;
    TreeNode * left ;
    TreeNode* right;

    TreeNode() : val() , left(nullptr) , right(nullptr) {}
    TreeNode (int x) : val(x) , left(nullptr) , right(nullptr){}
    TreeNode (int x , TreeNode* left , TreeNode* right) : val(x) , left(left) , right(right){}


};

int maxDept(TreeNode* root){
    if (root == NULL) return 0;
    queue<TreeNode*>q;
    q.push(root);
    int height= 0;

    while (!q.empty()){
        int size = q.size();

        for (int i=0 ; i < size ; i++){
            TreeNode* node = q.front();
            q.pop();
            cout << node->val<< " ";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
        height++;

    }
    return height;   
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    int h = maxDept(root); 
    cout << h << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(width of tree) (worst case O(n))