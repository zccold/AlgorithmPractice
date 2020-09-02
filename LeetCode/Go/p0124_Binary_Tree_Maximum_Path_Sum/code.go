package p0124_Binary_Tree_Maximum_Path_Sum

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxPathSum(root *TreeNode) int {
	res := math.MinInt64
	fuck(root, &res)
	return res
}

func fuck(root *TreeNode, res *int) int {
	if root == nil {
		return 0
	}
	left := fuck(root.Left, res)
	right := fuck(root.Right, res)
	noneSum := root.Val //左右都没有
	leftSum := left + root.Val
	rightSum := right + root.Val
	bothSum := leftSum + right
	max := max4(noneSum, leftSum, rightSum, bothSum)
	*res = max2(max, *res)
	return max3(leftSum, rightSum, noneSum)
}

func max2(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func max3(a, b, c int) int {
	sb := max2(a, b)
	return max2(sb, c)
}

func max4(a, b, c, d int) int {
	sb := max3(a, b, c)
	return max2(sb, d)
}
