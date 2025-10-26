lines = ["뚝섬", "성수", "건대입구", "구의", "신당", "상왕십리", "왕십리", "한양대"]


onBoard = False
station = input("승차역: ")  
for line in lines :
    if line == station :
        onBoard = True
        
    if onBoard :
        print(line)




