package p0543_Diameter_of_Binary_Tree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func diameterOfBinaryTree(root *TreeNode) int {
	res := 0
	var heightAndDiameterOfBinaryTree func(root *TreeNode) int
	heightAndDiameterOfBinaryTree = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l := heightAndDiameterOfBinaryTree(root.Left)
		r := heightAndDiameterOfBinaryTree(root.Right)
		if l+r > res {
			res = l + r
		}
		if l > r {
			return l + 1
		}
		return r + 1
	}
	heightAndDiameterOfBinaryTree(root)
	return res
}
