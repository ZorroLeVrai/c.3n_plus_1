def transform(previous):
    #if previous is an odd number
    if previous & 1:
        return 3 * previous + 1
    
    #divide previous by 2
    return previous >> 1

def get_series(number):
    result = []
    result.append(number)
    while number != 1:
        number = transform(number)
        result.append(number)

    return result

#not called because Python automatically formats the list properly
def series_to_string(numbers):
    return "[{list}]".format(list=', '.join(map(str, numbers)))

numbers = get_series(1025)
print(numbers, end='\n')