package p0062_Unique_Paths

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestCode(t *testing.T) {
	assert.Equal(t, 3, uniquePaths(3, 2))
	assert.Equal(t, 28, uniquePaths(7, 3))
	assert.Equal(t, 1, uniquePaths(1, 2))
	assert.Equal(t, 1, uniquePaths(3, 1))
}
