def print_mst(mst):
    for i in mst:
        print(i[0], i[1], i[2])

def kruskal(graph, n):
    edges = []
    for i in range(n):
        for j in range(i+1, n):
            if graph[i][j]:
                edges.append((i, j, graph[i][j]))

    edges.sort(key=lambda x: x[2])
    parent = list(range(n))
    def find(v):
        while parent[v] != v:
            parent[v] = parent[parent[v]]
            v = parent[v]
        return v

    def union(v1, v2):
        parent[find(v1)] = find(v2)

    mst = []

    for edge in edges:
        if find(edge[0]) != find(edge[1]):
            mst.append(edge)
            union(edge[0], edge[1])

    return mst

# example graph
graph = [
    [0,10,5,6],
    [10,0,2,3],
    [5,2,0,1],
    [6,3,1,0]
]

# print the minimum spanning tree
print_mst(kruskal(graph, len(graph)))
