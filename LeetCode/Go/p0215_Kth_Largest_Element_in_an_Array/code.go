package p0215_Kth_Largest_Element_in_an_Array

import (
	"sort"
)

//可以对一个长k的有序数组做插入，插入的时候用二分查找，复杂度是nlogk，但是我懒得写了
func findKthLargest(nums []int, k int) int {
	sort.Ints(nums)
	return nums[len(nums)-k]
}
