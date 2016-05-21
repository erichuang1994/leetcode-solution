#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
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
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA;
    ListNode *b = headB;
    while (a != NULL && b != NULL) {
      if (a == b) {
        return a;
      }
      a = a->next;
      b = b->next;
    }
    if (a == NULL and b == NULL) {
      return NULL;
    }
    if (a == NULL) {
      a = headB;
      while (b != NULL) {
        b = b->next;
        a = a->next;
      }
      b = headA;
    } else {
      b = headA;
      while (a != NULL) {
        a = a->next;
        b = b->next;
      }
      a = headB;
    }
    while (a != NULL && b != NULL) {
      if (a == b) {
        return a;
      }
      a = a->next;
      b = b->next;
    }
    return NULL;
  }
};

int main() {
  Solution a;
  // int v = {};
  return 0;
}
