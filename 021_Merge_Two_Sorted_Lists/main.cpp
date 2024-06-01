#include "../000_Utilities/listNode.hpp"
#include "../000_Utilities/overrideForListNode.hpp"
#include "../000_Utilities/vecParser.hpp"
#include "../000_Utilities/vecToListNode.hpp"
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>

using std::pair;
using std::string;
using std::vector;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        ListNode *head = nullptr, *tail = nullptr;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                if (head == nullptr) {
                    head = list1;
                } else {
                    tail->next = list1;
                }
                tail = list1;
                list1 = list1->next;
            } else {
                if (head == nullptr) {
                    head = list2;
                } else {
                    tail->next = list2;
                }
                tail = list2;
                list2 = list2->next;
            }
        }

        if (list1 == nullptr) {
            tail->next = list2;
        }
        if (list2 == nullptr) {
            tail->next = list1;
        }
        return head;
    }
};

int main(int argc, char *argv[]) {
    clock_t start = clock();

    Solution *sol = new Solution();

    string strTestcases = "[1,2,4]\n[1,3,4]\n[]\n[]\n[]\n[0]\n";

    vector<pair<ListNode *, ListNode *>> test_cases =
        convert(parseInput(strTestcases));

    for (pair<ListNode *, ListNode *> test_case : test_cases) {
        std::cout << sol->mergeTwoLists(test_case.first, test_case.second)
                  << std::endl;
    }

    clock_t end = clock();
    double duration = (double)(end - start) / (__clock_t)1000;
    std::cout << std::endl
              << "Exicution Time: " << duration << " ms" << std::endl;
    return 0;
}