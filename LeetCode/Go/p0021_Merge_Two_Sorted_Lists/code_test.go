package p0021_Merge_Two_Sorted_Lists

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
	two []int
}

type ans struct {
	one []int
}

func Test_Problem0021(t *testing.T) {
	qs := []question{
		{
			para{[]int{},
				[]int{1, 3, 5, 7},
			},
			ans{[]int{1, 3, 5, 7}},
		},
		{
			para{[]int{1, 3, 5, 7},
				[]int{},
			},
			ans{[]int{1, 3, 5, 7}},
		},
		{
			para{[]int{1, 3, 5, 7},
				[]int{2, 4, 6, 8},
			},
			ans{[]int{1, 2, 3, 4, 5, 6, 7, 8}},
		},
		{
			para{[]int{10, 20, 30},
				[]int{1, 2, 3},
			},
			ans{[]int{1, 2, 3, 10, 20, 30}},
		},
		{
			para{[]int{1, 3, 5},
				[]int{2, 4, 6, 8, 10},
			},
			ans{[]int{1, 2, 3, 4, 5, 6, 8, 10}},
		},
		{
			para{[]int{1, 3, 5, 7, 9},
				[]int{2, 4, 6},
			},
			ans{[]int{1, 2, 3, 4, 5, 6, 7, 9}},
		},
		// 如需多个测试，可以复制上方元素。
	}

	for _, q := range qs {
		a, p := q.ans, q.para

		assert.Equal(t, a.one, l2s(mergeTwoLists(s2l(p.one), s2l(p.two))), "输入:%v", p)
	}
}

// convert *ListNode to []int
func l2s(head *ListNode) []int {
	var res []int

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
