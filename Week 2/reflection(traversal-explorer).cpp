/*

How does a stack help recursion?
A stack stores function calls, local variables, and return addresses so the program can return to the correct place after each recursive call.

Why does BFS use a queue?
BFS explores nodes level by level. A queue (FIFO) ensures the first discovered node is processed first.

When would you prefer DFS over BFS?
When you need to explore deeply, perform backtracking, detect cycles, do topological sorting, or when memory is limited.

What information must be stored to avoid revisiting nodes in a graph?
A visited array/set that records whether each node has already been visited.

*/