package p0014_Longest_Common_Prefix

//选最短的，然后一个一个比较，太简单懒得写注释了
func longestCommonPrefix(strs []string) string {
	short := shortest(strs)

	for i := 0; i < len(short); i++ {
		for j := 0; j < len(strs); j++ {
			if strs[j][i] != short[i] {
				return strs[j][:i]
			}
		}
	}

	return short
}

func shortest(strs []string) string {
	if len(strs) == 0 {
		return ""
	}

	res := strs[0]
	for _, s := range strs {
		if len(res) > len(s) {
			res = s
		}
	}

	return res
}
