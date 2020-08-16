package p0075_Sort_Colors

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestCode(t *testing.T) {
	in0 := []int{1, 0}
	sortColors(in0)
	assert.Equal(t, []int{0, 1}, in0)
	in1 := []int{2, 0, 2, 1, 1, 0}
	sortColors(in1)
	assert.Equal(t, []int{0, 0, 1, 1, 2, 2}, in1)
	in2 := []int{0, 0}
	sortColors(in2)
	assert.Equal(t, []int{0, 0}, in2)
}
