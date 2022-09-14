package p1457_Pseudo_Palindromic_Paths_in_a_Binary_Tree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func pseudoPalindromicPaths(root *TreeNode) int {
	nums := [10]int{}
	res := 0
	var fuck func(*TreeNode)
	fuck = func(node *TreeNode) {
		// 记录节点值
		nums[node.Val]++

		if node.Left == nil && node.Right == nil {
			shit := 0
			for _, num := range nums {
				if num%2 == 1 {
					shit++
				}
			}
			if shit <= 1 {
				res++
			}
			//fmt.Println("node", node.Val, nums)
		}
		if node.Left != nil {
			fuck(node.Left)
		}
		if node.Right != nil {
			fuck(node.Right)
		}
		//删除节点值
		nums[node.Val]--
	}
	fuck(root)
	return res
}
