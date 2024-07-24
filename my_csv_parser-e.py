def my_csv_parser(param_1, param_2):
    # Split the string into lines using the newline character as the separator
    lines = param_1.strip().split('\n')
    
    # Initialize an empty result array to store the 2D array
    result = []
    
    # Iterate through each line
    for line in lines:
        # Split the line into columns using the provided separator
        columns = line.split(param_2)
        
        # Append the columns as an array to the result array
        result.append(columns)
    
    return result


def my_csv_parser(param_1, param_2):
    lines = param_1.strip().split('\n')
    
    result = []
    
    for line in lines:
        columns = line.split(param_2)
        
        result.append(columns)
    
    return result
