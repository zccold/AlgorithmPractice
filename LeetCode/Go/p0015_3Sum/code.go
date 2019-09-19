package p0015_3Sum

import "sort"

func threeSum(nums []int) [][]int {
	if len(nums) < 3 {
		return [][]int{}
	}
	sort.Ints(nums)
	res := make([][]int, 0)
	for i := 0; i < len(nums); i++ {
		//已经考虑过的数
		if i != 0 && nums[i] == nums[i-1] {
			continue
		}
		//遍历后边的数
		low := i + 1
		high := len(nums) - 1
		for low < high {
			//考虑过的数字
			if low != i+1 && nums[low-1] == nums[low] {
				low++
				continue
			}
			if high != len(nums)-1 && nums[high] == nums[high+1] {
				high--
				continue
			}
			sum := nums[i] + nums[low] + nums[high]
			if sum == 0 {
				res = append(res, []int{nums[i], nums[low], nums[high]})
				low++
				high--
			} else if sum < 0 {
				low++
			} else {
				high--
			}
		}
	}
	return res
}
