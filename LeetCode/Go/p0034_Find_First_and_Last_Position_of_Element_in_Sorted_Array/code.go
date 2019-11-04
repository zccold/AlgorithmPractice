package p0034_Find_First_and_Last_Position_of_Element_in_Sorted_Array

//TODO: 这个乱七八糟的case检查的贼傻逼
func searchRange(nums []int, target int) []int {
	res := []int{-1, -1}
	if len(nums) == 1 {
		if nums[0] == target {
			return []int{0, 0}
		} else {
			return res
		}
	}
	l, r := 0, len(nums)-1
	for l < r {
		mid := (l + r) / 2
		if nums[l] == target {
			res[0] = l
			break
		} else if nums[mid] < target {
			l = mid + 1
		} else {
			r = mid
		}
		if l == r && nums[l] == target {
			res[0] = l
			break
		}
	}
	if res[0] == -1 {
		return res
	}
	l, r = 0, len(nums)-1
	for l < r {
		mid := (l + r + 1) / 2
		if nums[r] == target {
			res[1] = r
			return res
		} else if nums[mid] > target {
			r = mid - 1
		} else {
			l = mid
		}
		if l == r && nums[r] == target {
			res[1] = r
			return res
		}
	}
	return res
}
