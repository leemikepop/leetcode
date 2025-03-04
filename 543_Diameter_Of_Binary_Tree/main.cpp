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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int result = 0;
        DFS(root, &result);
        return result;
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

private:
    int DFS(TreeNode* root, int* result) {
        if(!root) return 0;
        
        int l = DFS(root->left, result);
        int r = DFS(root->right, result);

        *result = max(*result, l+r);

        return max(l,r) + 1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> v = {
        {1,2,3,4,5},
        {1,2},
        {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}
    };
    for(auto i : v) {
        TreeNode* root = s.createTree(i);
        cout << s.diameterOfBinaryTree(root) << endl;
    }
    return 0;
}