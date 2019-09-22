package p0016_3Sum_Closest

import "sort"

func threeSumClosest(nums []int, target int) int {
	//这里排序会破坏原数组的，只是做题不用管而已
	sort.Ints(nums)
	result := nums[0] + nums[1] + nums[2]
	for i := 0; i < len(nums); i++ {
		//把剩余的部分单独切片了一下，或者遍历的时候从i+1开始，都一样
		bar := nums[i+1:]
		for p, q := 0, len(bar)-1; p < q; {
			//如果能找到和为target的
			if bar[p]+bar[q]+nums[i] == target {
				return target
			}
			//如果找到比当前最优解更接近的
			if CalcAbs(bar[p]+bar[q]+nums[i]-target) < CalcAbs(result-target) {
				result = bar[p] + bar[q] + nums[i]
			}
			//大了向左，小了向右
			if bar[p]+bar[q]+nums[i]-target > 0 {
				q--
			} else {
				p++
			}
		}
	}
	return result
}

//神奇的取绝对值，我也忘了从哪抄的了
func CalcAbs(a int) (ret int) {
	ret = (a ^ a>>31) - a>>31
	return
}
