Dic = {"hanyang" : ["hanyang.ac.kr", "hanyang univ"], "univ" : ["univ2024", "nuiv meaning", "univ 2023", "univ 2022"], "computr" : ['computer']}
#value 자료형의 종류를 통일시켜주는게 편리함. 여기선 list.
#***리스트와 
print("검색어 : ", end = "")

word = input()
print("Showing results for " + word)

if word in Dic :
    print("*Suggested: " , end="")
    for eachword in Dic[word] :
        print(eachword + " ", end= "")
    print()


# (list)[인덱스] -> 그 인덱스에 맞는 값(value) 추출
# (dictionary)[key] -> key에 맞는 값(value) 추출 
