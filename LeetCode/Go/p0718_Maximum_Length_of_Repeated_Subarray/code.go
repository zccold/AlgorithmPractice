package p0718_Maximum_Length_of_Repeated_Subarray

func findLength(nums1 []int, nums2 []int) int {
	// shit[i][j]表示nums1前i个 和 nums2前j个，尾部对齐，往前数，有多少个匹配
	shit := make([][]int, len(nums1)+1)
	for i := range shit {
		shit[i] = make([]int, len(nums2)+1)
	}

	max := 0
	for i := 1; i < len(shit); i++ {
		line := shit[i]
		for j := 1; j < len(line); j++ {
			if nums1[i-1] == nums2[j-1] {
				tmp := shit[i-1][j-1] + 1
				shit[i][j] = tmp
				if tmp > max {
					max = tmp
				}
			}
		}
	}

	return max
}
