#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* middleNode(ListNode* head) {
            if(!head || !head->next) return head;
            ListNode *slow = head->next;
            ListNode *fast = head->next->next;
            while(fast && fast->next && fast != slow) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
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
    vector<vector<int>> test_cases = {
        {1,2,3,4,5},
        {1,2,3,4,5,6}
    };
    for (int i = 0; i < test_cases.size(); i++) {
        ListNode* head = sol->createLinkedList(test_cases[i]);
        ListNode* middle = sol->middleNode(head);
        while(middle) {
            cout << middle->val << " ";
            middle = middle->next;
        }
        cout << endl;
    }
    return 0;
}