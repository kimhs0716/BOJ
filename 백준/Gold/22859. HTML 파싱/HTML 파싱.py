import re
s = input()
remove_space = re.compile('\s+')
p1 = re.compile('<div title="(.+?)">(.+?)</div>')
p2 = re.compile('</?.+?>')
p3 = re.compile('<p>(.+?)</p>')
m = p1.findall(s)
for i in m:
    print('title :', re.sub(remove_space, ' ', i[0]))
    for j in p3.findall(i[1]):
        print(re.sub(remove_space, ' ', re.sub(p2, '', j)))
