package p0009_Palindrome_Number

import "strconv"

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}

	//TODO: dont use itoa
	s := strconv.Itoa(x)

	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		if s[i] != s[j] {
			return false
		}
	}

	return true
}
