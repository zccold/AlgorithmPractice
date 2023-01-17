package p0279perfectsquares

import "testing"

func Test_numSquares(t *testing.T) {
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
			args: args{n: 12},
			want: 3,
		},
		{
			name: "2",
			args: args{n: 13},
			want: 2,
		},
		{
			name: "3",
			args: args{n: 51},
			want: 3,
		},
		{
			name: "4",
			args: args{n: 269},
			want: 2,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := numSquares(tt.args.n); got != tt.want {
				t.Errorf("numSquares() = %v, want %v", got, tt.want)
			}
		})
	}
}
