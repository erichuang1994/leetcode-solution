class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        ret = 0
        temp = 0
        flag = [-1]*200
        for x in range(len(s)):
        	# print flag[ord(s[x])]
        	if x - flag[ord(s[x])] > temp:
        		flag[ord(s[x])] = x
        		temp = temp+1
        	else:
        		if temp > ret:
        			ret = temp
        		temp = x - flag[ord(s[x])]
        		flag[ord(s[x])] = x
        if temp > ret:
        	ret = temp
        return ret

if __name__ == "__main__":
	a = Solution()
	print a.lengthOfLongestSubstring("aaaa")