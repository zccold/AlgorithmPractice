package p0112_Path_Sum

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func hasPathSum(root *TreeNode, sum int) bool {
	if root == nil {
		return false
	}
	if root.Left == nil && root.Right == nil {
		return sum == root.Val
	}
	sum2 := sum - root.Val
	if sum2 == 0 && root.Left == nil && root.Right == nil {
		return true
	}
	return hasPathSum(root.Left, sum2) || hasPathSum(root.Right, sum2)
}
