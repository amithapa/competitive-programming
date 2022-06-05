from __future__ import annotations
from queue import PriorityQueue

class LexicalStr:
    def __init__(self, content: str):
        self.content = content

    def __lt__(self, other: LexicalStr):
        return self.content > other.content

class LexographicalPriorityQueue:
    def __init__(self):
        self.priority_queue = PriorityQueue()

    def put(self, item: str):
        self.priority_queue.put(LexicalStr(item))
    
    def get(self) -> str:
        return self.priority_queue.get().content

def main():
    pq = LexographicalPriorityQueue()

    pq.put("A")
    pq.put("XX")
    pq.put("XR")
    pq.put("FZ")
    pq.put("X")
    pq.put("B")

    print(pq.get())
    print(pq.get())
    print(pq.get())
    print(pq.get())
    print(pq.get())
    print(pq.get())

if __name__ == "__main__":
    main()