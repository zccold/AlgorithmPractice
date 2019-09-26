package p0020_Valid_Parentheses

import "container/list"

//最简单的括号匹配，需要一个栈，垃圾go没有，用list凑合一下
func isValid(s string) bool {
	l := list.New()
	for i := 0; i < len(s); i++ {
		if (s[i] == ')') || (s[i] == ']') || (s[i] == '}') {
			if l.Len() == 0 {
				return false
			}
			shit := l.Back().Value.(byte)
			if shit == '(' {
				if s[i] != ')' {
					return false
				}
			} else if shit == '[' {
				if s[i] != ']' {
					return false
				}
			} else if shit == '{' {
				if s[i] != '}' {
					return false
				}
			}
			l.Remove(l.Back())
		} else {
			l.PushBack(s[i])
		}
	}
	return l.Len() == 0
}
