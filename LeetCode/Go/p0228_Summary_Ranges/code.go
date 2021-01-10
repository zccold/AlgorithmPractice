package p0228_Summary_Ranges

import "fmt"

func summaryRanges(nums []int) []string {
	i := 0
	res := make([]string, 0)
	for i < len(nums) {
		s, r := fuck(nums, i)
		res = append(res, s)
		i = r + 1
	}
	return res
}

func fuck(nums []int, l int) (string, int) {
	r := l
	for len(nums) > r+1 && nums[r+1]-nums[r] == 1 {
		r++
	}
	if r == l {
		return fmt.Sprint(nums[l]), r
	} else {
		return fmt.Sprintf("%d->%d", nums[l], nums[r]), r
	}
}
