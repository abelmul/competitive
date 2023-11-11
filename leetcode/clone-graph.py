# Definition for a Node.
class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: "Node") -> "Node":
        clone = None
        if node:
            """
            since nodes can be identified by thier value
            we can use dict to store the node with the value as key
            """
            clone = Node(node.val)
            nodes = {node.val: clone}

            stack = [node]
            visited = set()

            while stack:
                node = stack.pop()

                if node.val not in visited:
                    c = nodes[node.val]
                    for neighbor in node.neighbors:
                        if neighbor.val in nodes:
                            n = nodes[neighbor.val]
                        else:
                            n = Node(neighbor.val)
                            nodes[neighbor.val] = n

                        c.neighbors.append(n)
                        stack.append(neighbor)

                    visited.add(node.val)

        return clone
