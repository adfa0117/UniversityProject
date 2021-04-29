import random
import copy

player = ["재우", "재원", "창현", "찬우", "남석", "기준", "동우", "균도", "소원", "정호"]
line = ["탑", "정글", "미드", "원딜", "서폿"]
teamLength = 5
isLine = True
Exit = False
while not(Exit):
    print("1팀")
    tempPlayer = copy.copy(player)
    for i in range(teamLength):
        value = random.choice(tempPlayer)
        tempPlayer.remove(value)
        if isLine is True:
            print(line[i], ": ", value)
        else:
            print(value)
    print("2팀")
    for i in range(teamLength):
        value = random.choice(tempPlayer)
        tempPlayer.remove(value)
        if isLine is True:
            print(line[i], ": ", value)
        else:
            print(value)
    val = input("종료? [Y]")
    if val == "y" or val == "Y":
        Exit = True
