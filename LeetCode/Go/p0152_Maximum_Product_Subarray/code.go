package p0152_Maximum_Product_Subarray

import "math"

func maxProduct(nums []int) int {
	res := math.MinInt64
	min := 1
	max := 1
	for _, num := range nums {
		if num < 0 {
			min, max = max, min
		}
		minTmp := min * num
		if minTmp < num {
			min = minTmp
		} else {
			min = num
		}
		maxTmp := max * num
		if maxTmp > num {
			max = maxTmp
		} else {
			max = num
		}
		if max > res {
			res = max
		}
	}
	return res
}
