# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        nodeList = []
        while not (l1 == None and l2 == None and carry == 0):
        	val1 = 0
        	val2 = 0
        	if l1 !=None:
        		val1 = l1.val
        		l1 = l1.next
        	if l2 !=None:
        		val2 = l2.val
        		l2 = l2.next
        	val = (val1 + val2+carry)%10
        	carry = (val1 + val2+carry)/10
        	nodeList.append(val)
        ret = ListNode(nodeList[0])
        temp = ret
        for x in range(1,len(nodeList)):
        	temp.next = ListNode(nodeList[x])
        	temp = temp.next
        return ret

if __name__ == "__main__":
    a = Solution()
    print a.addTwoNumbers([0],[0])
