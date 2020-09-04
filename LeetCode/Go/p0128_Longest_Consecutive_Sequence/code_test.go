package p0128_Longest_Consecutive_Sequence

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestCode(t *testing.T) {
	assert.Equal(t, 4, longestConsecutive([]int{100, 4, 200, 1, 3, 2}))
	assert.Equal(t, 5, longestConsecutive([]int{4, 0, -4, -2, 2, 5, 2, 0, -8, -8, -8, -8, -1, 7, 4, 5, 5, -4, 6, 6, -3}))
}
