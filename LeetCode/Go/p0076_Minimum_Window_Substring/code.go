package p0076_Minimum_Window_Substring

import (
	"math"
)

func minWindow(s string, t string) string {
	if len(s) < len(t) {
		return ""
	}
	var tCount [64]uint32
	for _, char := range t {
		tCount[char-'A']++
	}
	var sCount [64]uint32

	match := func() bool {
		for i := 0; i < 64; i++ {
			if sCount[i] < tCount[i] {
				return false
			}
		}
		return true
	}

	lTmp, rTmp, lengthTmp := -1, -1, math.MaxInt64 //存当前最优解
	l, r := 0, 0                                   //前闭后开
	for r <= len(s) {
		//字符数量不够直接r++
		if r-l < len(t) || !match() {
			if r == len(s) {
				break
			}
			sCount[s[r]-'A']++
			r++
			continue
		} else {
			length := r - l
			if length < lengthTmp {
				lTmp, rTmp, lengthTmp = l, r, length
				if length == len(t) {
					break
				}
			}
			sCount[s[l]-'A']--
			l++
		}
	}

	if lTmp != -1 {
		return s[lTmp:rTmp]
	}
	return ""
}
