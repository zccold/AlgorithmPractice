package p0013_Roman_to_Integer

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

type qa struct {
	a int
	q string
}

func Test_OK(t *testing.T) {
	qaList := []qa{
		{a: 3, q: "III"},
		{a: 4, q: "IV"},
		{a: 9, q: "IX"},
		{a: 58, q: "LVIII"},
		{a: 1994, q: "MCMXCIV"},
		{a: 1437, q: "MCDXXXVII"},
		{a: 3333, q: "MMMCCCXXXIII"},
	}
	for _, qa := range qaList {
		assert.Equal(t, qa.a, romanToInt(qa.q), "input: %v", qa.q)
	}
}
