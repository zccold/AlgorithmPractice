package p0064_Minimum_Path_Sum

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestMinPathSum(t *testing.T) {
	in := [][]int{
		{1, 3, 1},
		{1, 5, 1},
		{4, 2, 1},
	}
	assert.Equal(t, 7, minPathSum(in))
}
