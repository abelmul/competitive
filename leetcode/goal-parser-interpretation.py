class Solution:
    def interpret(self, command: str) -> str:
        result = ""

        li = []
        in_parens = False

        for c in command:
            if c == "(":
                in_parens = True
                li.append(c)
            elif c == ")":
                in_parens = False

                if li[-1] == "(":
                    result += "o"
                else:
                    result += "".join(li[1:])

                li = []
            else:
                if in_parens:
                    li.append(c)
                else:
                    result += c

        return result
