package p0101_Symmetric_Tree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return fuck(root.Left, root.Right)
}

func fuck(r1, r2 *TreeNode) bool {
	if r1 == nil && r2 == nil {
		return true
	}
	if r1 != nil && r2 != nil {
		if r1.Val != r2.Val {
			return false
		} else {
			return fuck(r1.Left, r2.Right) && fuck(r1.Right, r2.Left)
		}
	}
	return false
}
