package p0045_Jump_Game_2

import "math"

func jump(nums []int) int {
	if len(nums) <= 1 {
		return 0
	}
	shit := make([]int, len(nums))
	for i := 1; i < len(shit); i++ {
		shit[i] = math.MaxInt64
	}
	for i := 0; i < len(shit); i++ {
		for j := 1; j <= nums[i] && i+j < len(shit); j++ {
			if shit[i]+1 < shit[i+j] {
				shit[i+j] = shit[i] + 1
			}
		}
	}
	return shit[len(shit)-1]
}
