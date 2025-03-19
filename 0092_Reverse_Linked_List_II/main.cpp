#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int v, ListNode *next) : val(v), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int index = 1;
        ListNode *dummy = new ListNode(0, head);
        ListNode *preList = dummy;
        
        for(int i = 1; i < left; i++) {
            preList = preList->next;
        }

        ListNode *ReverseList = nullptr;
        while(index <= right) {
            if (index >= left && index <= right) ReverseList = new ListNode(head->val, ReverseList);
            head = head->next;
            index++;
        }
        
        ListNode *current = preList;
        preList->next = ReverseList;
        while(current->next) {
            current = current->next;
        }
        current->next = head;

        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
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
    // vector<vector<vector<int>>> test_cases = {
    //     {{1,2,3,4,5}, 2, 4},
    //     // {{1,2,3,4,5}, {1,5}},
    //     // {{1,2,3,4,5}, {1,1}}
    // };
    // for (int i = 0; i < test_cases.size(); i++) {
        
    // }
    vector<vector<int>> test_cases = {
        {1,2,3,4,5}
    };
    ListNode* head = sol->createLinkedList(test_cases[0]);
    ListNode* ReverseList = nullptr;
    ReverseList = sol->reverseBetween(head, 2, 4);
    while(ReverseList) {
        cout << ReverseList->val << " ";
        ReverseList = ReverseList->next;
    }
    cout << endl;
    return 0;
}