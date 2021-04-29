from random import *
repeat = True
while repeat:
    ranMin = input("숫자 최소치 : ")
    while not(ranMin.isdecimal()):
        print("숫자만 입력하세요.")
        ranMin = input("숫자 최소치 : ")
    ranMax = input("숫자 최대치 : ")
    while not(ranMax.isdecimal() and ranMax > ranMin):
        if not(ranMax.isdecimal()):
            print("숫자만 입력하세요.")
        elif ranMax <= ranMin:
            print("최대치는 최소치보다 커야합니다.")
        ranMax = input("숫자 최대치 : ")
    count = input("출력 횟수 : ")
    while not(count.isdecimal()):
        print("숫자만 입력하세요.")
        count = input("출력 횟수 : ")
    ranMin = int(ranMin)
    ranMax = int(ranMax)
    count = int(count)
    for i in range(count):
        output = randrange(ranMin,ranMax, 1)
        print(output)
    isRepeat = input("끝내시려면 y를 아니라면 다른 키를 눌러주십시오.")
    if isRepeat == "Y" or isRepeat == "y":
        repeat = False
        
    
