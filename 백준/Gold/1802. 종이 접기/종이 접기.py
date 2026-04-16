def c(s):
  if (l:=len(s))==1:return 1
  for i in range(l//2):
    if s[i]==s[-i-1]:return 0
  return c(s[:l//2])
exec("print('NYOE S'[c(input())::2]);"*int(input()))