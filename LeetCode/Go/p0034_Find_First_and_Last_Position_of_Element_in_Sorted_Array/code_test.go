package p0034_Find_First_and_Last_Position_of_Element_in_Sorted_Array

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

type question struct {
	para
	ans
}

// para 是参数
// one 代表第一个参数
type para struct {
	one []int
	two int
}

// ans 是答案
// one 代表第一个答案
type ans struct {
	one []int
}

func Test_Problem0034(t *testing.T) {
	ast := assert.New(t)

	qs := []question{
		{
			para{[]int{1}, 1},
			ans{[]int{0, 0}},
		},

		{
			para{[]int{5, 7, 7, 8, 8, 10}, 8},
			ans{[]int{3, 4}},
		},

		{
			para{[]int{5, 7, 7, 8, 8, 10}, 6},
			ans{[]int{-1, -1}},
		},

		{
			para{[]int{5, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 10}, 8},
			ans{[]int{3, 12}},
		},
	}

	for _, q := range qs {
		a, p := q.ans, q.para
		fmt.Printf("~~%v~~\n", p)

		ast.Equal(a.one, searchRange(p.one, p.two), "输入:%v", p)
	}
}
