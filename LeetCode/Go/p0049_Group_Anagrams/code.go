package p0049_Group_Anagrams

import "sort"

func groupAnagrams(strs []string) [][]string {
	resMap := make(map[string][]string)
	sortStr := func(str string) string {
		rs := []rune(str)
		sort.Slice(rs, func(i, j int) bool {
			return rs[i] < rs[j]
		})
		return string(rs)
	}
	for _, str := range strs {
		k := sortStr(str)
		if shit, ok := resMap[k]; ok {
			resMap[k] = append(shit, str)
		} else {
			resMap[k] = []string{str}
		}
	}
	res := make([][]string, 0)
	for _, v := range resMap {
		res = append(res, v)
	}
	return res
}
