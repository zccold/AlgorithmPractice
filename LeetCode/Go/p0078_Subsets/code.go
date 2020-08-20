package p0078_Subsets

func subsets(nums []int) [][]int {
	if len(nums) == 0 {
		return [][]int{}
	}
	resLen := 1
	for i := 0; i < len(nums); i++ {
		resLen *= 2
	}
	res := make([][]int, 0, resLen)
	res = append(res, []int{})
	for _, num := range nums {
		lenNow := len(res)
		for i := 0; i < lenNow; i++ {
			withOutNum := res[i]
			withNum := make([]int, len(withOutNum), len(withOutNum)+1)
			copy(withNum, withOutNum)
			withNum = append(withNum, num)
			res = append(res, withNum)
		}
	}
	return res
}
