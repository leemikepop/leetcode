#include "vecToListNode.hpp"
#include <utility>

ListNode* createLinkedLists(const std::vector<int>& nums) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int num : nums) {
        ListNode* node = new ListNode(num);
        if (head == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    return head;
}

std::vector<std::pair<ListNode*, ListNode*>> convert(const std::vector<std::pair<std::vector<int>, std::vector<int>>>& input) {
    std::vector<std::pair<ListNode*, ListNode*>> result;

    for (const auto& pair : input) {
        result.push_back(std::make_pair(createLinkedLists(pair.first), createLinkedLists(pair.second)));
    }

    return result;
}