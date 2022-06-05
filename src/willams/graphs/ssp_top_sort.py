from collections import defaultdict, deque
from typing import DefaultDict, List
from math import inf
from queue import LifoQueue

class Node:
    def __init__(self, vertex: int, weight: int) -> None:
        self.vertex = vertex
        self.weight = weight

class Graph:
    def __init__(self, vertices: int) -> None:
        self.adj: DefaultDict[int, List[Node]] = defaultdict(list)
        self.degree: DefaultDict[int, int] = defaultdict(int)
        self.vertices = vertices

        for index in range(vertices):
            _ = self.degree[index]

    def calculate_degree(self):
        """
        Calculate degree
        """

        for u in range(self.vertices):
            for v in self.adj[u]:
                self.degree[v] += 1

    def add_edge(self, u: int, v: int, weight: int):
        self.adj[u].append(Node(v, weight))

    def shortest_path(self, src):
        order = []

        
        q = deque()

        for v in range(self.vertices):
            if self.degree[v] == 0:
                order.append(v)
                q.append(v)
        
        parent = [-1 for index in range(self.vertices)]
        dist = [inf for index in range(self.vertices)]
        dist[src] = 0
        
        while q:
            u = q.popleft()

            for node in self.adj[u]:
                v = node.vertex
                w = node.weight

                self.degree[v] -= 1
                if w + dist[u] < dist[v]:
                    parent[v] = u
                    dist[v] = min(dist[v], w + dist[u])

                if self.degree[v] == 0:
                    order.append(v)
                    q.append(v)

        print(self.reconstruct_path(parent, 0, 7)) 
        # print(parent)
        print(dist)
        print(order)

    def longest_path(self, src):
        order = []

        
        q = deque()

        for v in range(self.vertices):
            if self.degree[v] == 0:
                order.append(v)
                q.append(v)
        
        parent = [-1 for index in range(self.vertices)]
        dist = [inf for index in range(self.vertices)]
        dist[src] = 0
        
        while q:
            u = q.popleft()

            for node in self.adj[u]:
                v = node.vertex
                w = node.weight * -1

                self.degree[v] -= 1
                if w + dist[u] < dist[v]:
                    parent[v] = u
                    dist[v] = min(dist[v], w + dist[u])

                if self.degree[v] == 0:
                    order.append(v)
                    q.append(v)

        print(self.reconstruct_path(parent, 0, 7))
        # print(parent)
        print([dis * -1 for dis in dist])
        print(order)

    def reconstruct_path(self, parent, start, end):
        path = []
        while end != -1:
            path.append(end)
            
            if end == start:
                break
            end = parent[end]
        
        path.reverse()
        
        return path

    
    def topological_sort(self):
        # Calculate the degree
        degree = [0] * self.vertices
        for u in range(self.vertices):
            for node in self.adj[u]:
                v = node.vertex
                degree[v] += 1
        
        q = LifoQueue()
        for v in range(self.vertices):
            if degree[v] == 0:
                q.put(v)
        order = []
        while not q.empty():
            u = q.get()

            for node in self.adj[u]:
                v = node.vertex
                degree[v] -= 1
                if degree[v] == 0:
                    q.put(v)
            order.append(u)

        return order

    def dag_shortest_path(self, start: int):
        distance = [None] * self.vertices
        top_sort = self.topological_sort()

        distance[start] = 0

        for index in range(self.vertices):
            node_index = top_sort[index]

            if distance[node_index] is not None:
                for adjacent_node in self.adj[node_index]:
                    v = adjacent_node.vertex
                    w = adjacent_node.weight

                    new_distance = distance[node_index] + w

                    if distance[v] is None:
                        distance[v] = new_distance
                    else:
                        distance[v] = min(distance[v], new_distance)

        print(distance)
        print(top_sort)



        




def main():
    g = Graph(8)

    g.add_edge(0, 1, 3)
    g.add_edge(0, 2, 6)
    g.add_edge(1, 2, 4)

    g.add_edge(1, 3, 4)
    g.add_edge(1, 2, 4)
    g.add_edge(1, 4, 11)

    g.add_edge(2, 3, 8)

    g.add_edge(3, 4, -4)
    g.add_edge(3, 5, 5)
    g.add_edge(3, 6, 2)

    g.add_edge(4, 7, 9)
    g.add_edge(5, 7, 1)
    g.add_edge(6, 7, 2)
    

    # g.shortest_path(0)
    # g.longest_path(0)
    g.dag_shortest_path(0)


if __name__ == "__main__":
    main()