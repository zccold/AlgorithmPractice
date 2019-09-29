package p0022_Generate_Parentheses

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

type question struct {
	para
	ans
}

type para struct {
	one int
}

type ans struct {
	one []string
}

func Test_Problem0022(t *testing.T) {
	ast := assert.New(t)

	qs := []question{
		{
			para{2},
			ans{[]string{
				"(())",
				"()()",
			}},
		},
		{
			para{3},
			ans{[]string{
				"((()))",
				"(()())",
				"(())()",
				"()(())",
				"()()()",
			}},
		},
		{
			para{4},
			ans{[]string{
				"(((())))",
				"((()()))",
				"((())())",
				"((()))()",
				"(()(()))",
				"(()()())",
				"(()())()",
				"(())(())",
				"(())()()",
				"()((()))",
				"()(()())",
				"()(())()",
				"()()(())",
				"()()()()",
			}},
		},
	}

	for _, q := range qs {
		a, p := q.ans, q.para
		fmt.Printf("~~%v~~\n", p)

		ast.Equal(a.one, generateParenthesis(p.one), "输入:%v", p)
	}
}

func Benchmark_generateParenthesis(b *testing.B) {
	for i := 0; i < b.N; i++ {
		generateParenthesis(10)
	}
}
