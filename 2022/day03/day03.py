def prioritize():
    
    f = open("input.txt", "r")
    line = f.readline()
    fh = []
    sh = []
    count = 0
    dict = {'a': 1, 'c': 3, 'b': 2, 'e': 5, 'd': 4, 'g': 7, 'f': 6, 'i': 9, 'h': 8, 'k': 11, 'j': 10, 'm': 13, 'l': 12,
            'o': 15, 'n': 14, 'q': 17, 'p': 16, 's': 19, 'r': 18, 'u': 21, 't': 20, 'w': 23, 'v': 22, 'y': 25, 'x': 24,
            'z': 26, 'A': 27, 'B': 28, 'C': 29, 'D': 30, 'E': 31, 'F': 32, 'G': 33, 'H': 34, 'I': 35, 'J': 36, 'K': 37,
            'L': 38, 'M': 39, 'N': 40, 'O': 41, 'P': 42, 'Q': 43, 'R': 44, 'S': 45, 'T': 46, 'U': 47, 'V': 48, 'W': 49,
            'X': 50, 'Y': 51, 'Z': 52}
    
    while line:
        
        fh =line[:int(len(line)/2)]
        sh = line[int(len(line)/2):]
        print(fh,sh)
        dup = list(set(fh) & set(sh))
        print(dup)
                
        count += dict.get(dup[0])
        line = f.readline()
        
    return count

print(prioritize())