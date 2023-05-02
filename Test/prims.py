import sys

V = 4

def min_key(key, mstSet):
    min_val = sys.maxsize
    min_index = None
    for v in range(V):
        if not mstSet[v] and key[v] < min_val:
            min_val = key[v]
            min_index = v
    return min_index

def print_mst(parent, graph):
    print("Edge \tWeight")
    for i in range(1, V):
        print(parent[i], "-", i, "\t", graph[i][parent[i]])

def prim_mst(graph):
    parent = [None] * V
    key = [sys.maxsize] * V
    mstSet = [False] * V

    key[0] = 0
    parent[0] = -1

    for count in range(V - 1):
        u = min_key(key, mstSet)
        mstSet[u] = True

        for v in range(V):
            if graph[u][v] and not mstSet[v] and graph[u][v] < key[v]:
                parent[v] = u
                key[v] = graph[u][v]

    print_mst(parent, graph)

graph = [
   [0,10,5, 6],
    [10, 0, 2, 3],
    [2,3,0,1],
    [6,5,1,0]
]


prim_mst(graph)
