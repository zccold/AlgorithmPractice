package p0057_Insert_Interval

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_insert(t *testing.T) {
	type args struct {
		intervals   [][]int
		newInterval []int
	}
	tests := []struct {
		name string
		args args
		want [][]int
	}{
		{
			name: "1",
			args: args{
				intervals:   [][]int{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}},
				newInterval: []int{4, 8},
			},
			want: [][]int{{1, 2}, {3, 10}, {12, 16}},
		},
		{
			name: "2",
			args: args{
				intervals:   [][]int{{1, 2}, {6, 7}, {8, 10}, {12, 16}},
				newInterval: []int{3, 5},
			},
			want: [][]int{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			assert.Equalf(t, tt.want, insert(tt.args.intervals, tt.args.newInterval), "insert(%v, %v)", tt.args.intervals, tt.args.newInterval)
		})
	}
}
