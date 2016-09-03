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
  bool isPalindrome(ListNode *head) {
    int len = 0;
    ListNode *tmp = head;
    while (tmp != NULL) {
      tmp = tmp->next;
      len++;
    }
    if (len == 0 || len == 1) {
      return true;
    }
    ListNode *next;
    tmp = head->next;
    head->next = NULL;
    ListNode *last = head;
    for (int i = 1; i < (len) / 2; i++) {
      next = tmp->next;
      tmp->next = last;
      last = tmp;
      tmp = next;
    }
    if (len % 2 == 1) {
      tmp = tmp->next;
    }
    while (tmp != NULL) {
      if (tmp->val != last->val) {
        return false;
      }
      tmp = tmp->next;
      last = last->next;
    }
    return true;
  }
};
