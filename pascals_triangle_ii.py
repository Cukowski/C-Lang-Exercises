def pascals_triangle_ii(k):
    row = [1]  # Initialize the first row with 1
    
    for _ in range(k):
        new_row = [1]  # Start with 1 at the beginning
        for i in range(1, len(row)):
            new_value = row[i-1] + row[i]  # Calculate each value
            new_row.append(new_value)
        new_row.append(1)  # End with 1
        row = new_row  # Update the row
    
    return row
