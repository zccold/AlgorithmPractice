package p0113_Path_Sum_2

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func pathSum(root *TreeNode, sum int) [][]int {
	res := make([][]int, 0)
	fuck(root, sum, []int{}, &res)
	return res
}

func fuck(root *TreeNode, sum int, tmp []int, res *[][]int) {
	if root == nil {
		return
	}
	if root.Left == nil && root.Right == nil && sum == root.Val {
		tmpCopy := make([]int, len(tmp)+1)
		copy(tmpCopy, tmp)
		tmpCopy[len(tmp)] = root.Val
		*res = append(*res, tmpCopy)
	}
	tmp = append(tmp, root.Val)
	sum2 := sum - root.Val
	fuck(root.Left, sum2, tmp, res)
	fuck(root.Right, sum2, tmp, res)
}
