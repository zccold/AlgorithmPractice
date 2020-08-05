package p0056_Merge_Intervals

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestShit(t *testing.T) {
	assert.Equal(t, [][]int{{1, 6}, {8, 10}, {15, 18}}, merge([][]int{{1, 3}, {2, 6}, {8, 10}, {15, 18}}))
	assert.Equal(t, [][]int{{1, 5}}, merge([][]int{{1, 4}, {4, 5}}))
}
