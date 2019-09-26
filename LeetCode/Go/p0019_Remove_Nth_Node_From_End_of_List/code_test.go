package p0019_Remove_Nth_Node_From_End_of_List

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

type question struct {
	para
	ans
}

type para struct {
	one []int
	two int
}

type ans struct {
	one []int
}

func Test_Problem0019(t *testing.T) {
	qs := []question{

		{
			para{[]int{1, 2}, 1},
			ans{[]int{1}},
		},
		{
			para{[]int{1, 2, 3, 4, 5}, 1},
			ans{[]int{1, 2, 3, 4}},
		},
		{
			para{[]int{1, 2, 3, 4, 5}, 2},
			ans{[]int{1, 2, 3, 5}},
		},
		{
			para{[]int{1}, 1},
			ans{[]int{}},
		},
	}

	for _, q := range qs {
		a, p := q.ans, q.para

		assert.Equal(t, a.one, l2s(removeNthFromEnd(s2l(p.one), p.two)), "输入:%v", p)
	}
}

// convert *ListNode to []int
func l2s(head *ListNode) []int {
	res := []int{}

	for head != nil {
		res = append(res, head.Val)
		head = head.Next
	}

	return res
}

// convert []int to *ListNode
func s2l(nums []int) *ListNode {
	if len(nums) == 0 {
		return nil
	}

	res := &ListNode{
		Val: nums[0],
	}
	temp := res
	for i := 1; i < len(nums); i++ {
		temp.Next = &ListNode{
			Val: nums[i],
		}
		temp = temp.Next
	}

	return res
}
