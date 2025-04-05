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
        TreeNode* searchBST(TreeNode* root, int val) {
            if(!root) return nullptr;
            else if(val == root->val) return root;
            else if(val < root->val) return searchBST(root->left, val);
            else return searchBST(root->right, val);
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
    
    vector<pair<vector<int>, int>> test_cases = {
        {{4, 2, 7, 1, 3}, 2},
        {{4, 2, 7, 1, 3}, 5},
        {{1}, 1},
        {{1}, 2},
        {{}, 0}
    };

    for (int i = 0; i < test_cases.size(); i++) {
        TreeNode* root = sol->createTree(test_cases[i].first);
        cout << sol->searchBST(root, test_cases[i].second) << endl;
    }

    return 0;
}