package p0028_Implement_strStr

//BMH
func strStr(haystack string, needle string) int {
	n := len(haystack)
	m := len(needle)
	if m == 0 {
		return 0
	}
	//坏字符后移距离，为字符最后一次出现位置到字符串尾部的距离
	//有点没想明白的是这样如果
	//babbbacxxxxxxxx
	//abbbbac
	//匹配到a，只能往后动一位，感觉可能是我没细看原来的BM算法，或许是好后缀里的内容
	shift := make(map[byte]int)
	for k := 0; k <= m-2; k++ {
		shift[needle[k]] = m - 1 - k
	}
	s := 0 //偏移量
	for s <= n-m {
		j := m - 1 //进行匹配的部分字符串尾部
		for haystack[s+j] == needle[j] {
			j--
			if j < 0 {
				return s
			}
		}
		offset, ok := shift[haystack[s+m-1]]
		if !ok {
			offset = m
		}
		s = s + offset
	}
	return -1
}
