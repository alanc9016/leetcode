func maxProduct(nums []int) int {
	res := -999
	prod := 1

	for i := 0; i < len(nums); i++ {
		prod *= nums[i]
		res = max(res, prod)
		if prod == 0 {
			prod = 1
		}
	}

	prod = 1

	for i := len(nums) - 1; i >= 0; i-- {
		prod *= nums[i]
		res = max(res, prod)
		if prod == 0 {
			prod = 1
		}
	}

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
