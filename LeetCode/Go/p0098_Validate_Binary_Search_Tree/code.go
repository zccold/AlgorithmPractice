package p0098_Validate_Binary_Search_Tree

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isValidBST(root *TreeNode) bool {
	tmp := new(int)
	*tmp = math.MinInt64
	return fuck(root, tmp)
}

func fuck(root *TreeNode, tmp *int) bool {
	if root == nil {
		return true
	}
	l := fuck(root.Left, tmp)
	if !l {
		return false
	}
	if root.Val > *tmp {
		*tmp = root.Val
	} else {
		return false
	}
	return fuck(root.Right, tmp)
}
