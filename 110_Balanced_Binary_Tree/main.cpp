#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        bool isBalanced(TreeNode* root) {
            if(!root) return true;
            if(!root->left && !root->right) return true;
            else if(root->left || root->right) {
                if(!root->left && root->right) if(height(root->right) <= 1) return true;
                if(!root->right && root->left) if(height(root->left) <= 1) return true;
                if(root->left && root->right) {
                    if(abs(height(root->left)-height(root->right)) <= 1) return true;
                }
            }
            return false;
        }

        int height(TreeNode* root) {
            if(!root) return 0;
            else {
                if(!root->left && !root->right) return 1;
                else if(!root->left && root->right) return height(root->right) + 1;
                else if(!root->right && root->left) return height(root->left) + 1;
                else return max(height(root->left), height(root->right)) + 1;
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
        
    };

int main(int argc, char* argv[]) {
    Solution *sol = new Solution();
    vector<vector<int>> test_cases = {
        // {3,9,20,-1,-1,15,7},
        // {1,2,2,3,3,-1,-1,4,4},
        // {1,2,2,3,3,3,3,4,4,4,4,4,4,-1,-1,5,5},
        {1,2,2,3,-1,-1,3,4,-1,-1,-1,-1,-1,-1,4},
        // {1,-1,3,2}
    };

    for (int i = 0; i < test_cases.size(); i++) {
        TreeNode* root = sol->createTree(test_cases[i]);
        cout << sol->isBalanced(root) << endl;
    }
    return 0;
}