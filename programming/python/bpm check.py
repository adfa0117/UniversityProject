end = False
while not(end):
    i = input("bpm : ")
    if i.isdecimal():
        i = int(i)
        print(200/i)
    else:
        print("숫자를 입력하세요")
    
