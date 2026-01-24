# 🧮 Minimum Pair Removal to Sort Array I

- **Problem:** [LeetCode 3507 – Minimum Pair Removal to Sort Array I](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/)

---

## 🧠 Problem Summary

You are given an integer array `nums`.

In one operation:
- Choose two **adjacent elements**
- Replace them with their **sum**
- Remove the second element

Your task is to find the **minimum number of operations** needed to make the array **non-decreasing**.

---

## 💡 Key Observation

Every operation reduces the array size.

To avoid breaking order further:
- Always merge the **adjacent pair with the smallest sum**
- This greedy choice minimizes disruption
- Repeating this leads to the array becoming sorted in the fewest steps

This is why a greedy strategy works.

---

## 🛠️ Approach

1. While `nums` is not sorted:
   - Scan all adjacent pairs
   - Find the pair with the **minimum sum**
2. Merge that pair:
   - `nums[i] = nums[i] + nums[i+1]`
   - Remove `nums[i+1]`
3. Count each merge as one operation
4. Stop when array becomes non-decreasing

---

## ⏱️ Complexity

- **Time Complexity:**  
  O(n²) in the worst case  
  (each merge costs O(n), repeated up to n times)

- **Space Complexity:**  
  O(1) extra space (in-place operations)

---

## ⚠️ Common Pitfalls

- Merging random or largest pairs breaks ordering
- Sorting the array after each operation is incorrect
- Forgetting that the array shrinks after each merge
- Returning the minimum sum instead of its index

---

## 🎯 Takeaway

This problem checks:
- Greedy reasoning
- Careful array mutation
- Understanding when local optimal decisions lead to global correctness

If you try DP here, you missed the point.
