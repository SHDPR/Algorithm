###Algorithms solving shortest-path-problems

* Dijkstra

  > Single node -> Single node
  > Use priority_queue to keep track of dist[0] ~ dist[V]

* Bellman-Ford

  > Single node -> Other nodes
  > Problem with negative weights, infinite cycles
  > Iterate through V cycles with edge release
  > N+1th cycle can detect infinite cycles

* Floyd-Warshall 

  > Nodes -> Nodes
  > Iterate through N * N * N cycle, each indicating stop node, source node, destination node
