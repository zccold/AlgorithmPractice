package p0392_Is_Subsequence

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestCode(t *testing.T) {
	assert.Equal(t, true, isSubsequence("ace", "abcde"))
	assert.Equal(t, false, isSubsequence("aec", "abcde"))
}
