package p0016_3Sum_Closest

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
	one int
}

func Test_OK(t *testing.T) {
	qs := []question{

		{
			para{[]int{-1, 2, 1, -4}, 1},
			ans{2},
		},
		{
			para{[]int{-1, 2, 2, 2, 2, 2, 2, 2, 1, -4}, 1},
			ans{0},
		},
		{
			para{[]int{-1, 2, 2, 2, 2, 2, 2, 2, 1, -4}, 0},
			ans{0},
		},
	}

	for _, q := range qs {
		a, p := q.ans, q.para
		assert.Equal(t, a.one, threeSumClosest(p.one, p.two), "输入:%v", p)
	}
}
