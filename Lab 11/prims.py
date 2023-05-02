
def print_mst (parent, graph):
    for i in range(1, len(parent)):
        
        print(parent[i], i, graph[i][parent[i]])



def mst_prism(graph, r):
    key = [float('inf')]*len(graph)
    parent = [None]*len(graph)

    key[r] = 0
    t = set(range(len(graph)))

    while t:
        u = min(t, key=lambda x: key[x])

        t.remove(u)

        for v in range(len(graph)):
            if graph[u][v] and v in t and graph[u][v] < key[v]:
                parent[v] = u
                key[v] = graph[u][v]

    return parent



graph = [
   [0,10,5,6],
    [10,0,2,3],
    [5,2,0,1],
    [6,3,1,0]
]


print_mst(mst_prism(graph, 0), graph)




