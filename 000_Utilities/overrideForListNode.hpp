#include "listNode.hpp"

#include <iostream>
#include <sstream>

std::ostream& operator<<(std::ostream& os, ListNode* head) {
    os << "[";
    while (head != nullptr) {
        os << head->val;
        if (head->next != nullptr) {
            os << ", ";
        }
        head = head->next;
    }
    os << "]";
    return os;
}

// std::ostream &operator<<(std::ostream &os, ListNode *head) {
//     if (head == nullptr) {
//         os << "[]";
//     } else {
//         os << "[";
//         while (head != nullptr) {
//             os << head->val << " ";
//             head = head->next;
//         }
//         os << "\b]";
//     }
//     return os;
// }