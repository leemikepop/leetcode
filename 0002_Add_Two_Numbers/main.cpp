#include <iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* current = res;
        int cout = 0;
        while (l1 || l2 || cout) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            cout = a + b + cout;
            current->next = new ListNode(cout % 10);
            current = current->next;
            cout /= 10;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return res->next;
    }
};

ListNode* createLinkedList(const std::vector<int>& nums) {
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    for (int num : nums) {
        ListNode *newNode = new ListNode(num);

        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
    }

    return head;
}

void printLinkedList(ListNode *head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v1 = {2, 4, 3};
    std::vector<int> v2 = {5, 6, 4};

    ListNode *l1 = createLinkedList(v1);
    ListNode *l2 = createLinkedList(v2);
    ListNode *ret = (new Solution())->addTwoNumbers(l1, l2);

    printLinkedList(ret);

    return 0;
}