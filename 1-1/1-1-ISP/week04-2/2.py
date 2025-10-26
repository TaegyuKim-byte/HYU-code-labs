station = input("승차역을 입력하세요:")

lines = ["한양대", "뚝섬", "성수", "건대입구", "구의", "신당", "상왕십리", "왕십리", "한양대"]


def countStation(lines, station) :
    count = 0
    for line in lines :
        if line == station :
            break
        count = count + 1
    return count

def chooseLine(lines, count) :
    if count < (len(lines)/2) :
        lines.reverse()
    return lines

def displayStation(lines, station) :
    onBoard = False
    for line in lines :
        if line == station :
            onBoard = True
        if onBoard :
            print(line)
            if line == "한양대" :
                break
    
    
    
count = countStation(lines, station)

lines = chooseLine(lines, count)

displayStation(lines, station)



