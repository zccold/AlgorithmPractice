package p0004_Median_of_Two_Sorted_Arrays

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

type para struct {
	one []int
	two []int
}

type ans struct {
	one float64
}

type question struct {
	p para
	a ans
}

func Test_OK(t *testing.T) {
	ast := assert.New(t)

	qs := []question{
		{
			p: para{
				one: []int{1, 3},
				two: []int{2},
			},
			a: ans{2},
		},
		{
			p: para{
				one: []int{1, 2},
				two: []int{3, 4},
			},
			a: ans{2.5},
		},
		{
			p: para{
				one: []int{1, 2},
				two: []int{3},
			},
			a: ans{2},
		},
	}
	for _, q := range qs {
		a, p := q.a, q.p
		ast.Equal(a.one, findMedianSortedArrays(p.one, p.two), "输入:%v", p)
	}
}
