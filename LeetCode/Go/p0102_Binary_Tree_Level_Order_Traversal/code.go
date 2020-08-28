package p0102_Binary_Tree_Level_Order_Traversal

import "container/list"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	currentLevel := list.New()
	nextLevel := list.New()
	currentLevel.PushBack(root)
	var res [][]int
	var tmp []int
	tmp = make([]int, 0)
	for currentLevel.Len() > 0 {
		e := currentLevel.Front()
		currentLevel.Remove(e)
		shit := e.Value.(*TreeNode)
		tmp = append(tmp, shit.Val)
		if shit.Left != nil {
			nextLevel.PushBack(shit.Left)
		}
		if shit.Right != nil {
			nextLevel.PushBack(shit.Right)
		}

		if currentLevel.Len() == 0 {
			currentLevel = nextLevel
			nextLevel = list.New()
			res = append(res, tmp)
			tmp = make([]int, 0)
		}
	}
	return res
}
