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
        ListNode* removeElements(ListNode* head, int val) {
            while(head) {
                if(head->val == val) head = head->next;
                else break;
            }
            if(!head) return head;
            ListNode* pre = head;
            ListNode* curr = head->next;
            while(curr) {
                if(curr->val == val) {
                    pre->next = curr->next;
                    curr = curr->next;
                } else {
                    pre = curr;
                    curr = curr->next;
                }
            }
            return head;
        }

        ListNode* removeElements2(ListNode* head, int val) {
            while(head) {
                if(head->val == val) head = head->next;
                else break;
            }
            if(!head) return head;
            ListNode* curr = head;
            while(curr) {
                while(curr->next && curr->next->val == val) {
                    curr->next = curr->next->next;
                }
                curr = curr->next;
            }
            return head;
        }

        ListNode* createLinkedList(vector<int> v)  {
            if(v.size() == 0) return nullptr;
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
    vector<vector<vector<int>>> test_cases = {
        {{1,2,6,3,4,5,6}, {6}},
        {{},{1}},
        {{7,7,7,7},{7}},
        {{1,2,2,1},{2}}
    };
    cout << "Remove 1" << endl;
    for(auto v: test_cases) {
        ListNode* head = sol->createLinkedList(v[0]);
        ListNode* newHead = sol->removeElements(head, v[1][0]);
        while(newHead) {
            cout << newHead->val << " ";
            newHead = newHead->next;
        }
        cout << endl;
    }

    cout << endl << "Remove 2" << endl;
    for(auto v: test_cases) {
        ListNode* head = sol->createLinkedList(v[0]);
        ListNode* newHead = sol->removeElements2(head, v[1][0]);
        while(newHead) {
            cout << newHead->val << " ";
            newHead = newHead->next;
        }
        cout << endl;
    }
    return 0;
}