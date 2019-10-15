package p0027_Remove_Element

/*和上一个题一样，两个指针
一开始不知道咋想的，觉得i对应的元素也需要判断
其实直接覆盖就是了
不管是不是val，早就过去了的
*/
func removeElement(nums []int, val int) int {
	if nums == nil || len(nums) == 0 {
		return 0
	}
	i := 0
	for j := 0; j < len(nums); j++ {
		if nums[j] != val {
			nums[i] = nums[j]
			i++
		}
	}
	return i
}
