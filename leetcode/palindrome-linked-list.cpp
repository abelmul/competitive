#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* ptr = head;
        vector<int> list;
        
        while(ptr != nullptr) {
            list.push_back(ptr->val);
            ptr = ptr->next;
        }
        
        vector<int> reverse_list = list;
        reverse(reverse_list.begin(), reverse_list.end());
        
        return list == reverse_list;
    }
};
