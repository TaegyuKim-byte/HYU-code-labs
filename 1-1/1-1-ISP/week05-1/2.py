import time

HANGMANPICS = ['''
  +---+
  |   |
      |
      |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
      |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
  |   |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========''']

List = [0, 1, 2, 3, 4, 5, 6]
def displayASCii(img_list) :
    for idx in List :
        time.sleep(1)
        print(img_list[idx])

displayASCii(HANGMANPICS)

#def displayASCii(img_list, idx) :
    #if idx >= 0 and idx <= len(img_list) :
        #print(img_list[idx])
       

#displayASCii(HANGMANPICS, 0)
#time.sleep(1)
#displayASCii(HANGMANPICS, 1)
#time.sleep(1)
#displayASCii(HANGMANPICS, 2)
#time.sleep(1)
#displayASCii(HANGMANPICS, 3)
#time.sleep(1)
#displayASCii(HANGMANPICS, 4)
#time.sleep(1)
#displayASCii(HANGMANPICS, 5)
#time.sleep(1)
#displayASCii(HANGMANPICS, 6)

#1번 응용한게 마지막 풀이 



