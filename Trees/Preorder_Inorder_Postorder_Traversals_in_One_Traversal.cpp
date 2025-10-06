#include <iostream>
#include<stack>
#include<vector>
using namespace std ;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0) , left(nullptr) , right(nullptr){}
    TreeNode(int x): val(x) , left(nullptr) , right(nullptr){}
    TreeNode(int x , TreeNode*left, TreeNode*right): val(x) , left(left) , right(right){}
};

void allTraversals(TreeNode* root){
    if (!root) return ;

    stack<pair<TreeNode* , int>> st;
    st.push({root , 1});

    vector<int> preorder , inorder , postorder;

    while (!st.empty()){
        auto it = st.top();
        st.pop();

        if (it.second == 1){
            preorder.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->left)
                st.push({it.first->left , 1});
        }
        else if (it.second ==2 ){
            inorder.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->right)
                st.push({it.first->right , 1});
        }
        else{
            postorder.push_back(it.first->val);
        }
    }
    cout << "Preorder: ";
    for (int x : preorder) cout << x << " ";
    cout << endl << "Inorder: ";
    for (int x : inorder) cout << x << " ";
    cout << endl << "Postorder: ";
    for (int x : postorder) cout << x << " ";
    cout << endl; 
}

int main (){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    allTraversals(root);
    return 0;
}