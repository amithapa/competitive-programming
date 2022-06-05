from queue import PriorityQueue

class MaxPriorityQueue:
    def __init__(self):
        self.priority_queue = PriorityQueue()

    def put(self, item):
        self.priority_queue.put(-1 * item)

    def get(self):
        return -1 * self.priority_queue.get()

def main():
    pq = MaxPriorityQueue()

    pq.put(2)
    pq.put(13)
    pq.put(5)
    pq.put(3)
    pq.put(11)
    pq.put(7)

    print(pq.get())
    print(pq.get())
    print(pq.get())
    print(pq.get())
    print(pq.get())
    print(pq.get())

if __name__ == "__main__":
    main()