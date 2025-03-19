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
        bool isSymmetric(TreeNode* root) {
            if(!root) return true;
            if(!root->left && !root->right) return true;
            else if(root->left && root->right) {
                // return isSymmetric_rec(root->left, root->right);
                return isSymmetric_iter(root);
            }
            return false;
        }

        bool isSymmetric_rec(TreeNode* left, TreeNode* right) {
            if(!left && !right) return true;
            else if(left && right && left->val == right->val) {
                return (isSymmetric_rec(left->right, right->left) && isSymmetric_rec(left->left, right->right));
            }
            return false;
        }

        bool isSymmetric_iter(TreeNode* root) {
            queue<TreeNode*> q;
            q.push(root->left);
            q.push(root->right);
            TreeNode* left = nullptr;
            TreeNode* right = nullptr;
            while(!q.empty()) {
                left = q.front();
                q.pop();
                right = q.front();
                q.pop();
                if(left && right) {
                    if(left->val != right->val) return false;
                    q.push(left->left);
                    q.push(right->right);
                    q.push(left->right);
                    q.push(right->left);
                } else if(left || right) return false;
            }
            return true;
        }

        TreeNode* createTree(vector<int> v) {
            if(v.size() == 0) return nullptr;
            TreeNode* root = new TreeNode(v[0]);
            queue<TreeNode*> q;
            q.push(root);
            TreeNode* current = nullptr;
            
            for(int i = 1; i < v.size(); i+=2) {
                current = q.front();
                q.pop();
                if(v[i] != -1) {
                    current->left = new TreeNode(v[i]);
                    q.push(current->left);
                }
                if(i+1 < v.size() && v[i+1] != -1) {
                    current->right = new TreeNode(v[i+1]);
                    q.push(current->right);
                }
            }
            return root;
        }
    };

int main(int argc, char* argv[]) {
    Solution *sol = new Solution();
    vector<vector<int>> test_cases = {
        {1,2,2,3,4,4,3},
        {1,2,2,3,4,4,3,5,6,7,8,8,7,6,5},
        {1,2,2,3,4,4,3,5,6,7,8,8,7,6,5,9},
        {1,2,2,-1,3,-1,3}
    };

    for (int i = 0; i < test_cases.size(); i++) {
        TreeNode* root = sol->createTree(test_cases[i]);
        cout << sol->isSymmetric(root) << endl;
    }

    return 0;
}