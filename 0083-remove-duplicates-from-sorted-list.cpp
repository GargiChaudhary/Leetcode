"""
Problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
Example:
Input: head = [1,1,2]
Output: [1,2]
"""
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* forw = head -> next;
        while(forw != NULL){
            if(temp -> val == forw -> val){
                temp -> next = forw -> next;
                forw = forw -> next;
            }else{
                temp = forw;
                forw = forw -> next;
            }
        }
        return head;
    }
};
