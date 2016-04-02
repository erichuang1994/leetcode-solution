import bisect

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums_sorted=sorted(nums)
        for index,value in enumerate(nums_sorted):
            result = bisect.bisect_left(nums_sorted,target-value)
            length = len(nums)
            if result <length and nums_sorted[result] == target-value:
                if value == target - value:
                    res = self.my_index(nums ,value)
                    return res[0:2]
                return [nums.index(value),nums.index(target-value)]
    def my_index(self,my_list,value):
        result =[]
        for index,v in enumerate(my_list):
            if v == value:
                result.append(index)
        return result

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        table = [-1]*65535
        for index ,v in enumerate(nums):
            if table[v] != -1 and index != table[v]:
                return [table[v] ,index]
            table[target-v] = index



if __name__ == "__main__":
    a = Solution()
    print a.twoSum([5,75,25],100)
