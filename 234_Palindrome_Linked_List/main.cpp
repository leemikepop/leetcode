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
        bool isPalindrome(ListNode* head) {
            if (!head || !head->next) return true;
            ListNode* reverse = nullptr;
            ListNode* temp = head;
            while(head) {
                reverse = new ListNode(head->val, reverse);
                head = head->next;
            }
            while(temp) {
                if(temp->val != reverse->val) return false;
                temp = temp->next;
                reverse = reverse->next;
            }
            return true;
        }

        bool isPalindrome2(ListNode* head) {
            if(!head || !head->next) return true;
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode *reverseList = reverse(slow);
            while(reverseList) {
                if(head->val != reverseList->val) return false;
                reverseList = reverseList->next;
                head = head->next;
            }
            return true;
        }

        ListNode* reverse(ListNode* head) {
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
            ListNode* Node = head;
            
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
        {1,2,2,1},
        {1,2}
    };

    cout << "Palindrome 1" << endl;
    for (int i = 0; i < test_cases.size(); i++) {
        ListNode* head = sol->createLinkedList(test_cases[i]);
        cout << sol->isPalindrome(head) << endl;
    }
    
    cout << endl;
    cout << "Palindrome 2" << endl;
    for (int i = 0; i < test_cases.size(); i++) {
        ListNode* head = sol->createLinkedList(test_cases[i]);
        cout << sol->isPalindrome2(head) << endl;
    }

    return 0;
}