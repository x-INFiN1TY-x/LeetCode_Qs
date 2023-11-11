class Graph:
    def __init__(self, n: int, edges: List[Tuple[int, int, int]]):
        # Initialize the graph with a defaultdict where each node maps to a list of (neighbor, edge_cost) tuples
        self.graph = defaultdict(list)
        for from_node, to_node, edge_cost in edges:
            self.graph[from_node].append((to_node, edge_cost))

    def addEdge(self, edge: Tuple[int, int, int]) -> None:
        # Add a new edge to the graph
        self.graph[edge[0]].append((edge[1], edge[2]))

    def shortestPath(self, start_node: int, end_node: int) -> int:
        # Initialize minimum costs for each node with infinity, set the starting node cost to 0
        min_costs = defaultdict(lambda: float('inf'))
        min_costs[start_node] = 0
        
        # Initialize the priority queue with a tuple (cost, node)
        heap = [(0, start_node)]

        while heap:
            # Pop the node with the minimum cost from the priority queue
            cur_cost, cur_node = heapq.heappop(heap)

            # If the current node is the destination, return the minimum cost to reach it
            if cur_node == end_node:
                return min_costs[end_node]

            # Explore neighbors and update costs
            for nei, edge_cost in self.graph[cur_node]:
                new_cost = cur_cost + edge_cost
                # If the new cost is smaller than the current recorded cost for the neighbor, update it
                if new_cost < min_costs[nei]:
                    min_costs[nei] = new_cost
                    # Add the neighbor and its new cost to the priority queue
                    heapq.heappush(heap, (new_cost, nei))

        # If there is no path from start_node to end_node
        return -1