package p0114_Flatten_Binary_Tree_to_Linked_List

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func flatten(root *TreeNode) {
	if root == nil {
		return
	}
	flatten(root.Left)
	flatten(root.Right)
	//这之后，left和right应该都是一条链了，把一个接到另一个尾部即可
	tmp := root.Right
	root.Right = root.Left
	root.Left = nil
	for root.Right != nil {
		root = root.Right
	}
	root.Right = tmp
}
