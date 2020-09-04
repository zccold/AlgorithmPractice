package p0128_Longest_Consecutive_Sequence

func longestConsecutive(nums []int) int {
	tmp := make(map[int]int)
	res := 0
	for _, num := range nums {
		if _, ok := tmp[num]; ok {
			continue
		} else {
			lLen := tmp[num-1]
			rLen := tmp[num+1]
			l := lLen + rLen + 1
			if l > res {
				res = l
			}
			//把自己存一下，记下这个数字算过了，值其实无所谓
			tmp[num] = l
			//只需要更新最左和最右
			tmp[num-lLen] = l
			tmp[num+rLen] = l
		}
	}
	return res
}
