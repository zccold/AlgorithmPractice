package p0032_Longest_Valid_Parentheses

/*
In this approach, we make use of two counters left and right.
First, we start traversing the string from the left towards the right and for every ‘(’ encountered,
we increment the left counter and for every ‘)’ encountered, we increment the rightright counter.
Whenever left becomes equal to right,
we calculate the length of the current valid string and keep track of maximum length substring found so far.
If right becomes greater than left we reset left and right to 0.

Next, we start traversing the string from right to left and similar procedure is applied.

照着官方解题思路做的，反证一下原理
假设算法找出了一段是x，而他错了，那么可能是这样(x)，或者()x
(x)是不可能的，因为不可能在x之前那个括号重置
()x的话，显然扫完x之后会继续扫出最大值

不反证有点说不清，
第一，要说明在x之前，算法一定重置自己
假如向右扫没重置，那么说明x之前是个（或者虽然是）但是数量还不够，
如果是（，那么x之后必然是个（，否则x不是最长，那么向左的时候，必然会扫出来x
原谅我懒得详细说了……就这样吧
*/
func longestValidParentheses(s string) int {
	left, right, res := 0, 0, 0
	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			left++
		} else {
			right++
		}
		if right == left {
			if 2*right > res {
				res = 2 * right
			}
		} else if right > left {
			left, right = 0, 0
		}
	}
	left, right = 0, 0
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == '(' {
			left++
		} else {
			right++
		}
		if right == left {
			if 2*right > res {
				res = 2 * right
			}
		} else if right < left {
			left, right = 0, 0
		}
	}
	return res
}
