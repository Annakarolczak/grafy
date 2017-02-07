parent = dict()
rank = dict()

def make_set(vertice):
    #kazdy wierzcholek vertice jest korzeniem jednoelementowego drzewa
    parent[vertice] = vertice
    # print parent
    rank[vertice] = 0

def find(vertice):
    # wyznacza element ze zbioru zawierajacego wierzcholek vertice reprezentanta drzewa do ktorego nalezy
    if parent[vertice] != vertice:
        parent[vertice] = find(parent[vertice])
        # print "parent", parent
    return parent[vertice]

def union(vertice1, vertice2):
    #sumuje drzewa z wierzcholkami vertice1, vertice2
    root1 = find(vertice1)
    root2 = find(vertice2)
    if root1 != root2:
        if rank[root1] > rank[root2]:
            parent[root2] = root1
            # print "parent[root2]", parent
        else:
            parent[root1] = root2
            # print "parent[root1]", parent
            if rank[root1] == rank[root2]:
                rank[root2] += 1

def kruskal(graph):
    for vertice in graph['vertices']:
        make_set(vertice)

    minimum_spanning_tree = set()
    edges = list(graph['edges']) #lista wierzcholkow i wag
    edges.sort() #sortujemy
    for edge in edges:
        weight, vertice1, vertice2 = edge
        if find(vertice1) != find(vertice2):
            union(vertice1, vertice2)
            minimum_spanning_tree.add(edge)
    return minimum_spanning_tree

if __name__ == "__main__":

    graph = {
            'vertices': ['A', 'B', 'C', 'D', 'E', 'F'],
            'edges': ([(1, 'A', 'B'), (5, 'A', 'C'), (3, 'A', 'D'), (4, 'B', 'C'), (2, 'B', 'D'), (1, 'C', 'D')])
            }

    print(kruskal(graph))
