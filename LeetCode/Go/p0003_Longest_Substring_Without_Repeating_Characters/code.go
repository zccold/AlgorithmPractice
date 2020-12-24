package p0003_Longest_Substring_Without_Repeating_Characters

func lengthOfLongestSubstring(s string) int {
	lastIndexMap := make(map[byte]int) //字符上一次出现的index
	left := -1                         //当前计算长度时使用的最左下标-1
	res := 0
	for i := 0; i < len(s); i++ {
		c := s[i]
		if lastIndex, ok := lastIndexMap[c]; ok && lastIndex > left {
			left = lastIndex //当前字符出现过，且位置在leftIndex的右侧，更新leftIndex
		} else {
			tmp := i - left
			if tmp > res {
				res = tmp
			}
		}
		lastIndexMap[c] = i
	}
	return res
}
