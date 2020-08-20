package p0078_Subsets

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestCode(t *testing.T) {
	assert.Equal(t, [][]int{}, subsets([]int{}))
	assert.Equal(t, [][]int{{}, {0}, {1}, {0, 1}}, subsets([]int{0, 1}))
}
