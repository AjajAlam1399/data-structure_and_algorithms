## it is used to find the count or the actual strongly connected graph

strongly connected graph - from any node whatever the path i may take i must be able to return back to the starting node in graph

## it is only done in directed graph

# step
1. sort all the edges according to their fininshing time by using dfs and stack
2. reverse all the edges
3.do again dfs on the element that we store in stack during step 1