package p0057_Insert_Interval

func insert(intervals [][]int, newInterval []int) [][]int {
	if len(intervals) == 0 {
		return [][]int{newInterval}
	}

	res := make([][]int, 0)
	tmp := newInterval
	for i := 0; i < len(intervals); i++ {
		shit := intervals[i]
		if shit[0] > tmp[1] {
			res = append(res, tmp)
			tmp = shit
		} else if shit[1] < tmp[0] {
			res = append(res, shit)
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
