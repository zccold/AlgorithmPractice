package p0026_Remove_Duplicates_from_Sorted_Array

/*
As long as nums[i] = nums[j]nums[i]=nums[j], we increment jj to skip the duplicate.
因为数组是排序的，所以我们可以用两个指针，j是快指针，i是慢指针（实际上用的下标）
当ij相等时，把j向前，
不相等时，i向前，然后把j的值赋值到i的位置
如果那个数字只有一个，其实实在原地赋值，没啥影响
别的情况挺好理解的。。。
*/
func removeDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	i := 0
	for j := 1; j < len(nums); j++ {
		if nums[j] != nums[i] {
			i++
			nums[i] = nums[j]
		}
	}
	return i + 1
}
