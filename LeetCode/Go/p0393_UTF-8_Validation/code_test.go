package p0393_UTF_8_Validation

import "testing"

func Test_validUtf8(t *testing.T) {
	type args struct {
		data []int
	}
	tests := []struct {
		name string
		args args
		want bool
	}{
		{
			name: "1",
			args: args{
				data: []int{197, 130, 1}, //11000101 10000010 00000001
			},
			want: true,
		},
		{
			name: "2",
			args: args{
				data: []int{235, 140, 4}, //11101011 10001100 00000100
			},
			want: false,
		},
		{
			name: "3",
			args: args{data: []int{250, 145, 145, 145, 145}}, //11111010 10010001 10010001 10010001 10010001
			want: false,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := validUtf8(tt.args.data); got != tt.want {
				t.Errorf("validUtf8() = %v, want %v", got, tt.want)
			}
		})
	}
}
