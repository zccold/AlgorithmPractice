package p0046_Permutations

import "testing"

func TestCode(t *testing.T) {
	nums := []int{1, 2, 3}
	res := permute(nums)
	t.Log(res)
}
