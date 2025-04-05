#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
    public:
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            return maxDepth(root).second;
        }
    
        pair<int, TreeNode*> maxDepth(TreeNode* root) {
            if(!root) return {0, nullptr};
            else {
                auto left = maxDepth(root->left);
                auto right = maxDepth(root->right);
                int depth = max(left.first, right.first) + 1;
                if(left.first > right.first) return {depth, left.second};
                else if(right.first > left.first) return {depth, right.second};
                else return {depth, root};
            }
        }
        TreeNode* createTree(vector<int> v) {
            if (v.size() == 0) return nullptr;
        
            TreeNode* root = new TreeNode(v[0]);
            queue<TreeNode*> q;
            q.push(root);
        
            int i = 1;  // start from the second element
            while (i < v.size()) {
                TreeNode* current = q.front();
                q.pop();
        
                // Assign the left child
                if (v[i] != -1) {
                    current->left = new TreeNode(v[i]);
                    q.push(current->left);
                }
                i++;  // Move to the next value
        
                // Assign the right child if it exists
                if (i < v.size() && v[i] != -1) {
                    current->right = new TreeNode(v[i]);
                    q.push(current->right);
                }
                i++;  // Move to the next value
            }
            return root;
        }

        void printTree(TreeNode* root) {
            if (!root) {
                cout << "null ";
                return;
            }
            cout << root->val << " ";
            printTree(root->left);
            printTree(root->right);
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<vector<int>> test_cases = {
        {3,5,1,6,2,0,8,-1,-1,7,4},
        {1},
        {0,1,3,-1,2},
    };
    for(auto test_case : test_cases) {
        TreeNode* root = sol.createTree(test_case);
        TreeNode* result = sol.lcaDeepestLeaves(root);
        sol.printTree(result);
        cout << endl;
    }
    return 0;
}