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
        int findTilt(TreeNode* root) {
            TreeNode* node = nullptr;
            TreeNode* tree = root;
            queue<TreeNode*> q;
            if(!root) return 0;
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
            while(!q.empty()) {
                node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                sum(node);
            }

            q.push(root);
            while(!q.empty()) {
                node = q.front();
                q.pop();
                if(node->left && node->right) {
                    node->val = abs(node->left->val-node->right->val);
                    q.push(node->left);
                    q.push(node->right);
                } else if(node->left) {
                    node->val = node->left->val;
                    q.push(node->left);
                } else if(node->right) {
                    node->val = node->right->val;
                    q.push(node->right);
                } else node->val = 0;
            }

            int sum = 0;
            q.push(root);
            while(!q.empty()){
                node = q.front();
                q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            return sum;
        }

        void sum(TreeNode* root) {
            if(!root) return;
            queue<TreeNode*> q;
            int sum = 0;
            q.push(root);
            while(!q.empty()) {
                TreeNode* node = q.front();
                q.pop();
                if(node->val != -1) sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            root->val = sum;
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

int main(int argc, char* argv[]){
    Solution *sol = new Solution();
    
    vector<vector<int>> test_cases = {
        // {1,2,3},
        // {4,2,9,3,5,-1,7},
        // {21,7,14,1,1,2,2,3,3},
        // {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
        {-8,3,0,-8,-1,-1,-1,-1,-1,-1,8}
    };

    for (int i = 0; i < test_cases.size(); i++) {
        TreeNode* root = sol->createTree(test_cases[i]);
        cout << sol->findTilt(root) << endl;
    }

    return 0;
}