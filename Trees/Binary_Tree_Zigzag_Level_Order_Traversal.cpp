#include <iostream>
#include<queue>
using namespace std ;

struct TreeNode{
    int val ;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0) , left(nullptr) , right(nullptr){}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr){}
    TreeNode(int x , TreeNode* left , TreeNode* right) : val(x) , left(left) , right(right){}

};

vector<vector<int>> zigzag(TreeNode* root){
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q ;
    q.push(root);
    bool lr = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> level(size);

        for (int i=0 ; i < size ; i++){
            TreeNode* node = q.front();
            q.pop();

            int index = lr ? i : (size-1-i);
            level[index] = node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
                }
            result.push_back(level);
            lr = !lr;
    }
    return result;
}

int main () {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(9);

    vector<vector<int>> ans = zigzag(root);

    for (auto &level : ans) {
        for (int val : level) cout << val << " ";
        cout << endl;
    }
    return 0;
}
