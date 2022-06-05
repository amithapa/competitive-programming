from typing import DefaultDict, List
from collections import defaultdict, deque

class Graph:
    def __init__(self):
        self.adj: DefaultDict[List] = defaultdict(list)

    def add_edge(self, u: int, v: int):
        self.adj[u].append(v)

    def bfs(self, src: int):
        q = deque()
        q.append(src)

        visited: DefaultDict = defaultdict(bool)

        while q:
            u: int = q.popleft()
            if visited[u]:
                continue
            
            visited[u] = True

            for v in self.adj[u]:
                if visited[v]:
                    continue
                q.append(v)

            print(u, end=" ")

        print("")

    # def top_sort(self, u: int, data,  visited=None):
    #     if visited is None:
    #         visited = defaultdict(bool)
        
    #     visited[u] = True
        

    #     for v in self.adj[u]:
    #         if visited[v]:
    #             continue
    #         print(v)
    #         data.append(v)
    #         self.top_sort(v, data, visited)


def main():
    g = Graph()
    g.add_edge(2, 0)
    g.add_edge(2, 4)

    g.add_edge(0, 3)
    g.add_edge(0, 1)
    g.add_edge(3, 1)
    g.add_edge(4, 3)
    g.add_edge(4, 5)
    g.add_edge(5, 1)

    g.bfs(2)
    # data = [2]
    # g.top_sort(2, data)
    # data.reverse()

    # print(data)

if __name__ == "__main__":
    main()