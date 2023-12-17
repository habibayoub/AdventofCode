def elf_rps():
    
    f = open("input.txt", "r")
    line = f.readline()
       
    #1 rock A X lose
    #2 paper B Y draw
    #3 scissors C Z win
    points = 0
    while line:
        
        if line[0] == "A":
            
            if line[2] == "Y":
                points += 4
            elif line[2] == "X":
                points += 3
            elif line[2] == "Z":
                points += 8
                
        elif line[0] == "B":
            
            if line[2] == "Y":
                points += 5
            elif line[2] == "X":
                points += 1
            elif line[2] == "Z":
                points += 9
                
        elif line[0] == "C":
            
            if line[2] == "Y":
                points += 6
            elif line[2] == "X":
                points += 2
            elif line[2] == "Z":
                points += 7
                
        line = f.readline()
        
    return points
print(elf_rps())