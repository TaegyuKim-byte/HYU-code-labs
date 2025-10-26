news = '''SHRIMPLY THE BEST: Are you seeking a lively learning experience
involving creative turns of phrases, specifically those phrases
and words that involve a crustacean we all know? If you are, then
you've prawn, er, won big, at least if you've paid a visit to the
social feeds helmed by the Monterey Bay Aquarium staff. It is Shrimp Week,
a playful period when the Cannery Row landmark pauses to "shellebrate"
the small critter and its amazing attributes. No gifts, telegrams, or greeting
cards are expected; after all, a card would get wet if you handed it to a
shrimp and any presents might go unused. Rather, this shellebration is all
about education and amusement, with the amusing elements hailing from the
witty wordplay woven through the shrimp-themed posts. It's all happening on
the aquarium's social pages, with so much afoot that it is difficult to keep
(cara)pace.FAIRY SHRIMP TO GIANT PRAWN: Of course, the shrimp, though famously
diminutive, isn't a one-size-fits-all kind of icon; the antennae-rocking,
carapace-cool creatures boast a dazzling array of attributes. Telling the
tail, er, tale of the shrimpverse, though, requires several posts, and a few
videos, too, so feel free to scroll through the aquarium's latest updates to
find out what you may have missed. But wait: You can be "shrimpspired" by
having shrimpdates sent to your phone. Shrimply text 54159 -- oh, SHRIMPLYFB
is what you'll want to specifically text -- then sit back and let the
educational and ocean-y awesomeness wash over you or your phone, rather.
But wait: Would you prefer to watch a cleaner shrimp cleaning?
Cool: Here's two exciting hours of that thrilling krill-a-tude.'''.lower()

words = news.split()
leng= {} #dic (key와 value로 정보 저장)

for word in words :
    length = len(word) #숫자 
    if length not in leng : #in을 쓸 때 key와 value중 어떤것의 포함관게를 보는가
        leng[length] = [word]
    else :
        leng[length].append(word)

print(max(leng), leng[max(leng)])
    
    
        

