#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

struct TreeNode{
    int val ;
    TreeNode * left ;
    TreeNode* right;

    TreeNode() : val() , left(nullptr) , right(nullptr) {}
    TreeNode (int x) : val(x) , left(nullptr) , right(nullptr){}
    TreeNode (int x , TreeNode* left , TreeNode* right) : val(x) , left(left) , right(right){}


};

void leftBoundary(TreeNode* root , vector<int> &res){
        TreeNode* cur = root;
        while(cur){
            if (cur->left || cur->right)
                res.push_back(cur->val);
                if (cur->left) cur = cur->left;
                else cur=cur->right;
            }
        }

void leaves(TreeNode* root , vector<int> & res){
    if (!root) return ;
    if (!root->left && !root->right){
        res.push_back(root->val);
        return ;
    }
    leaves(root->left , res);
    leaves(root->right , res);
}

void rightBoundary(TreeNode* root , vector<int> & res){
    vector<int> temp;
    TreeNode* cur = root;
    while (cur)
    {
       if(cur->left || cur->right)
       temp.push_back(cur->val);

       if (cur->right) cur = cur->right;
       else cur = cur->left;
    }
    for(int i= temp.size() -1 ; i >= 0 ; i--)
    res.push_back(temp[i]);
}

vector <int> boundary_traversal(TreeNode* root){
    vector<int> res ;
    if (!root) return res ;
    res.push_back(root->val);

    if (root->left) leftBoundary(root->left , res);
    leaves(root->left , res);
    leaves(root->right , res);

    if (root->right) rightBoundary(root->right , res);
    return res ;
}

int main(){
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

     vector<int> res = boundary_traversal(root1);
    for (int x : res) cout << x << " ";
    return 0;
    
}

