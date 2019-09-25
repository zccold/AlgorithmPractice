package p0018_4Sum

import "sort"

func fourSum(nums []int, target int) [][]int {
	if len(nums) < 4 {
		return [][]int{}
	}
	sort.Ints(nums)
	res := make([][]int, 0)
	for i := 0; i < len(nums)-3; i++ {
		//已经考虑过的数
		if i != 0 && nums[i] == nums[i-1] {
			continue
		}
		for j := i + 1; j < len(nums)-2; j++ {
			//已经考虑过的数
			if j != i+1 && nums[j] == nums[j-1] {
				continue
			}
			//遍历后边的数
			low := j + 1
			high := len(nums) - 1
			for low < high {
				//考虑过的数字
				if low != j+1 && nums[low-1] == nums[low] {
					low++
					continue
				}
				if high != len(nums)-1 && nums[high] == nums[high+1] {
					high--
					continue
				}
				sum := nums[i] + nums[j] + nums[low] + nums[high]
				if sum == target {
					res = append(res, []int{nums[i], nums[j], nums[low], nums[high]})
					low++
					high--
				} else if sum < target {
					low++
				} else {
					high--
				}
			}
		}
	}
	return res
}
