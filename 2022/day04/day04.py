def swallow():
    
    f = open("input.txt", "r")
    line = f.readline()
    count = 0
    
    while line:
        line = line.replace("-", ",").replace("\n", "").split(",")
        
        if ( ((int(line[0]) <= int(line[2])) & (int(line[1]) >= int(line[3])) ) | 
            ( (int(line[2]) <= int(line[0])) & (int(line[3]) >= int(line[1])) )):
            count += 1

        line = f.readline()
    return count

print(swallow())

def overlap():
    
    f = open("input.txt", "r")
    line = f.readline()
    count = 0
    
    while line:
        line = line.replace("-", ",").replace("\n", "").split(",")
        
        if ( ( (int(line[0]) <= int(line[2])) & (int(line[1]) >= int(line[2])) ) | 
            ( (int(line[2]) <= int(line[0]))  & (int(line[3]) >= int(line[0]))  ) ):
            count += 1
        
        line = f.readline()
    return count

print(overlap())