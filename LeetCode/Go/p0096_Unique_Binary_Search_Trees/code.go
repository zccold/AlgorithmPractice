package p0096_Unique_Binary_Search_Trees

func numTrees(n int) int {
	shit:=make([]int,n+1)
	shit[0]=1
	for i:=1;i<=n;i++{
		for j:=0;j<i;j++{
			shit[i]+=shit[j]*shit[i-1-j]
		}
	}
	return shit[n]
}