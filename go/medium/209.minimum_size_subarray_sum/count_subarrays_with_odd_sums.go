package main

import "math"

func minSubarrayLen(nums []int, target int) int {
	if len(nums) == 1 {
		if nums[0] >= target {
			return 1
		}
		return 0
	}

	if nums[0] >= target {
		return 1
	}

	minLen := math.MaxInt64
	left := 0
	right := 0
	windowSum := nums[0]

	for left < len(nums) {
		if windowSum < target && right+1 == len(nums) {
			break
		}

		if windowSum < target {
			right++
			windowSum += nums[right]
			continue
		}

		currentLen := right + 1 - left

		if currentLen < minLen {
			minLen = currentLen
			if minLen == 1 {
				return 1
			}
		}

		windowSum -= nums[left]
		left++
	}

	if minLen == math.MaxInt64 {
		return 0
	}

	return minLen
}
