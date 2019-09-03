package p0001_Two_Sum

func twoSum(nums []int, target int) []int{
	//map的key为nums中的数字，value为它的下标
	m:=make(map[int]int,len(nums))

	for i:=0;i<len(nums);i++{
		if v,ok:=m[target-nums[i]];ok{
			//找到与当前数字匹配的数字，返回结果
			return []int{v,i}
		}else{
			//没有找到，将当前数字存入map
			m[nums[i]]=i
		}
	}

	//没有结果的情况(为了通过编译)
	return nil
}
