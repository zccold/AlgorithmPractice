package p0012_Integer_to_Roman

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

type qa struct {
	q int
	a string
}

func Test_OK(t *testing.T) {
	qaList := []qa{
		{q: 3, a: "III"},
		{q: 4, a: "IV"},
		{q: 9, a: "IX"},
		{q: 58, a: "LVIII"},
		{q: 1994, a: "MCMXCIV"},
		{q: 1437, a: "MCDXXXVII"},
		{q: 3333, a: "MMMCCCXXXIII"},
	}
	for _, qa := range qaList {
		assert.Equal(t, qa.a, intToRoman(qa.q), "input: %v", qa.q)
	}
}
