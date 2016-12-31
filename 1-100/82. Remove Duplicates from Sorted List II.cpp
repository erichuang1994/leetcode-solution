/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode **t = &(head);
    ListNode *c;
    while (*t != NULL) {
      c = (*t)->next;
      if (c != NULL && (*t)->val == c->val) {
        while (c != NULL && (*t)->val == c->val) {
          *t = c;
          c = (*t)->next;
        }
        *t = (*t)->next;
      } else {
        t = &((*t)->next);
      }
    }
    return head;
  }
};
