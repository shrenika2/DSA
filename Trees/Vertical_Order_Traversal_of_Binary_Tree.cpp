#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left ;
    TreeNode* right;

    TreeNode(): val(0) , left(nullptr) , right(nullptr){}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr){}
    TreeNode(int x , TreeNode* left , TreeNode* right) : val(x) , left(left) , right(right){}

};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root){
        map<int , map<int , multiset<int>>> nodes;

        queue<pair<TreeNode* , pair<int , int>>> todo;

        todo.push({root , {0 , 0}});

        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();

            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;

            nodes[x][y].insert(node->val);

            if (node->left)
                todo.push({node->left , {x-1 , y+1}});
            if(node->right)
                    todo.push({node->right , {x+1 , y+1}});
        }

        vector<vector<int>> ans;

        for (auto& p : nodes){
            vector<int> col;
            for (auto& q : p.second){
                col.insert(col.end() , q.second.begin() , q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

int main (){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    vector<vector<int>> result = s.verticalTraversal(root);

    cout << "Vertical Order Traversal: " << endl;
    for (auto & col : result){
        for (int val : col)
            cout << val << " ";
    }
    return 0;
}