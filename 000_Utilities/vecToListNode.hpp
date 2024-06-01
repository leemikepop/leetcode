#ifndef VECTOLISTNODE_HPP
#define VECTOLISTNODE_HPP

#include "listNode.hpp"

#include <vector>
#include <utility>		//pair

ListNode* createLinkedLists(const std::vector<int>& nums);
std::vector<std::pair<ListNode*, ListNode*>> convert(const std::vector<std::pair<std::vector<int>, std::vector<int>>>& input);

#endif // VECTOLISTNODE_HPP