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
  ListNode *removeElements(ListNode *head, int val) {
    while (head != NULL && head->val == val)
      head = head->next;
    if (head == NULL)
      return head;
    ListNode *last = head;
    ListNode *cur = head->next;
    while (cur != NULL) {
      if (cur->val == val) {
        last->next = cur->next;
      } else {
        last = cur;
      }
      cur = cur->next;
    }
    return head;
  }
};
