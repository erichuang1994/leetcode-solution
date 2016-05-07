# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
        	return None
        one = head
        faster = head.next
        if faster == None:
        	return None
        if one is faster:
        	return faster
        while True:
        	one = one.next
        	if one == None:
        		return None
        	faster = faster.next
        	if faster == None:
        		return None
        	faster = faster.next
        	if faster == None:
        		return None
        	if one is faster:
        		break
        print 'hit',one.val,faster.val
        one = head 
        faster = faster.next
        if faster is head:
        	return head
        while one is not faster:
        	# print one.val,faster.val
        	one = one.next
        	faster = faster.next

        return faster
if __name__ == "__main__":
	# [3,2,0,-4,5]
	three = ListNode(3)
	two = ListNode(2)
	three.next = two
	zero = ListNode(0)
	two.next = zero
	minusfour = ListNode(-4)
	zero.next = minusfour
	five = ListNode(5)
	minusfour.next = five
	five.next=zero
	# minusfour.next = three
	a = Solution()
	print a.detectCycle(three).val