def binary_prefix_divisible_by_(A):
    current_number = 0
    result = []
    
    for bit in A:
        current_number = (current_number << 1) + bit
        result.append(current_number % 5 == 0)
    
    return result