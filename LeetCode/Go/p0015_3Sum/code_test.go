package p0015_3Sum

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

type question struct {
	q []int
	a [][]int
}

func Test_OK(t *testing.T) {

	qs := []question{
		{
			q: []int{-1, 0, 1, 2, -1, -4},
			a: [][]int{{-1, -1, 2}, {-1, 0, 1}},
		},
	}

	for _, qa := range qs {
		assert.Equal(t, qa.a, threeSum(qa.q), "输入:%v", qa.q)
	}
}
