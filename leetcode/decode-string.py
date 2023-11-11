class Solution:
    def decodeString(self, s: str) -> str:
        st = []

        for i in range(len(s)):
            if s[i] == "]":
                cs = []
                while st[-1] != "[":
                    cs.append(st.pop())

                st.pop()  # remove [

                kstring = []
                while st and st[-1].isdigit():
                    kstring.append(st.pop())

                st += int("".join(reversed(kstring))) * "".join(reversed(cs))

            else:
                st.append(s[i])

        return "".join(st)
