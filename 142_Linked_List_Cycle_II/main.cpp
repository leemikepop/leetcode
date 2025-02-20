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
            while(tortoise && hare->next) {
                tortoise = tortoise->next;
                hare = hare->next->next;
                if(tortoise == hare) {
                    tortoise = head;
                    while(tortoise != head) {
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
                if (i == pos[0]) {
                    cycle = current;
                }
                current = current->next;
            }
            if (pos[0] == 0) cycle = head;
            current->next = cycle;
            // int index = 0;
            // while(head && index < 10) {
            //     cout << head->val << " ";
            //     head = head->next;
            //     index++;
            // }
            return head;
        }
    };


int main(int argc, char *argv[]) {
    Solution *sol = new Solution();
    vector<vector<vector<int>>> test_cases = {
        {{3,2,0,-4}, {1}},
        {{1,2}, {0}},
        {{1}, {-1}}
    };

    for (auto i : test_cases) {
        cout << sol->detectCycle(sol->createLinkedList(i[0], i[1]))->val << endl;
    }
    // sol->createLinkedList(test_cases[1][0], test_cases[1][1]);
    // cout << sol->detectCycle(sol->createLinkedList(test_cases[1][0], test_cases[1][1]))->val << endl;
    return 0;
}