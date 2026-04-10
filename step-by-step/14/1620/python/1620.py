import sys
from typing import Dict, List

def fastInput() -> str:
    return sys.stdin.readline().strip()

pokemonNormalList:List[str] = []
pokemonNameDict:Dict[str, int] = {}

n, queryNum = map(int, fastInput().split())

for i in range(n):
    string:str = fastInput()
    pokemonNormalList.append(string)
    pokemonNameDict[string] = i
    
for i in range(queryNum):
    stringOrNum:str = fastInput()
    if stringOrNum.isdigit():
        num:int = int(stringOrNum)
        print(pokemonNormalList[num - 1])
        
    else:
        print(pokemonNameDict[stringOrNum] + 1)