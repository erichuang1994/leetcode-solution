# coding:utf8
#  比较两个数组的中位数，判断出median所在的区间，
#  划分成新的子问题
#

import bisect


class Solution(object):

    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        l1, l2 = len(nums1), len(num2s)
        if l2 < l1:
        	nums1, nums2 = nums2, nums1
        	l1, l2 = l2, l1
        low = 0
        high = l1
        half = (l1 + l2 + 1)/2
        while True:
        	mid = (low + high)/2
        	i = mid
        	j = half - mid
        	# find
        	if nums1[i] <= nums2[j+1] and nums2[j] <= nums1[i+1]:
    			max_left = max(nums1[i],nums2[j])
    			min_right = min(nums1[i+1],nums2[j+1])
        		if (l1 + l2)%2 == 0:
        			return (max_left + min_right)*1./2
        		return max_left
        	if i< m and j < l2-1 and  nums1[i] > nums2[j+1]:
        		high = mid-1
        	elif i< m-1 and j < l2 and nums1[i+1] < nums2[j]: 
        		low = mid+1
        	else:
        		if 

if __name__ == "__main__":
    a = Solution()
    t1 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22]
    t2 = [0,6]
    print a.findMedianSortedArrays(t1, t2)