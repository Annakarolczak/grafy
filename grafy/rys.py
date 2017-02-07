from igraph import *
import kruskal


def list_vertics(vertic):
    l = []
    for i in range(0, vertic):
        l.append(i)
    return l

def graph(edge_list, v):
    l = []
    for j in edge_list:
        m = j[1],j[0]
        l.append(m)
    edge_list = edge_list + l
    GG = {}
    li1 = []
    for i in edge_list:
        li1.append(i[1])
        if i[0] in GG.keys():
            GG[i[0]].append(i[1])
        else:
            GG[i[0]] = li1
            li1 = []
    for k in range(v):
        if k not in GG.keys():
            GG[k] = None
    return GG

def DFS(start, GRAPH):
    l = []
    # target = target -1
    stack = [start]
    #stos
    visited = []
    w = GRAPH.keys()
    while len(stack) > 0:
        x = stack.pop(0)
        # if x == target:
        #     visited.append(x)
        #     l.append(x)
        #     return visited
        if x not in visited:
            visited = visited+[x]
            l.append(x)
            if GRAPH[x] is not None:
                stack = GRAPH[x] + stack
    return l

def kruskal_graph():
    graph = {}
    edges_l = []
    graph['vertices'] = list_vertics(vertic)
    pytanie = raw_input("Czy chcesz podac wagi? (T or F) ")
    for i in edge_list:
        if pytanie != 'F':
            waga = int(raw_input("Podaj wage wierzcholka " + str(i) + ': '))
        else:
            waga = 1
        edg = waga, i[0], i[1]
        edges_l.append(edg)
    edges_l.sort()
    print edges_l
    graph['edges'] = edges_l
    return kruskal.kruskal(graph)


if __name__ == "__main__":
    vertic = int(raw_input("Podaj liczbe wierzcholkow: "))
    edges = []
    for j in raw_input("Podaj krawedzie: "): #(0,3 3,1 1,2 2,3 3,5 0,4) (5,3 3,4 4,0 0,1 1,4 1,2 2,3)
        edges.append(j)
    size = len(edges)
    l = []
    cou = 1
    for j in range(0, size, 2):
        while cou < size:
            k1 = int(edges[cou])
            k2 = int(edges[cou+2])
            kk = k1, k2
            l.append(kk)
            cou += 4
    print l

    g = Graph()
    g.add_vertices(vertic)
    g.add_edges(l)
    g.vs()
    g.vs["name"] = list_vertics(vertic)
    macierz_sasiedztwa = g.get_adjacency()
    new_list = []
    nj = []
    print "to jest macierz_sasiedztwa", macierz_sasiedztwa
    edge_list = g.get_edgelist()
    g.vs["label"] = g.vs["name"]
    g.vs["color"] = "blue"
    plot(g, color="color", label="label")

    l_vertics = (list_vertics(vertic))
    print "lista wierzcholkow"
    print l_vertics
    GRAPH = graph(edge_list, vertic)
    start = min(GRAPH.keys())
    target = max(GRAPH.keys())+1

    """
    1. spojnosc grafu: graf jest spojny gdy lista wierzcholkow rowna sie liscie z DFS
    dla kazdej pary wieszcholkow istnieje sciezka
    """
    sre_list = []
    dfs_list = []
    cen_list = {}
    s = l_vertics
    # for tt in s:
    #     for vv in l_vertics:
    f = DFS(s[0], GRAPH)
    print "wynik dfs"
    print f
    f.sort()
    # cen_list[vv,tt] = f
    # if f not in dfs_list and len(f) > 1:
    #     dfs_list.append(f)
    # print dfs_list
    # for dd in f:
    #     if dd == l_vertics:
    #         consist = True
    #         break
    #     else:
    #         consist = False
    # for ddd in dd:
    #     if len(ddd) > 1:
    #         sre_list.append(len(ddd)-1)
    if s == f:
        print "Graf jest spojny"
    else:
        print "Graf jest niespojny"
    print cen_list

    """
    srednica- najwieksza odleglosc miedzy dowolnymi wierzcholkami grafu
    """
    # srednica = max(sre_list)
    # print "srednica grafu to: ", srednica

    # promien = min(sre_list)
    # print "promien grafu to: ", promien

    """
    centrum- Wierzcholki dla ktorych osiagniete jest minimum z definicji promienia grafu
    """
    # centrum = []
    # ccc = []
    # cou = -1
    # ke = cen_list.keys()
    # powtorka = []
    # for u in cen_list.values():
    #     cou += 1
    #     if len(u) == promien + 1:
    #         centrum.append(ke[cou])
    # for uu in centrum:
    #     ff = uu[0]
    #     ccc.append(ff)
    # for y in ccc:
    #     if ccc.count(y) > 1:
    #         powtorka.append(y)
    # n = list(set(ccc))
    # powtorka = list(set(powtorka))
    # for yu in powtorka:
    #     n.remove(yu)

    # print "centrum grafu to: ", n


    """
    2. Algorytm Kruskala- szukanie najkrotszej drogi potrzebne wagi!!! jak nie ma to zawsze 1
    Tylko jak graf spojny wazony
    pusty zbior krawedzi i lista wszystkich krawedzi grafu uporzadkowana wg rosnacych wag
    dopoki w zbiorze nie ma wszystkich wierzcholkow wybieramy z listy krawedz, jesli nie tworzy ona cyklu z
    krawedziami juz obecnymi w zbiorze, dodajemy ja do zbioru.
    gdy algorytm zakonczy prace, w zborze bedzie minimalne drzewo rozpinajace.
    """
    print "Minimalne drzewo rozpinajace"
    print kruskal_graph()

















