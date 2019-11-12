package p0035_Search_Insert_Position

func searchInsert(nums []int, target int) int {
	i, j := 0, len(nums)-1
	//二分查找的时候返回范围到不了j+1
	if target > nums[j] {
		return j + 1
	}
	for i < j {
		mid := (i + j) / 2
		if nums[mid] == target {
			return mid
		} else if nums[mid] < target {
			i = mid + 1
		} else {
			j = mid
		}
	}
	return j
}
