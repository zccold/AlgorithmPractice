package p0075_Sort_Colors

//写完又想了想，1不一定要这么分开，第一遍可以1放到和0一组，这个中间分割线就没这么蛋疼了，其实就是快排思想，最优中间值是已知的
func sortColors(nums []int) {
	//log.Println(nums)
	i, j := 0, len(nums)-1
	//先把0和2排好，形成前半段是0和1，后半段是1和2的结构
	for i < j {
		if nums[i] == 1 {
			i++
		} else if nums[j] == 1 {
			j--
		} else if nums[i] == 2 && nums[j] == 0 {
			nums[i], nums[j] = nums[j], nums[i]
			i++
			j--
		} else if nums[i] == 2 {
			j--
		} else /*nums[i]==0*/ {
			i++
		}
	}
	//log.Println(nums)

	//这个地方懒得动脑子了，应该可以控制上一步的行为来稳定获取的
	shit := -1
	if i > j {
		shit = i
	} else {
		for index := i; index < len(nums); index++ {
			if nums[index] == 2 {
				shit = index
				break
			}
		}
		if shit == -1 {
			shit = len(nums)
		}
	}
	//log.Printf("i: %d;j: %d;shit: %d\n", i, j, shit)

	sortTwoNumSlice := func(nums []int, n1 int, n2 int) {
		//log.Printf("twoNumsSliceSord: nums: %v, n1: %d, n2: %d\n", nums, n1, n2)
		for i, j := 0, len(nums)-1; i < j; {
			if nums[i] == n1 {
				i++
			} else if nums[j] == n2 {
				j--
			} else {
				nums[i], nums[j] = nums[j], nums[i]
				i++
				j--
			}
		}
	}

	sortTwoNumSlice(nums[:shit], 0, 1)
	sortTwoNumSlice(nums[shit:], 1, 2)

	//log.Println(nums)
}
