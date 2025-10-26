lines = ["신당", "상왕십리", "왕십리", "한양대", "뚝섬", "성수", "건대입구", "구의"]
linesLeft = ["신당", "상왕십리", "왕십리", "한양대"]
linesRight = ["구의", "건대입구", "성수", "뚝섬", "한양대"]

station = input("승차역 : ")
if lines.index(station) < 3 :
    onBoard = False
    for line in linesLeft :
        if line == station :
            onBoard = True

        if onBoard :
            print(line)

if lines.index(station) > 3 :
    onboard = False
    for Line in linesRight :
        if Line == station :
            onboard = True

        if onboard :
            print(Line)
    
