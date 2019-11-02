package p0033_Search_in_Rotated_Sorted_Array

//想不到什么好办法，看别人的答案也就是两次二分查找，一次找到翻转距离，一次正常二分查找
func search(nums []int, target int) int {
	rotated := indexOfMin(nums) /* 数组旋转了的距离 */
	size := len(nums)
	left, right := 0, size-1

	for left <= right {
		mid := (left + right) / 2
		/* nums 是 rotated，所以需要使用 rotatedMid 来获取 mid 的值 */
		rotatedMid := (rotated + mid) % size
		switch {
		case nums[rotatedMid] < target:
			left = mid + 1
		case target < nums[rotatedMid]:
			right = mid - 1
		default:
			return rotatedMid
		}
	}

	return -1
}

//假如数组是4,5,6,1,2,3 返回的下表是3(1的下标），同时也就是{4,5,6}的长度
func indexOfMin(nums []int) int {
	left, right := 0, len(nums)-1
	for left < right {
		mid := (left + right) / 2
		if nums[right] < nums[mid] {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}