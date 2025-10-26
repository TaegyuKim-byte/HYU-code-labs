import random

def pickRandomWord(words) :
    idx = random.randint(0, len(words)-1)
    word = words[idx]
    return word



words = '''ant baboon badger bat bear beaver camel cat clam cougar coyote crew deer dog donkey duck eagle
ferret fox frog goat goose hawk lion lizard llama mole monkey moose mouse mule newt otter owl
panda parrot pigeon rabbit ram rat raven rhino salmon
seal shark sheep skunk sloth snake spider stork swan tiger toad trout turkey turtle whale wolf wombat zebra'''.split()




    
word = pickRandomWord(words)

print(word)


