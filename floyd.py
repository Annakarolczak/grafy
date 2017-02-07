def directed_graph(graph):
    vertices = graph.keys()
    return {v1: {v2: 0 if v1 == v2 else graph[v1].get(v2, float('inf'))
                 for v2 in vertices}
            for v1 in vertices}

def weighted_graph(graph):
    vertices = graph.keys()
    d = graph
    for v2 in vertices:
        d = {v1: {v3: min(d[v1][v3], d[v1][v2] + d[v2][v3])
                 for v3 in vertices}
             for v1 in vertices}
    return d

if __name__ == "__main__":
     graph = {1: {2: 3, 3: 8, 5: -4}, 2: {4: 1, 5: 7}, 3: {2: 4}, 4: {1: 2, 3: -5}, 5: {4: 6}}
     g = directed_graph(graph)
     print(weighted_graph(g))