package p0011_Container_With_Most_Water

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

type qa struct {
	q []int
	a int
}

func Test_OK(t *testing.T) {
	qaList := []qa{
		{q: []int{1, 8, 6, 2, 5, 4, 8, 3, 7}, a: 49},
		{q: []int{1, 3, 6, 4, 3, 5, 6, 7, 8, 9, 7, 5, 4, 3, 2, 1}, a: 48},
		{q: []int{1, 2, 3, 1}, a: 3},
	}
	for _, qa := range qaList {
		assert.Equal(t, qa.a, maxArea(qa.q), "input: %v", qa.q)
	}
}
