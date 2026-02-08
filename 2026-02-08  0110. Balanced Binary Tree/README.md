# 110. Balanced Binary Tree

## Problem Statement
Given a binary tree, determine if it is **height-balanced**.

A binary tree is height-balanced if for every node, the height difference between its left and right subtrees is **at most 1**.

## Constraints
- The number of nodes in the tree is in the range **[0, 5000]**
- `-10^4 ≤ Node.val ≤ 10^4`

## Approach
- Define a helper function to compute the height of a subtree.
- For each node:
  - Compute the height of the left and right subtrees.
  - If the absolute difference exceeds 1, the tree is not balanced.
- Recursively check balance for left and right subtrees.

## Complexity Analysis
- **Time Complexity:** O(n²) in the worst case (skewed tree), since height is recomputed for each node.
- **Space Complexity:** O(h), where `h` is the height of the tree (recursion stack).

## Notes
- This solution is straightforward and easy to understand.
- It can be optimized to O(n) using a bottom-up height check.
