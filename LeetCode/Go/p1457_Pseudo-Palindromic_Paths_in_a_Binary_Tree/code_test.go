package p1457_Pseudo_Palindromic_Paths_in_a_Binary_Tree

import "testing"

func Test_pseudoPalindromicPaths(t *testing.T) {
	type args struct {
		root *TreeNode
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			name: "1",
			args: args{root: &TreeNode{
				Val: 2,
				Left: &TreeNode{
					Val:   3,
					Left:  &TreeNode{Val: 3},
					Right: &TreeNode{Val: 1},
				},
				Right: &TreeNode{
					Val:   1,
					Left:  nil,
					Right: &TreeNode{Val: 1},
				},
			}},
			want: 2,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := pseudoPalindromicPaths(tt.args.root); got != tt.want {
				t.Errorf("pseudoPalindromicPaths() = %v, want %v", got, tt.want)
			}
		})
	}
}
