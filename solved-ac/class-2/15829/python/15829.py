R:int = 31
M:int = 1234567891

length:int = int(input())
string:str = input()

sum:int = 0
for i, c in enumerate(string):
    sum += (ord(c) - 97 + 1) * (R ** (i))
    
sum %= M

print(sum)