package p0031_Next_Permutation

/*
x345，只有排列到了x543这种情况时，才会需要动x
而且还需要看345中是否有能大于x的，否则到了x543这个情况，还是得找下一位的
然后把x和345中大于x且最小的互换，此时后边三个数组肯定还是降序
只需要给他们翻转，从最大排列变成最小排列即可
*/
func nextPermutation(nums []int) {
	for i := len(nums) - 2; i >= 0; i-- {
		if nums[i] < nums[i+1] {
			for j := len(nums) - 1; j > i; j-- {
				if nums[j] > nums[i] {
					nums[i], nums[j] = nums[j], nums[i]
					reverse(nums, i+1, len(nums)-1)
					return
				}
			}
		}
	}
	reverse(nums, 0, len(nums)-1)
}

func reverse(nums []int, i int, j int) {
	//没有做检查
	for i < j {
		nums[i], nums[j] = nums[j], nums[i]
		i++
		j--
	}
}
