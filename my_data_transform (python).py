def my_data_transform(param_1):
    def get_email_provider(email):
        parts = email.split("@")
        if len(parts) == 2:
            return parts[1]
        return email
    
    def get_age_group(age):
        if 1 <= age <= 20:
            return "1->20"
        elif 21 <= age <= 40:
            return "21->40"
        elif 41 <= age <= 65:
            return "41->65"
        else:
            return "66->99"
    
    def get_order_time_group(order_at):
        hour = int(order_at.split(" ")[1].split(":")[0])

        if 6 <= hour < 12:
            return "morning"
        elif 12 <= hour < 18:
            return "afternoon"
        else:
            return "evening"
    
    lines = param_1.strip().split("\n")
    transformed_lines = []

    header = lines[0]
    transformed_header = header.replace("Age,", "Age,").replace("Order At", "Order At")
    transformed_lines.append(transformed_header)

    for line in lines[1:]:
        columns = line.split(",")
        
        email = get_email_provider(columns[4])
        age = int(columns[5])
        order_at = columns[9]
        
        age_group = get_age_group(age)
        order_time_group = get_order_time_group(order_at)
        
        columns[4] = email
        columns[5] = age_group
        columns[9] = order_time_group
        
        transformed_lines.append(",".join(columns))
    
    return transformed_lines
