package p0005_Longest_Palindromic_Substring

import "strings"

//TODO：研究下高级算法
//TODO:添加注释
func longestPalindrome(s string) string {
	if len(s) == 0 {
		return ""
	}
	var sb strings.Builder
	sb.Grow(len(s)*2 + 1)
	for i := 0; i < len(s); i++ {
		if i == len(s)-1 {
			sb.Write([]byte{'#', s[i], '#'})
		} else {
			sb.Write([]byte{'#', s[i]})
		}
	}
	bigStr := sb.String()
	var maxMiddle, maxRadius int
	for middle := 0; middle < len(bigStr); middle++ {
		for radius := 0; ; radius++ {
			if middle-radius < 0 || middle+radius >= len(bigStr) || bigStr[middle-radius] != bigStr[middle+radius] {
				break
			} else if radius > maxRadius {
				maxMiddle = middle
				maxRadius = radius
			}
		}
	}
	return strings.Replace(bigStr[maxMiddle-maxRadius:maxMiddle+maxRadius+1], "#", "", -1)
}
