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
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head)
      return head;
    int count = k;
    ListNode *last = head;
    ListNode *cur = head->next;
    ListNode *tmp;
    last->next = NULL;
    while (--count && cur) {
      tmp = cur->next;
      cur->next = last;
      last = cur;
      cur = tmp;
    }
    if (count == 0) {
      head->next = reverseKGroup(cur, k);
      return last;
    } else {
      cur = last->next;
      last->next = NULL;
      while (++count < k) {
        tmp = cur->next;
        cur->next = last;
        last = cur;
        cur = tmp;
      }
      return last;
    }
  }
};
