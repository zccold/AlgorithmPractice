package p0077_Combinations

func combine(n int, k int) [][]int {
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		nums[i] = i + 1
	}
	res := make([][]int, 0)
	tmp := make([]int, 0, k)
	fuck(&res, k, nums, tmp)
	return res
}

func fuck(res *[][]int, k int, nums []int, tmp []int) {
	//fmt.Printf("nums: %v\ttmp: %v\tlen: %d\tcap: %d\n", nums, tmp, len(tmp), cap(tmp))
	if len(tmp) == k {
		ttmp := make([]int, len(tmp))
		copy(ttmp, tmp)
		*res = append(*res, ttmp)
		return
	}
	tmp = append(tmp, 0)
	for i, num := range nums {
		//如果i以及右边的数字不够了，肯定凑不出来
		if len(nums)-i < k-len(tmp) {
			break
		}
		tmp[len(tmp)-1] = num
		fuck(res, k, nums[i+1:], tmp)
	}
}
