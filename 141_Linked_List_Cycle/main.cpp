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
        bool hasCycle(ListNode *head) {
            if(!head || !head->next) return false;
            ListNode *fast = head;
            ListNode *slow = head;
            while(fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;
                if(fast == slow) return true;
            }
            return false;
        }

        ListNode* createLinkedList(vector<int> v, vector<int> pos)  {
            ListNode* head = new ListNode(v[0]);
            ListNode* current = head;
            ListNode* cycle = nullptr;
            
            for(int i = 1; i < v.size(); i++) {
                current->next = new ListNode(v[i]);
                current = current->next;
                if (i == pos[0]) {
                    cycle = current;
                }
            }
            if (pos[0] == 0) cycle = head;
            current->next = cycle;
            return head;
        }
    };


int main(int argc, char *argv[]) {
    Solution *sol = new Solution();
    vector<vector<vector<int>>> test_cases = {
        {{3,2,0,-4}, {1}},
        {{1,2}, {0}},
        {{1}, {-1}},
        {{1,2}, {-1}},
    };

    for (auto i : test_cases) cout << sol->hasCycle(sol->createLinkedList(i[0], i[1])) << endl;
    return 0;
}