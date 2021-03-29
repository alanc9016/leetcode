func maxSubArray(nums []int) int {
	res := nums[0]
	var dp []int

	dp = append(dp, nums[0])

	for i := 1; i < len(nums); i++ {
		x := max(dp[i-1]+nums[i], nums[i])
		dp = append(dp, x)
		res = max(res, x)
	}

    	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}
