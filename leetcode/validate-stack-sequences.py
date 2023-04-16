from typing import List


class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        length = len(pushed)

        push_idx = 0
        pop_idx = 0

        st = []

        while push_idx < length and pop_idx < length:
            st.append(pushed[push_idx])

            while st and popped[pop_idx] == st[-1]:
                pop_idx += 1
                st.pop()

            push_idx += 1

        while st and popped[pop_idx] == st[-1]:
            pop_idx += 1
            st.pop()

        return pop_idx == length and push_idx == length
