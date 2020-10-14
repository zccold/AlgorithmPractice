package p0152_Maximum_Product_Subarray

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestCode(t *testing.T) {
	assert.Equal(t, 4, maxProduct([]int{3, -1, 4}))
	assert.Equal(t, 0, maxProduct([]int{0}))
	assert.Equal(t, 0, maxProduct([]int{0, 0}))
	assert.Equal(t, 0, maxProduct([]int{0, -1}))
}
