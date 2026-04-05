while True:
    string:str = input()
    
    if string == "0":
        break
    
    reversedStr:str = string[::-1]
    print("yes" if string == reversedStr else "no")