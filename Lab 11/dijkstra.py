import heapq

def dijkstra(graph, start):
    # Initialize the distance from the start node to all other nodes as infinity
    distances = [float('inf')] * len(graph)
    distances[start] = 0
    
    # Initialize the parent of each node in the shortest path tree
    parents = [None] * len(graph)
    
    # Initialize the heap queue with the start node
    pq = [(0, start)]
    
    while pq:
        # Pop the node with the smallest distance from the heap
        current_distance, current_node = heapq.heappop(pq)
        
        # Check all neighboring nodes of the current node
        for neighbor, weight in enumerate(graph[current_node]):
            # If there's a shorter path to the neighbor through the current node
            if weight != 0 and current_distance + weight < distances[neighbor]:
                # Update the distance and parent of the neighbor
                distances[neighbor] = current_distance + weight
                parents[neighbor] = current_node
                # Add the neighbor to the heap
                heapq.heappush(pq, (distances[neighbor], neighbor))

    return parents, distances

def print_path(parents, start, end):
    if end == start:
        print(start, end=' ')
    elif parents[end] is None:
        print('No path from {} to {}'.format(start, end))
    else:
        print_path(parents, start, parents[end])
        print(end, end=' ')

def print_all_paths(parents, start):
    for i in range(len(parents)):
        print_path(parents, start, i)
        print()

graph = [
    [0,1,5,6],
    [1,0,2,3],
    [5,2,0,1],
    [6,3,1,0]
]

parents, distances = dijkstra(graph, 0)
print_all_paths(parents, 0)
print(distances)
