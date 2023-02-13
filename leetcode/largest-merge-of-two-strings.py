class Solution:
    def largestMerge(self, word1: str, word2: str) -> str:
        merged_word = []

        word1_ptr = 0
        word2_ptr = 0
        word1_last = len(word1)
        word2_last = len(word2)

        while word1_ptr < word1_last and word2_ptr < word2_last:
            if word1[word1_ptr:] >= word2[word2_ptr:]:
                merged_word.append(word1[word1_ptr])
                word1_ptr += 1
            else:
                merged_word.append(word2[word2_ptr])
                word2_ptr += 1

        while word1_ptr < word1_last:
            merged_word.append(word1[word1_ptr])
            word1_ptr += 1

        while word2_ptr < word2_last:
            merged_word.append(word2[word2_ptr])
            word2_ptr += 1

        return "".join(merged_word)
