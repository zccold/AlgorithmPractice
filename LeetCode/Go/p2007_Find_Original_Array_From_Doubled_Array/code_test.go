package p2007_Find_Original_Array_From_Doubled_Array

import (
	"reflect"
	"sort"
	"testing"
)

func Test_findOriginalArray(t *testing.T) {
	type args struct {
		changed []int
	}
	tests := []struct {
		name string
		args args
		want []int
	}{
		{
			name: "1",
			args: args{[]int{1, 3, 4, 2, 6, 8}},
			want: []int{1, 3, 4},
		},
		{
			name: "2",
			args: args{[]int{6, 3, 0, 1}},
			want: []int{},
		},
		{
			name: "3",
			args: args{[]int{0}},
			want: []int{},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findOriginalArray(tt.args.changed)
			sort.Ints(got)
			if !reflect.DeepEqual(got, tt.want) {
				t.Errorf("findOriginalArray() = %v, want %v", got, tt.want)
			}
		})
	}
}
