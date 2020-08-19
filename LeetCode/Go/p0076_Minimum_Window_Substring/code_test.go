package p0076_Minimum_Window_Substring

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestCode(t *testing.T) {
	assert.Equal(t, "ABC", minWindow("ABC", "ABC"))
	assert.Equal(t, "", minWindow("ABCDEFG", "Z"))
	assert.Equal(t, "BANC", minWindow("ADOBECODEBANC", "ABC"))
}
