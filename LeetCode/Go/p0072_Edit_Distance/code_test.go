package p0072_Edit_Distance

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestCode(t *testing.T) {
	assert.Equal(t, 0, minDistance("horse", "horse"))
	assert.Equal(t, 3, minDistance("", "ros"))
	assert.Equal(t, 3, minDistance("horse", "ros"))
	assert.Equal(t, 5, minDistance("intention", "execution"))
}
