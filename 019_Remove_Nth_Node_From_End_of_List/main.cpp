/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
*/
#include <ctime>
#include <iostream>
#include <utility> //pair
#include <vector>

using std::pair;
using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::ostream &operator<<(std::ostream &os, ListNode *head) {
    if (head == nullptr) {
        os << "[]";
    } else {
        os << "[";
        while (head != nullptr) {
            os << head->val << " ";
            head = head->next;
        }
        os << "\b]";
    }
    return os;
}

class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        vector<ListNode *> table = {};
        ListNode *curr = head;
        int size = 0;
        while (curr != nullptr) {
            table.push_back(curr);
            curr = curr->next;
            size++;
        }
        if (n == size) {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        } else {
            curr = table[size - n - 1];
            ListNode *tmp = curr->next;
            curr->next = tmp->next;
            delete tmp;
        }
        return head;
    }
};

int main(int argc, char *argv[]) {
    clock_t start = clock();

    Solution *sol = new Solution();
    vector<pair<vector<int>, int>> test_cases = {
        {{1, 2, 3, 4, 5}, 2}, {{1}, 1}, {{1, 2}, 1}};

    for (pair<vector<int>, int> &test_case : test_cases) {
        vector<int> v = test_case.first;
        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        for (int num : v) {
            ListNode *newNode = new ListNode(num);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        std::cout << sol->removeNthFromEnd(head, test_case.second) << std::endl;
    }

    clock_t end = clock();
    double duration = (double)(end - start) / (__clock_t)1000;
    std::cout << std::endl
              << "Exicution Time: " << duration << " ms" << std::endl;
    return 0;
}