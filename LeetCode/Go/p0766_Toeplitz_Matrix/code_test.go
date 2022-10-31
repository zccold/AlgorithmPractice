package p0766_Toeplitz_Matrix

import "testing"

func Test_isToeplitzMatrix(t *testing.T) {
	type args struct {
		matrix [][]int
	}
	tests := []struct {
		name string
		args args
		want bool
	}{
		{
			name: "1",
			args: args{matrix: [][]int{{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}}},
			want: true,
		},
		{
			name: "2",
			args: args{matrix: [][]int{{1, 2}, {2, 2}}},
			want: false,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := isToeplitzMatrix(tt.args.matrix); got != tt.want {
				t.Errorf("isToeplitzMatrix() = %v, want %v", got, tt.want)
			}
		})
	}
}
