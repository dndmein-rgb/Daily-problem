# [744. Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)

## Problem Summary
You are given a **sorted** array of characters `letters` and a character `target`.

Return the **smallest character** in the array that is **strictly greater than `target`**.

The array is considered **circular**, meaning:
- If no character is greater than `target`, return `letters[0]`.

---

## Key Insight
Because the array is sorted:
- The first character greater than `target` is the answer.
- If you reach the end without finding one, wrap around.

This circular condition is not optional. Ignore it and you fail half the test cases.

---

## Approach (Linear Scan)
1. Iterate through `letters`
2. Return the **first** character where `letters[i] > target`
3. If none found, return `letters[0]`

No binary search here. This solution is intentionally simple and still valid.

---

## Algorithm
- Loop from index `0` to `n-1`
- Check `letters[i] > target`
- Return immediately when condition is met
- Otherwise, wrap around

---

## Complexity
- **Time:** O(n)
- **Space:** O(1)

Not optimal, but perfectly acceptable under constraints.

---

## Example
Input:
letters = ['c','f','j']
target = 'j'


Output:
'c'


Explanation:
- No character is greater than `'j'`
- Circular wrap → return first element

---

## Common Mistakes
- Forgetting the circular rule
- Returning the closest letter instead of the **next greater**
- Overengineering with binary search when not required

---

## Final Thought
This problem is a warm-up.  
If this took more than a few minutes, the issue is not the problem.
