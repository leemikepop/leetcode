#include <iostream>
#include <vector>

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
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if(!p && !q) return true;
            else if(!p || !q) return false;
            else { 
                if(p->val == q->val) {
                    if(isSameTree(p->left,q->left)) {
                        return isSameTree(p->right,q->right);
                    } 
                }
            }
            return false;
        }

        TreeNode* createTree(vector<int> v) {
            if(v.size() == 0) return nullptr;
            TreeNode* root = new TreeNode(v[0]);
            TreeNode* current = root;
            
            for(int i = 1; i < v.size(); i++) {
                current->left = new TreeNode(v[i]);
                current = current->left;
            }
            return root;
        }
    };

int main(int argc, char *argv[]) {
    Solution *sol = new Solution();
    vector<vector<vector<int>>> test_cases = {
        {{1,2,3},{1,2,3}},
        {{1,2,1},{1,1,2}},
        {{},{1}}
    };

    for (int i = 0; i < test_cases.size(); i++) {
        TreeNode* p = sol->createTree(test_cases[i][0]);
        TreeNode* q = sol->createTree(test_cases[i][1]);
        cout << sol->isSameTree(p,q) << endl;
    }
    return 0;
}