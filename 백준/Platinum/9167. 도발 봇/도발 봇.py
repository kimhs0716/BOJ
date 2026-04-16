import sys
input = sys.stdin.readlines

the = "theholygrail"

def find_the_holy_grail(s):
    c = 0
    for i in s:
        if i == the[c]:
            c += 1
        if c == 12:
            return True
    return False

def space():
    global result
    result += " "
    
def taunt():
    global k, result, i
    k[0] += 1
    if k[0] % 4 <= 1:
        sentence()
    elif k[0] % 4 == 2:
        i += 1
        taunt()
        space()
        sentence()
    else:
        noun(1)
        result += "!"

def sentence():
    global k
    k[1] += 1

    if k[1] % 3 == 1:
        past_rel()
        space()
        noun_phrase()
    elif k[1] % 3 == 2:
        present_rel()
        space()
        noun_phrase()
    else:
        past_rel()
        space()
        article()
        space()
        noun()

def noun_phrase():
    article()
    space()
    modified_noun()

def modified_noun():
    global k
    k[3] += 1
    if k[3] % 2 == 1:
        noun()
    else:
        modifier()
        space()
        noun()

def modifier():
    global k
    k[4] += 1
    if k[4] % 2 == 1:
        adjective()
    else:
        adverb()
        space()
        adjective()

def present_rel():
    global result
    result += "Your"
    space()
    present_person()
    space()
    present_verb()

def past_rel():
    global result
    result += "Your"
    space()
    past_person()
    space()
    past_verb()

def present_person():
    global k, result
    result += ["steed", "king", "first-born"][k[7] % 3]
    k[7] += 1

def past_person():
    global k, result
    result += ["mother", "father", "grandmother", "grandfather", "godfather"]\
    [k[8] % 5]
    k[8] += 1

def noun(upper = 0):
    global k, result

    if upper:
        result += ["Hamster", "Coconut", "Duck", "Herring", "Newt", "Peril",
               "Chicken", "Vole", "Parrot", "Mouse", "Twit"][k[9] % 11]

    else:
        result += ["hamster", "coconut", "duck", "herring", "newt", "peril",
               "chicken", "vole", "parrot", "mouse", "twit"][k[9] % 11]
    k[9] += 1

def present_verb():
    global k, result
    result += ["is", "masquerades as"][k[10] % 2]
    k[10] += 1

def past_verb():
    global k, result
    result += ["was", "personified"][k[11] % 2]
    k[11] += 1

def article():
    global result
    result += "a"

def adjective():
    global k, result
    result += ["silly", "wicked", "sordid", "naughty", "repulsive",
               "malodorous", "ill-tempered"][k[13] % 7]
    k[13] += 1

def adverb():
    global k, result
    result += ["conspicuously", "categorically", "positively", "cruelly",
               "incontrovertibly"][k[14] % 5]
    k[14] += 1

k = [0] * 15
inputs = input()
for sss in inputs[:-1]:
    s = sss.strip().split()
    cnt = len(s)
    print("Knight:", ' '.join(s) + " ")
    for ss in s:
        if not list(filter(lambda x: x.isalpha(), ss)): cnt -= 1
    cnt = cnt // 3 + (cnt % 3 != 0)
    if find_the_holy_grail(''.join(s).lower()):
        cnt -= 1
        print("Taunter: (A childish hand gesture). ")
    i = 0
    while i < cnt:
        print("Taunter: ", end='')
        result = ""
        taunt()
        print(result + ". ")
        i += 1
    print()

sss = inputs[-1]
s = sss.strip().replace("\t", " ").split()
cnt = len(s)
print("Knight:", ' '.join(s) + " ")
for ss in s:
    if not list(filter(lambda x: x.isalpha(), ss)): cnt -= 1
cnt = cnt // 3 + (cnt % 3 != 0)
if find_the_holy_grail(''.join(s).lower()):
    cnt -= 1
    print("Taunter: (A childish hand gesture). ")
i = 0
while i < cnt:
    print("Taunter: ", end='')
    result = ""
    taunt()
    print(result + ". ")
    i += 1
print()