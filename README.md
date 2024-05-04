# Data Structures and Algorithms

## UCSB CMPSC 130A

## Overview

Graph Algorithms and Data structures

### Graph Algorithms:

- **Breadth-First Search (BFS)**
- **Depth-First Search (DFS)**
- **Dijkstra's Algorithm**
- **Bellman-Ford Algorithm**
- **Prim's Algorithm**
- **Kruskal's Algorithm**
- **Topological Sorting**

### Data Structures:

- **Min/Max Heap**
- **Stack**
- **Priority Queue**
- **Deque**
- **Linked List**

### Projects:

1. **10 Kinds of People** (https://open.kattis.com/problems/10kindsofpeople)

   - Approach: By using the floodFill algorithm, color all the nodes in the graph by coloring all the same type adjacent(no diagonals) nodes recursively. At the end, check if the graph starting point(A) and end point(B) have same data type and check if they have the same color. If they meet this condition, that means there is a path from A to B thus return the data type.

2. **Through the Grapevine** (https://open.kattis.com/problems/grapevine)

   - Approach: A breadth-first search (BFS) algorithm to traverse through a graph of connections between people. During the BFS traversal, the skepticism of adjacent nodes is decremented, and if it reaches zero, the traversal continues to those adjacent nodes. The BFS traversal is limited to a certain number of days (d). The goal is to count the number of people encountered within the given number of days.

3. **Babelfish** (https://open.kattis.com/problems/babelfish)

   - Approach: Created a container of array of lists. Hash table inserts word and translate to the index position. If collision appears, the pair gets inserted at the end of the list.
