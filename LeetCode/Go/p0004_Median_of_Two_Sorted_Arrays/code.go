package p0004_Median_of_Two_Sorted_Arrays

import "math"

//其实就是归并，但是不需要做完整的归并，也不需要保存结果
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	//两个要选出来的数排在第几个（从1开始）
	index1 := (len(nums1) + len(nums2) + 1) / 2
	index2 := (len(nums1) + len(nums2) + 2) / 2
	var n1, n2 int
	n1 = math.MinInt64
	//候选数的下标，当i=0,j=0时，意味着已选出0个数，即将选出第1个数
	i, j := 0, 0
	//当前选出的数字
	var now int
	for {
		//当有一个数组耗尽时，直接从另一个数组取
		//如果数组还有很长，此处相比一个一个找过去可以节约时间
		//提交一下试了试耗时毫无变化，但是我懒得改回去了
		//TODO:代码有点乱
		if i == len(nums1) {
			if n1 == math.MinInt64 {
				n1 = nums2[index1-len(nums1)-1]
			}
			n2 = nums2[index2-len(nums1)-1]
			break
		} else if j == len(nums2) {
			if n1 == math.MinInt64 {
				n1 = nums1[index1-len(nums2)-1]
			}
			n2 = nums1[index2-len(nums2)-1]
			break
		} else {
			if nums1[i] < nums2[j] {
				now = nums1[i]
				i++
			} else {
				now = nums2[j]
				j++
			}
		}
		//此处挺乱，因为i+j刚刚加了1，所以now为选出的第i+j个数字
		if i+j == index1 {
			n1 = now
		}
		if i+j == index2 {
			n2 = now
			break
		}
	}
	return float64(n1+n2) / 2
}
