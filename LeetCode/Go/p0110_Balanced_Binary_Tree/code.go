package p0110_Balanced__Binary_Tree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isBalanced(root *TreeNode) bool {
	f, _ := fuck(root)
	return f
}

func fuck(root *TreeNode) (bool, int) {
	if root == nil {
		return true, 0
	} else if root.Left == nil && root.Right == nil {
		return true, 1
	} else {
		lFlag, lDepth := fuck(root.Left)
		if !lFlag {
			return false, -1
		}
		rFlag, rDepth := fuck(root.Right)
		if !rFlag {
			return false, -1
		}
		//交换一下，后边好写
		if lDepth > rDepth {
			lDepth, rDepth = rDepth, lDepth
		}
		if rDepth-lDepth > 1 {
			return false, -1
		} else {
			return true, rDepth
		}
	}
}
