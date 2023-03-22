class BrowserHistory:
    def __init__(self, homepage: str):
        self.b_stack = [homepage]
        self.f_stack = []

    def visit(self, url: str) -> None:
        self.f_stack = []
        self.b_stack.append(url)

    def back(self, steps: int) -> str:
        while steps and len(self.b_stack) > 1:
            self.f_stack.append(self.b_stack.pop())
            steps -= 1

        return self.b_stack[-1]

    def forward(self, steps: int) -> str:
        while steps and self.f_stack:
            self.b_stack.append(self.f_stack.pop())
            steps -= 1

        return self.b_stack[-1]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
