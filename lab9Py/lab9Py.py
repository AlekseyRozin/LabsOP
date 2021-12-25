# функция, которая возвращает список, состоящий из слов, стоящих на парных позициях в строке
def getWordsToCheck(str):
    words = str.split(' ')
    wordsToCheck = []
    for i in range(1,len(words),2):
        wordsToCheck.append(words[i])
    return wordsToCheck

# функция, которая возвращает истинное значение, если буква является гласной
def isVowel(letter):
    vowels = 'aeiou'
    if vowels.find(letter) == -1:
        return False
    else:
        return True

# функция, которая возвращает слово с дефисами в тех метсах, где слово можно перенести
def transfer(word):
    if len(word) < 5 or word.find('-') != -1:
        return 'Word cannot be transfered'
    res = ''
    for i in range(len(word)):
        res += word[i]
        dash = True
        if i < 1 or i > len(word) - 4: dash = False
        elif not isVowel(word[i]) and isVowel(word[i+1]): dash = False
        elif isVowel(word[i]) and isVowel(word[i+1]): dash = False
        elif isVowel(word[i]) and not isVowel(word[i + 1]) and not isVowel(word[i + 2]): dash = False
        if dash: res += '-'
    if res.find('-') == -1: 
        return 'Word cannot be transfered'
    else: 
        return res

# функция, которая выводит уже измененные слова, с дефисами в тех метсах, где слово можно перенести
def outputTransferedWords(words):
    for i in range(len(words)):
        print('\n',(i + 1) * 2,'.',words[i],'  --->  ',transfer(words[i]))
    print('\n\n')

#основная программа
input = input('Enter your text: ')
wordsToCheck = getWordsToCheck(input)
outputTransferedWords(wordsToCheck)