# sliding window algorithm
def str_maxlenoc(param_1, param_2):
    def is_common_substring(substring):
        # Helper function to check if a substring appears in all input strings
        for s in param_1:
            if substring not in s:
                return False
        return True

    # Initialize the longest common substring
    longest_common = ""

    # Iterate through all possible substrings
    for i in range(len(param_1[0])):
        for j in range(i + 1, len(param_1[0]) + 1):
            substring = param_1[0][i:j]
            if is_common_substring(substring) and len(substring) > len(longest_common):
                longest_common = substring

    return longest_common
