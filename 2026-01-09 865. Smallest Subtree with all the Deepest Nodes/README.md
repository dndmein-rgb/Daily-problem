# 865. Smallest Subtree with all the Deepest Nodes

## 📋 Problem Description

**Problem Number**: 865  
**Difficulty**: Medium  
**LeetCode Link**: [Smallest Subtree with all the Deepest Nodes](https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/)  
**Topics**: Hash Table, Tree, Depth-First Search, Breadth-First Search, Binary Tree  

---

### Problem Statement

Given the `root` of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains **all the deepest nodes** in the original tree.

A node is called **deepest** if it has the largest depth possible among any node in the entire tree. The **smallest subtree** containing all the deepest nodes is the Lowest Common Ancestor (LCA) of all those nodes.

---

### Examples

#### Example 1

**Input**: `root = [3,5,1,6,2,0,8,null,null,7,4]`  
**Output**: `[2,7,4]`  
**Explanation**: The deepest nodes are 7 and 4. The smallest subtree containing both is the node 2.

#### Example 2
**Input**: `root = [1]`  
**Output**: `[1]`  

---

### Constraints

- The number of nodes in the tree will be in the range `[1, 500]`.
- `0 <= Node.val <= 500`
- The values of the nodes in the tree are **unique**.

---

## 💡 Approach

### Key Insight

The "smallest subtree containing all deepest nodes" is actually the **Lowest Common Ancestor (LCA)** of all nodes that reside at the maximum depth of the tree.
- If a node's left subtree and right subtree both contain nodes at the `maxDepth`, then that current node must be the LCA (or a candidate for it).
- We use a post-order traversal (DFS) to find the depth of each subtree.

### Algorithm

1. **DFS Traversal**: Create a helper function that returns the maximum depth reachable from a given node.
2. **Compare Depths**: 
   - For any node, get the `leftMaxDepth` and `rightMaxDepth`.
   - If `leftMaxDepth == rightMaxDepth` and these depths are equal to or greater than the global `maxDepth` seen so far, this node is a candidate for the result.
3. **Update Global Answer**: Every time we find a node where the maximum depths of both subtrees are equal and reach the deepest level, we update our `ans` pointer and the global `maxDepth`.

---

## ⚡ Complexity Analysis

### Time Complexity: **O(N)**
- We visit each node in the binary tree exactly once during the DFS traversal.

### Space Complexity: **O(H)**
- Where $H$ is the height of the tree. This space is used by the recursion stack. In the worst case (a skewed tree), it could be $O(N)$.

---

**Pattern**: DFS (Post-order Traversal) / LCA  
**Date Solved**: January 8, 2026
