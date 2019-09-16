package p0010_Regular_Expression_Matching

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

type qa struct {
	s string
	p string
	a bool
}

func Test_OK(t *testing.T) {
	qaList := []qa{
		{s: "aa", p: "a", a: false},
		{s: "aa", p: "a*", a: true},
		{s: "ab", p: ".*", a: true},
		{s: "aab", p: "c*a*b", a: true},
		{s: "mississippi", p: "mis*is*p*.", a: false},
	}
	for _, qa := range qaList {
		assert.Equal(t, qa.a, isMatch(qa.s, qa.p), "s: %s, p: %s", qa.s, qa.p)
	}
}
