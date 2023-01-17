package p0057_Insert_Interval

func insert(intervals [][]int, newInterval []int) [][]int {
	if len(intervals) == 0 {
		return [][]int{newInterval}
	}

	res := make([][]int, 0)
	tmp := newInterval
	flag := false // 是否通过情况1直接把后一半的值都append进去了
	for i := 0; i < len(intervals); i++ {
		shit := intervals[i]
		// 给tmp找到了合适的位置
		if shit[0] > tmp[1] {
			res = append(res, tmp)
			// 后边的直接都放进去，不用再比较了
			res = append(res, intervals[i:]...)
			flag = true
			break
		} else if shit[1] < tmp[0] {
			// 还不到tmp的位置
			res = append(res, shit)
		} else {
			// tmp和现在这个有重叠，合并之后需要继续拿着，因为还可能和后边的重叠
			tmp = mergeTwo(tmp, shit)
		}
	}
	if !flag {
		res = append(res, tmp)
	}
	return res
}

// 有重叠
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
