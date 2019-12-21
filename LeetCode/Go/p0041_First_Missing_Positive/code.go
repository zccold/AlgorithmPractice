package p0041_First_Missing_Positive

func firstMissingPositive(nums []int) int {
	//每次操作，将本数字放到正确的位置上去
	for i := 0; i < len(nums); i++ {
		//nums[nums[i]-1] != nums[i]并不能改成nums[i]!=i+1，因为可能有重复的数字，会死循环的
		for nums[i] > 0 && nums[i] <= len(nums) && nums[nums[i]-1] != nums[i] {
			nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]
		}
	}
	for k, v := range nums {
		if v != k+1 {
			return k + 1
		}
	}
	return len(nums) + 1
}
