def max_calories():
    
    f = open("input.txt", "r")
    line = f.readline()
    cal = 0
    mc1 = 0
    mc2 = 0
    mc3 = 0
    while line:
        if line == "\n":
            if mc1 < cal:
                mc3 = mc2
                mc2 = mc1
                mc1 = cal
                print("MC1 : "+str(mc1))
            elif mc2 < cal:
                mc3 = mc2
                mc2 = cal
                print("MC2 : "+str(mc2))
            elif mc3 < cal:       
                mc3 = cal
                print("MC3 : "+str(mc3))
            cal = 0
            line = f.readline()
        else:
            cal += int(line)
            line = f.readline()
    return mc1 + mc2 + mc3
        
         
