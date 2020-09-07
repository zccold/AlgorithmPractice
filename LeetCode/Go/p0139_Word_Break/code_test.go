package p0139_Word_Break

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestCode(t *testing.T) {
	assert.Equal(t, true, wordBreak("ab", []string{"a", "b"}))
	assert.Equal(t, true, wordBreak("leetcode", []string{"leet", "code"}))
	assert.Equal(t, true, wordBreak("applepenapple", []string{"apple", "pen"}))
	assert.Equal(t, false, wordBreak("catsandog", []string{"cats", "dog", "sand", "and", "cat"}))
}
