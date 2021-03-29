func twoSum(nums []int, target int) []int {
	myMap := make(map[int]int)

	for index, num := range nums {
		if val, ok := myMap[num]; ok {
			return []int{val, index}
		} else {
			myMap[target-num] = index
		}
	}

	return []int{0, 0}
}
