import numpy
import random
from random import randint


def graph_edges(rand_edges):
    weight_rand_edges = []
    for i in rand_edges:
        weight = random.randint(1, 6), i[0], i[1]
        weight_rand_edges.append(weight)
    return weight_rand_edges

def rand_edgess(edge_list):
    edges_l = []
    for i in edge_list:
        edg = i[0], i[1], 1
        edges_l.append(edg)
    return edges_l

def randedges(n,numedges):
    e = []
    while len(e) < numedges:
        k = (randint(0, n), randint(0, n))
        if k[0] <> k[1] and k not in e and (k[1], k[0]) not in e:
            e.append(k)
    return e

def graph_edges(rand_edges):
    weight_rand_edges = []
    for i in rand_edges:
        weight = random.randint(1, 6), i[0], i[1]
        weight_rand_edges.append(weight)
    return weight_rand_edges

def BFS(start, target, GRAPH):
    #przeszukiwanie grafu wszerz start- min wierzcholek, cel- max wierzcholek, graph struktura- {0:[3,4]. 1:[3,2], 2:[2,3]}
    #przeszukujemy klucze, jezeli kolejka jest wieksza od zera za x zapisujemy pierwszy element z kolejki i tym samym usowamy go z kolejki
    queue = [start] #kolejka
    visited = []
    while len(queue) > 0:
        x = queue.pop(0)
        #jezeli x jest rowny celowi to do listy odwiedzonych wierzcholkow dopisujemy x
        if x == target:
            visited.append(x)
            return visited
        elif x not in visited:
            #jesli x nie nalezy do listy odwiedzonych wierzcholkow to dopisujemy go
            visited = visited+[x]
            if GRAPH[x] is not None:
                queue = queue + GRAPH[x]
    return visited

def generate_edges(graph):
    edges = []
    for node in graph:
        for neighbour in graph[node]:
            edges.append((node, neighbour))
    return edges

def nieskierowany(wierzcholki):
    visited = []
    for i in range(wierzcholki):
        visited.append("false")
    return visited

def matrices(v, k):
    row = []
    header = []
    for ele in range(v):
        row.append(0)
    for el in range(v):
        header.append(row)
    return numpy.array(header)

def all_pair(v):
    counter = 1
    c = 1
    pair = []
    while c < v:
        for i in range(1,v):
            k = (counter, c)
            counter += 1
            if k[0] <> k[1] and k not in pair and (k[1], k[0]) not in pair:
                pair.append(k)
            if counter > v:
                counter = 1
                c += 1
                if k[0] <> k[1] and k not in pair and (k[1], k[0]) not in pair:
                    pair.append((c, counter))
    return pair

def other_pair(all_pair):
    pair = []
    for i in all_pair:
        k = (i[1], i[0])
        if k not in all_pair:
            pair.append(k)
    return pair

def connected_graph(directed, vertic, rand_edges):
    first_pair = all_pair(vertic)
    second_pair = other_pair(first_pair)
    if directed == True:
        connected = [i for i in rand_edges if i in first_pair and i in second_pair]
    else:
        connected = [i for i in rand_edges if i in first_pair or i in second_pair]
    if len(connected) == len(first_pair) or len(connected) == len(second_pair):
        return "Graf jest spojny"
    else:
        return "Graf nie jest spojny"

def Dijkstra(G,start,end=None):
    D = {}
    P = {}
    Q = []
    Q[start] = 0
    for v in Q:
        D[v] = Q[v]
        if v == end:
            break
        for w in G[v]:
            vwLength = D[v] + G[v][w]
            if w in D:
                if vwLength < D[w]:
                    raise ValueError, "Dijkstra: found better path to already-final vertex"
                elif w not in Q or vwLength < Q[w]:
                    Q[w] = vwLength
                    P[w] = v
    return (D,P)


def shortestPath(G,start,end):
    D,P = Dijkstra(G,start,end)
    Path = []
    while 1:
        Path.append(end)
        if end == start:
            break
        end = P[end]
    Path.reverse()
    return Path



    g.add_edge('a', 'b', 7)
    g.add_edge('a', 'c', 9)
    g.add_edge('a', 'f', 14)
    g.add_edge('b', 'c', 10)
    g.add_edge('b', 'd', 15)
    g.add_edge('c', 'd', 11)
    g.add_edge('c', 'f', 2)
    g.add_edge('d', 'e', 6)
    g.add_edge('e', 'f', 9)
    return g