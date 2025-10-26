List1 = ["구의", "신당", "상왕십리", "왕십리", "한양대"]
List2 = ["구의", "건대입구", "성수", "뚝섬", "한양대"]


station = input("승차역을 입력하세요:")


if station in List1 :
    onBoard = False
    for line in List1 :
        if line == station :
            onBoard = True

        if onBoard :
            print(line)

if station in List2 :
    onBoard2 = False
    for line in List2 :
        if line == station :
            onBoard2 = True

        if onBoard2 :
            print(line)
   
            
