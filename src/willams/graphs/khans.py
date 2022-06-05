from typing import DefaultDict, List
from collections import defaultdict, deque

class Graph:
    def __init__(self, vertices: int):
        self.adj: DefaultDict[List] = defaultdict(list)
        self.degree: DefaultDict[int]  = defaultdict(int)

        self.vertices = vertices

        for index in range(vertices):
            _ = self.degree[index]

    def add_edge(self, u: int, v: int):
        self.adj[u].append(v)

    def calculate_degree(self):
        for u in range(self.vertices):
            for v in self.adj[u]:
                self.degree[v] += 1


    def bfs(self):
        self.calculate_degree()
        q = deque()

        for vertex in range(self.vertices):
            if self.degree[vertex] == 0:
                q.append(vertex)

        order = []
        while q:
            u: int = q.popleft()
            order.append(u)
            
            for v in self.adj[u]:
                self.degree[v] -= 1
                if self.degree[v] == 0:
                    q.append(v)
            
            # print(u, end=" ")
        # print("")
        if len(order) != self.vertices:
            print("Cycle detected")
            return None
        return order


def main():
    # g = Graph(6)
    # g.add_edge(2, 0)
    # g.add_edge(2, 4)

    # g.add_edge(0, 3)
    # g.add_edge(0, 1)
    # g.add_edge(3, 1)
    # g.add_edge(4, 3)
    # g.add_edge(4, 5)
    # g.add_edge(5, 1)

    g = Graph(14)

    g.add_edge(9, 2)
    g.add_edge(9, 10)
    g.add_edge(2, 6)

    g.add_edge(10, 6)

    g.add_edge(0, 2)
    g.add_edge(0, 6)
    g.add_edge(0, 3)

    g.add_edge(6, 11)
    g.add_edge(6, 7)

    g.add_edge(7, 12)
    g.add_edge(7, 4)


    g.add_edge(12, 8)

    g.add_edge(4, 8)
    g.add_edge(4, 5)
    
    g.add_edge(3, 4)
    g.add_edge(3, 1)

    g.add_edge(1, 0)


    g.add_edge(1, 4)
    

    print(g.bfs())
    

if __name__ == "__main__":
    main()