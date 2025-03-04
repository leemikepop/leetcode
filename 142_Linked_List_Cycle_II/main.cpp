#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode *tortoise = head;
            ListNode *hare = head;
            ListNode *Node = nullptr;
            while(hare && hare->next) {
                tortoise = tortoise->next;
                hare = hare->next->next;
                if(tortoise == hare) {
                    tortoise = head;
                    while(tortoise != hare) {
                        tortoise = tortoise->next;
                        hare = hare->next;
                    }
                    Node = tortoise;
                    break;
                }
            }
            return Node;
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

    ListNode* result = nullptr;
    for (auto i : test_cases) {
        result = sol->detectCycle(sol->createLinkedList(i[0], i[1]));
        if (result) cout << result->val << endl;
        else cout << "No cycle" << endl;
    }
    return 0;
}