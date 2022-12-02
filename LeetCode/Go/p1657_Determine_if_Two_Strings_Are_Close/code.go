package p1657determineiftwostringsareclose

func closeStrings(word1 string, word2 string) bool {
	if len(word1) != len(word2) {
		return false
	}
	cf1, nf1 := freqMap(word1)
	cf2, nf2 := freqMap(word2)

	// 检查包含的字符是否相同
	if len(cf1) != len(cf2) {
		return false
	}
	for k := range cf1 {
		if _, ok := cf2[k]; !ok {
			return false
		}
	}

	// 检查次数情况是否相同
	if len(nf1) != len(nf2) {
		return false
	}
	for k, v := range nf1 {
		if nf2[k] != v {
			return false
		}
	}
	return true
}

// 字母出现个数,出现n次的字母的个数
func freqMap(word string) (map[byte]int, map[int]int) {
	cf := make(map[byte]int, 26)
	for i := range word {
		cf[word[i]]++
	}
	nf := make(map[int]int)
	for _, v := range cf {
		nf[v]++
	}
	return cf, nf
}
