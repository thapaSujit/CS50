import sys
import graphviz
import os

def matrix_to_dict(matrix):
    graph = {}
    i = 0
    for row in matrix:
        j = 0
        for weight in row:
            if i not in graph:
                graph[i] = []
            if weight != 0:
                graph[i].append((j, weight))
            j += 1
        i += 1
    return graph

def draw_graph_dict(g):
    graph = graphviz.Graph(format='png', strict=True, filename='dict')
    for n in g.keys():
        graph.node(str(n), str(n))

    for n in g.keys():
        for t, w in g[n]:
            graph.edge(str(n), str(t), label=str(w))
    graph.render()
    os.remove('dict')

if __name__ == '__main__':
    matrix = [
        [0, 5, 0, 0, 0],
        [8, 0, 0, 0, 4],
        [0, 1, 0, 3, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 2, 0, 0]
    ]

    graph = matrix_to_dict(matrix)
    draw_graph_dict(graph)
