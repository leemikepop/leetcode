/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <stdlib.h>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 class Solution {
    public:
        int numComponents(ListNode* head, vector<int>& nums) {
            unordered_set<int> numSet(nums.begin(), nums.end());
            int count = 0;
            while(head) {
                if(numSet.find(head->val) != numSet.end()) {
                    while(head && numSet.find(head->val) != numSet.end()) {
                        head = head->next;
                    }
                    count++;
                }
                if(head) head = head->next;
            }
            return count;
        }

        ListNode* createLinkedList(vector<int> v)  {
            ListNode* head = new ListNode(v[0]);
            ListNode* current = head;
            
            for(int i = 1; i <= v.size(); i++) {
                current->next = new ListNode(v[i]);
                current = current->next;
            }
            return head;
        }
    };

int main(int argc, char *argv[]) {
    Solution *sol = new Solution();
    vector<vector<vector<int>>> test_cases = {
        {{0,1,2,3}, {0,1,3}},
        {{0,1,2,3,4}, {0,3,1,4}},
        {{3,4,0,2,1}, {4}}
    };

    for (auto i : test_cases) {
        ListNode* head = sol->createLinkedList(i[0]);
        cout << sol->numComponents(head, i[1]) << endl;
    }
    return 0;
}