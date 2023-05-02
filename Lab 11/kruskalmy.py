def kruskal(graph):
    edges = []
    for i in range(len(graph)):
        for j in range(i+1, len(graph)):
            if graph[i][j]:
                edges.append((i, j, graph[i][j]))

    edges.sort(key=lambda x: x[2])
    mst = []
    parent = list(range(len(graph)))
    
    for edge in edges:
        u, v, w = edge
        if parent[u] != parent[v]:
            mst.append(edge)
            old_parent = parent[u]
            new_parent = parent[v]
            for i in range(len(parent)):
                if parent[i] == old_parent:
                    parent[i] = new_parent

    return mst


def print_mst(mst):
    for i in mst:
        print(i[0], i[1], i[2])


graph = [    [0,10,5,6],
    [10,0,2,3],
    [5,2,0,1],
    [6,3,1,0]
]

print_mst(kruskal(graph))
