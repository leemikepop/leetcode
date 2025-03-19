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
        TreeNode* invertTree(TreeNode* root) {
            if(!root || (!root->left && !root->right)) return root;
            return invert(root);
        }
    
        TreeNode* invert(TreeNode* root) {
            if(root) {
                if(root->right) invert(root->right);
                invert(root->left);
                TreeNode* temp = root->left;
                root->left = root->right;
                root->right = temp;
            }
            return root;
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

        void printLevelOrder(TreeNode* root) {
            if (!root) return;  // Handle empty tree
        
            queue<TreeNode*> q;
            q.push(root);
        
            while (!q.empty()) {
                TreeNode* current = q.front();
                q.pop();
        
                cout << current->val << " "; // Print node value
        
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
        }
        
    };

int main(int argc, char* argv[]) {
    Solution *sol = new Solution();
    vector<vector<int>> test_cases = {
        {4, 2, 7, 1, 3, 6, 9},
        {2, 1, 3},
        {1, 2}
    };

    for (auto v : test_cases) {
        TreeNode* root = sol->createTree(v);
        TreeNode* inverted = sol->invertTree(root);
        cout << "Inverted tree: " << endl;
        sol->printLevelOrder(inverted);
        cout << endl;
    }

    return 0;
}