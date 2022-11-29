package p0039_Combination_Sum

import (
	"reflect"
	"sort"
	"testing"
)

func Test_combinationSum(t *testing.T) {
	type args struct {
		candidates []int
		target     int
	}
	tests := []struct {
		name string
		args args
		want [][]int
	}{
		{
			name: "1",
			args: args{
				candidates: []int{7, 3, 2},
				target:     18,
			},
			want: [][]int{
				{2, 2, 7, 7},
				{2, 3, 3, 3, 7},
				{2, 2, 2, 2, 3, 7},
				{3, 3, 3, 3, 3, 3},
				{2, 2, 2, 3, 3, 3, 3},
				{2, 2, 2, 2, 2, 2, 3, 3},
				{2, 2, 2, 2, 2, 2, 2, 2, 2},
			},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := combinationSum(tt.args.candidates, tt.args.target)
			sort.Slice(got, func(i, j int) bool { return sliceLess(got[i], got[j]) })
			sort.Slice(tt.want, func(i, j int) bool { return sliceLess(tt.want[i], tt.want[j]) })
			if !reflect.DeepEqual(got, tt.want) {
				t.Errorf("combinationSum() = %v, want %v", got, tt.want)
			}
		})
	}
}

func sliceLess(a, b []int) bool {
	if len(a) == len(b) {
		for i := range a {
			if a[i] < b[i] {
				return true
			}
		}
		return false
	}

	return len(a) < len(b)
}
