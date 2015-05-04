from nltk.corpus import wordnet as wn


def getCategoryDepth(word):
    wordsets = wn.synsets(word)
    if len(wordsets) > 0:
        wordset = wordsets[0]
        return len(wordset.hypernym_paths())
    else:
        return 5

fin = open("word.txt","r")
fout = open("category.txt","w")
listw = fin.read().split('\n')
for word in listw:
    fout.writelines(word + ' ' + str(getCategoryDepth(word)) + '\n')
    
fin.close()
fout.close()
