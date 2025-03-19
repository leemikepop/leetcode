#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        Solution(ListNode* head) {
            
        }
        
        int getRandom() {
            
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
    };

    for (auto& test_case: test_cases) {
        ListNode* head = sol->createLinkedList(test_case);
        cout << sol->getRandom() << endl;
        cout << sol->getRandom() << endl;
        cout << sol->getRandom() << endl;
        cout << sol->getRandom() << endl;
        cout << sol->getRandom() << endl;
        cout << endl;
    }

    return 0;
}