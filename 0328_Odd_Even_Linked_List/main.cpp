#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {
            
        }

        ListNode* createLinkedList(vector<int> v)  {
            if (v.size() == 0) return nullptr;
            ListNode* head = new ListNode(v[0]);
            ListNode* current = head;
            
            for(int i = 1; i < v.size(); i++) {
                current->next = new ListNode(v[i]);
                current = current->next;
            }
            return head;
        }
    };

int main(int argc, char *argv[]) {
    Solution *sol = new Solution();
    vector<vector<int>> test_cases = {
        {1,2,3,4,5},
        {2,1,3,5,6,4,7},
        {1,2,3,4,5,6,7,8},
        {1},
        {}
    };

    for (auto& test_case: test_cases) {
        ListNode* head = sol->createLinkedList(test_case);
        ListNode* result = sol->oddEvenList(head);
        while(result) {
            cout << result->val << " ";
            result = result->next;
        }
        cout << endl;
    }

    return 0;
}