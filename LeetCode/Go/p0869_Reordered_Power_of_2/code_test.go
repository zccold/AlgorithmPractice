package p0869_Reordered_Power_of_2

import (
	"reflect"
	"testing"
)

func Test_fuck(t *testing.T) {
	type args struct {
		n int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			name: "1",
			args: args{1},
			want: 1,
		},
		{
			name: "2",
			args: args{10},
			want: 2,
		},
		{
			name: "3",
			args: args{111},
			want: 3,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := fuck(tt.args.n); got != tt.want {
				t.Errorf("fuck() = %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_findN(t *testing.T) {
	type args struct {
		n int
	}
	tests := []struct {
		name string
		args args
		want [10]int
	}{
		{
			name: "1",
			args: args{1223334444},
			want: [10]int{0, 1, 2, 3, 4, 0, 0, 0, 0, 0},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := findN(tt.args.n); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("findN() = %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_reorderedPowerOf2(t *testing.T) {
	type args struct {
		n int
	}
	tests := []struct {
		name string
		args args
		want bool
	}{
		{
			name: "1",
			args: args{2},
			want: true,
		},
		{
			name: "2",
			args: args{61},
			want: true,
		},
		{
			name: "3",
			args: args{1204},
			want: true,
		},
		{
			name: "4",
			args: args{536870912},
			want: true,
		},
		{
			name: "5",
			args: args{1304},
			want: false,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := reorderedPowerOf2(tt.args.n); got != tt.want {
				t.Errorf("reorderedPowerOf2() = %v, want %v", got, tt.want)
			}
		})
	}
}
