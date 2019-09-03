package p0003_Longest_Substring_Without_Repeating_Characters

func lengthOfLongestSubstring(s string) int {
	lastAppeared := make(map[byte]int, 64) //字符上一次出现的index
	leftIndex := -1                        //当前计算长度时使用的最左下标
	maxLength := 0
	for i := 0; i < len(s); i++ {
		if lastIndex, ok := lastAppeared[s[i]]; ok && lastIndex >= leftIndex {
			//当前字符出现过，且位置在leftIndex的右侧，更新leftIndex
			leftIndex = lastIndex
		}
		//检查当前长度是否大于maxLength
		length := i - leftIndex
		if length > maxLength {
			maxLength = length
		}
		//更新当前字符的lastAppeared
		lastAppeared[s[i]] = i
	}
	return maxLength
}
