#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode *ReverseList = nullptr;
            while(head) {
                ReverseList = new ListNode(head->val, ReverseList);
                head = head->next;
            }
        }

        ListNode* reverseList2(ListNode* head) {
            if(!head || !head->next) return head;
            ListNode* curr = nullptr;
            while(head) {
                ListNode* temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
            }
            return curr;
        }

        ListNode* createLinkedList(vector<int> v)  {
            ListNode* head = new ListNode(v[0]);
            ListNode* current = head;
            ListNode *Node = head;
            
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
        {1,2,3,4,5}
    };
    ListNode* head = sol->createLinkedList(test_cases[0]);
    ListNode* newHead = sol->reverseList2(head);
    while(newHead) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;
    return 0;
}