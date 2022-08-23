package p0342_Power_of_Four

import "testing"

func Test_isPowerOfFour(t *testing.T) {
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
			args: args{n: 0},
			want: false,
		},
		{
			name: "2",
			args: args{n: 1},
			want: true,
		},
		{
			name: "3",
			args: args{n: 16},
			want: true,
		},
		{
			name: "4",
			args: args{n: -1},
			want: false,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := isPowerOfFour(tt.args.n); got != tt.want {
				t.Errorf("isPowerOfFour() = %v, want %v", got, tt.want)
			}
		})
	}
}
