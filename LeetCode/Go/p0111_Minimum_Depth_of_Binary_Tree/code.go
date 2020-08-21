package p0111_Minimum_Depth_of_Binary_Tree

import (
	"container/list"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	currentLevel := list.New()
	nextLevel := list.New()
	currentLevel.PushBack(root)
	res := 1
	for currentLevel.Len() > 0 {
		e := currentLevel.Front()
		currentLevel.Remove(e)
		shit := e.Value.(*TreeNode)
		//log.Printf("remove node: %d\n", shit.Val)
		if shit.Left == nil && shit.Right == nil {
			return res
		} else {
			if shit.Left != nil {
				nextLevel.PushBack(shit.Left)
				//log.Printf("pushback node: %d\n", shit.Left.Val)
			}
			if shit.Right != nil {
				nextLevel.PushBack(shit.Right)
				//log.Printf("pushback node: %d\n", shit.Right.Val)
			}
		}
		if currentLevel.Len() == 0 {
			currentLevel = nextLevel
			nextLevel = list.New()
			res++
		}
	}
	return 0
}
