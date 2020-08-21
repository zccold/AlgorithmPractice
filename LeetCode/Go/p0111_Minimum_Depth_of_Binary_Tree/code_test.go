package p0111_Minimum_Depth_of_Binary_Tree

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestCode(t *testing.T) {
	root := &TreeNode{
		Val: 1,
		Left: &TreeNode{
			Val: 2,
			Left: &TreeNode{
				Val:   4,
				Left:  nil,
				Right: nil,
			},
			Right: &TreeNode{
				Val:   5,
				Left:  nil,
				Right: nil,
			},
		},
		Right: &TreeNode{
			Val:   3,
			Left:  nil,
			Right: nil,
		},
	}
	assert.Equal(t, 2, minDepth(root))
}
