#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//   bool hasCycle(ListNode *head) {
//     if (head == NULL)
//       return false;
//     ListNode *hkJournalist = head;
//     ListNode *usJournalist = head;
//     while (true) {
//       usJournalist = usJournalist->next;
//       if (usJournalist == NULL)
//         return false;
//       usJournalist = usJournalist->next;
//       if (usJournalist == NULL)
//         return false;
//       hkJournalist = hkJournalist->next;
//       if (hkJournalist == usJournalist) {
//         return true;
//       }
//     }
//   }
// };
// without extra space
class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == NULL)
      return false;
    while (true) {
      if (head->next == NULL || head->next->next == NULL) {
        return false;
      }
      if (head->next == head) {
        return true;
      }
      head->next = head->next->next;
      head = head->next;
    }
  }
};
