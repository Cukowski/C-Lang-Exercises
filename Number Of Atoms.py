"""
:type  param_1: {String}
:rtype: string
"""
def number_of_atoms(formula: str) -> str:
    stack = []
    element_counts = {}
    i = 0
    
    while i < len(formula):
        char = formula[i]
        
        if char.isupper():
            # Extract the element name
            element_name = char
            i += 1
            while i < len(formula) and formula[i].islower():
                element_name += formula[i]
                i += 1
            
            # Extract the element count (if any)
            element_count = 0
            while i < len(formula) and formula[i].isdigit():
                element_count = element_count * 10 + int(formula[i])
                i += 1
            if element_count == 0:
                element_count = 1
            
            # Update the element count in the dictionary
            if element_name in element_counts:
                element_counts[element_name] += element_count
            else:
                element_counts[element_name] = element_count
        elif char == '(':
            # Push the current element and its count onto the stack
            stack.append(element_counts)
            element_counts = {}
            i += 1
        elif char == ')':
            # Pop the stack and update the counts within parentheses
            i += 1
            multiplier = 0
            while i < len(formula) and formula[i].isdigit():
                multiplier = multiplier * 10 + int(formula[i])
                i += 1
            if multiplier == 0:
                multiplier = 1
            temp_counts = stack.pop()
            for element, count in element_counts.items():
                if element in temp_counts:
                    temp_counts[element] += count * multiplier
                else:
                    temp_counts[element] = count * multiplier
            element_counts = temp_counts
        else:
            # Invalid character, skip
            i += 1
    
    # Combine element names and counts in the required format
    result = ""
    for element in sorted(element_counts.keys()):
        result += element
        if element_counts[element] > 1:
            result += str(element_counts[element])
    
    return result

