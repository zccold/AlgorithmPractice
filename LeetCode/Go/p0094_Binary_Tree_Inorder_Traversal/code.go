package p0094_Binary_Tree_Inorder_Traversal

//Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func inorderTraversal(root *TreeNode) []int {
	shit := make([]int, 0, 100)
	fuck(root, &shit)
	return shit
}

func fuck(root *TreeNode, shit *[]int) {
	if root != nil {
		fuck(root.Left, shit)
		*shit = append(*shit, root.Val)
		fuck(root.Right, shit)
	}
}
