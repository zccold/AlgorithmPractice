package p0374_Guess_Number_Higher_or_Lower

import "testing"

func Test_guessNumber(t *testing.T) {
	type args struct {
		n int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			name: "",
			args: args{n: 999},
			want: 100,
		},
		{
			name: "",
			args: args{999},
			want: 99,
		},
		{
			name: "",
			args: args{n: 888},
			want: 100,
		},
		{
			name: "",
			args: args{888},
			want: 99,
		},
		{
			name: "",
			args: args{n: 1},
			want: 1,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			buildGuess(tt.want)
			if got := guessNumber(tt.args.n); got != tt.want {
				t.Errorf("guessNumber() = %v, want %v", got, tt.want)
			}
		})
	}
}
