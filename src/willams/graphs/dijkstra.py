from __future__ import annotations
from typing import DefaultDict, List
from collections import defaultdict
from queue import PriorityQueue
from math import inf


class Node:
    def __init__(self, vertex: int, weight: int) -> None:
        self.vertex = vertex
        self.weight = weight


class Graph:
    def __init__(self, vertices: int) -> None:
        self.adj: DefaultDict[int, List[Node]] = defaultdict(list)
        self.vertices = vertices

    def add_edge(self, u, v, w):
        self.adj[u].append(Node(v, w))

    def djikstra_sp(self, start: int):
        visited = [False] * self.vertices
        distance = [inf] * self.vertices

        pq = PriorityQueue()
        distance[start] = 0
        pq.put((0, start))

        parent = [None] * self.vertices
        
        while not pq.empty():
            item = pq.get()
            dis, u = item
            visited[u] = True
            
            if distance[u] < dis:
                continue
            
            for node in self.adj[u]:
                v, weight = node.vertex, node.weight

                if visited[v]:
                    continue
                new_distance = dis + weight

                if new_distance < distance[v]:
                    parent[v] = u
                    distance[v] = new_distance
                    pq.put((new_distance, v))


        # print(distance)
        # print([v for v in range(self.vertices)])
        # print(parent)
        return (distance, parent)

    def find_shortest_path(self, start: int, end: int):
        distance, parent = self.djikstra_sp(start)
        print(distance)
        path = []

        if distance[end] == inf:
            return path
        
        while end is not None:
            path.append(end)
            end = parent[end]
        
        path.reverse()
        return path


def main():
    g = Graph(5)
    g.add_edge(0, 1, 4)
    g.add_edge(0, 2, 1)
    g.add_edge(2, 1, 2)
    g.add_edge(1, 3, 1)
    g.add_edge(2, 3, 5)
    g.add_edge(3, 4, 3)

    print(g.find_shortest_path(0, 4))

if __name__ == "__main__":
    main()