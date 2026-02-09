# [1382. Balance a Binary Search Tree](https://leetcode.com/problems/balance-a-binary-search-tree/)

## Problem Statement
Given the root of a Binary Search Tree (BST), return a **balanced** Binary Search Tree with the same node values.

A BST is balanced if the depths of the two subtrees of every node never differ by more than 1.

---

## Constraints
- The number of nodes in the tree is in the range **[1, 10⁴]**
- **-10⁵ ≤ Node.val ≤ 10⁵**
- The given tree is a valid Binary Search Tree

---

## Approach
1. Perform an **inorder traversal** of the BST to collect all node values in a sorted array.
2. Use the sorted array to construct a balanced BST:
   - Choose the middle element as the root
   - Recursively build left and right subtrees using left and right halves
3. This guarantees minimum height and a balanced BST.

---

## Example
Input:
1
 \
  2
   \
    3
     \
      4

Output (one possible balanced BST):
  2
 / \
1   3
     \
      4

---

## Complexity Analysis
- **Time Complexity:** O(n)
- **Space Complexity:** O(n) (for inorder traversal array)
