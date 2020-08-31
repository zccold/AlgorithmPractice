package p0105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	fmt.Printf("pre: %v, in: %v\n", preorder, inorder)
	if len(preorder) == 0 {
		return nil
	}
	rootVal := preorder[0]
	root := &TreeNode{Val: rootVal}
	var leftPreorder, leftInorder, rightPreorder, rightInorder []int
	for i := range inorder {
		if inorder[i] == rootVal {
			leftInorder = inorder[:i]
			leftPreorder = preorder[1 : len(leftInorder)+1]
			rightInorder = inorder[i+1:]
			rightPreorder = preorder[len(preorder)-len(rightInorder):]
			break
		}
	}
	root.Left = buildTree(leftPreorder, leftInorder)
	root.Right = buildTree(rightPreorder, rightInorder)
	return root
}
