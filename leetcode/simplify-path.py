class Solution:
    def simplifyPath(self, path: str) -> str:
        path_array = path.split("/")
        stack = []

        for path in path_array:
            if path == "..":
                if stack:
                    stack.pop()
            elif path != "" and path != ".":
                stack.append(path)

        return "/" + "/".join(stack)
