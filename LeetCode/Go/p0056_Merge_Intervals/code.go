package p0056_Merge_Intervals

import "sort"

func merge(intervals [][]int) [][]int {
	if len(intervals) == 0 {
		return [][]int{}
	}
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	res := make([][]int, 0)
	tmp := intervals[0]
	for i := 1; i < len(intervals); i++ {
		shit := intervals[i]
		if shit[0] > tmp[1] {
			res = append(res, tmp)
			tmp = shit
		} else {
			tmp = mergeTwo(tmp, shit)
		}
	}
	res = append(res, tmp)
	return res
}

//有重叠
func mergeTwo(i1, i2 []int) []int {
	left := i1[0]
	if left > i2[0] {
		left = i2[0]
	}
	right := i1[1]
	if right < i2[1] {
		right = i2[1]
	}
	return []int{left, right}
}
