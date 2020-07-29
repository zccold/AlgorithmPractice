package p0046_Permutations

func permute(nums []int) [][]int {
	if len(nums) == 0 {
		return [][]int{}
	}
	result := make([][]int, 0, factorial(len(nums)))
	backtrack(&result, []int{}, nums)
	return result
}

func backtrack(res *[][]int, tmp []int, nums []int) {
	if len(nums) == 0 {
		*res = append(*res, tmp)
		return
	}
	for i, num := range nums {
		tmpp := make([]int, len(tmp)+1)
		copy(tmpp, tmp)
		tmpp[len(tmp)] = num
		numsLeft := make([]int, len(nums))
		copy(numsLeft, nums)
		numsLeft = append(numsLeft[:i], numsLeft[i+1:]...)
		backtrack(res, tmpp, numsLeft)
	}
}

func factorial(n int) int {
	if n == 0 {
		return 1
	}
	return n * factorial(n-1)
}
