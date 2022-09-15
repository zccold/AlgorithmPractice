package p2007_Find_Original_Array_From_Doubled_Array

import "sort"

func findOriginalArray(changed []int) []int {
	sort.Ints(changed)
	indexMap := make(map[int]int)
	for _, num := range changed {
		indexMap[num]++
	}

	res := make([]int, 0)
	for _, num := range changed {
		count := indexMap[num]
		if count == 0 {
			continue
		}
		indexMap[num]--

		num2 := num * 2
		num2count := indexMap[num2]
		if num2count == 0 {
			return []int{}
		}
		indexMap[num2]--

		res = append(res, num)
	}
	return res
}
