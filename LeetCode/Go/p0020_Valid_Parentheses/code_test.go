package p0020_Valid_Parentheses

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

type question struct {
	para
	ans
}

// para 是参数
// one 代表第一个参数
type para struct {
	one string
}

type ans struct {
	one bool
}

func Test_Problem0020(t *testing.T) {
	qs := []question{

		{
			para{"()[]{}"},
			ans{true},
		},
		{
			para{"(]"},
			ans{false},
		},
		{
			para{"({[]})"},
			ans{true},
		},
		{
			para{"(){[({[]})]}"},
			ans{true},
		},
		{
			para{"((([[[{{{"},
			ans{false},
		},
		{
			para{"(())]]"},
			ans{false},
		},
	}

	for _, q := range qs {
		a, p := q.ans, q.para
		assert.Equal(t, a.one, isValid(p.one), "输入:%v", p)
	}
}
