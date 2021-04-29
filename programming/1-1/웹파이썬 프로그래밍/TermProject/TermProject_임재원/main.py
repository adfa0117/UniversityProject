from PyToMc.mcpi import minecraft
import math
import urllib.request
from PIL import Image
from io import BytesIO
import numpy as np
import math
import time

mc = minecraft.Minecraft.create()

posL = []
entityIdL = []
sizeL = []

#[x, y, z]위치에 주어진 color의 rgb값과 가장 차이가 적은 블럭을 설치하기 위한 함수
def setBlockRGB(x, y, z, color):
    #설치할 블럭들의 id, data모음
    block = [[251, 0], [251, 1], [251, 2], [251, 3],
             [251, 4], [251, 5], [251, 6], [251, 7],
             [251, 8], [251, 9], [251, 10], [251, 11],
             [251, 12], [251, 13], [251, 14], [251, 15],
             [159, 0], [159, 1], [159, 2], [159, 3],
             [159, 4], [159, 5], [159, 6], [159, 7],
             [159, 8], [159, 9], [159, 10], [159, 11],
             [159, 12], [159, 13], [159, 14], [159, 15]]
             
    #위 block에 상응하는 블럭들의 rgb값
    colors = [[207, 213, 214], [224, 97, 1], [169, 48, 159], [39, 137, 199],
              [241, 175, 21], [94, 169, 24], [214, 101, 143], [55, 58, 62],
              [125, 125, 115], [21, 119, 136], [100, 32, 156], [45, 47, 143],
              [96, 60, 32], [73, 91, 36], [142, 33, 33], [8, 10, 15],
              [210, 178, 161], [162, 84, 38], [150, 88, 109], [113, 109, 138],
              [186, 133, 35], [104, 118, 53], [162, 78, 79], [58, 42, 36],
              [135, 107, 98], [87, 91, 91], [118, 70, 86], [74, 60, 91],
              [77, 51, 36], [76, 83, 42], [143, 61, 47], [37, 23, 16]]
              
    #color에 가장 가까운 색깔을 갖고 있는 블럭의 index
    index = 0
    
    #colors의 rgb값과 color의 rgb값의 차이의 최솟값
    minC = distanceRGB(color, colors[0])
    
    #minC와 index를 구하기 위한 for문
    for i in range(len(colors)):
        dis = distanceRGB(color, colors[i])
        if dis < minC:
            minC = dis
            index = i
    
    #rgb값이 가장 차이가 적은 블럭을 [x, y, z]위치에 설치
    mc.setBlock(x, y, z, block[index][0], block[index][1])
    
#두 color의 rgb값의 차이를 반환하는 함수
def distanceRGB(color1, color2):
    #red값의 차이
    dr = color1[0] - color2[0]
    #green값의 차이
    db = color1[1] - color2[1]
    #blue값의 차이
    dg = color1[2] - color2[2]
    
    #세 값의 차이를 두 점 사이의 거리를 구하는 방식으로 구함
    return math.sqrt(dr*dr+db*db+dg*dg)
   
#종료시 호출되는 함수
def mcpi_exit(name):
    mc.postToChat("[{0}] 종료합니다.".format(name))
    print(name, " -> [Success] exit")

#등록시 호출되는 함수
def register(name, entityId, entityIdL, posL, sizeL):
    #이미 등록되어있는 경우
    if entityId in entityIdL:
        mc.postToChat("[{0}] 이미 등록되어 있습니다.".format(name))
        print(name, " -> [Fail] register")
        print("entityId is in entityIdL")
    
    #등록되어있지 않는 경우
    else:
        #리스트들을 확장시키고 default값을 넣어줌
        entityIdL.append(entityId)
        posL.append([0, -1, 0])
        sizeL.append([-1, -1])
        mc.postToChat("[{0}] 등록되었습니다.".format(name))
        print(name, " -> [Success] register")

#사진이 출력될 위치를 정하는 함수
def setPos(name, args, index, entityId, posL):
    if args == 1:
        pos = mc.entity.getPos(entityId)
        x = math.floor(pos.x)
        y = math.floor(pos.y)
        z = math.floor(pos.z)
        pos = [x, y, z]
        posL[index] = pos
        mc.postToChat("[{0}] 좌표가 {1}로 설정되었습니다.".format(name, pos))
        print(name, " -> [Success] setPos")
    else:
        mc.postToChat("[{0}] 올바르지 않은 입력".format(name))
        print(name, " -> [Fail] setPos")
        print("args is ", args)
        
def getPos(name, args, index, posL):
    if args == 1:
        if posL[index][1] == -1:
            mc.postToChat("[{0}] 아직 좌표를 설정하지 않았습니다. setPos를 쳐서 좌표를 설정해 주세요.".format(name))
            print(name, " -> [Fail] getPos")
            print("pos not set")
        else:
            mc.postToChat("[{0}] 좌표는 {1}입니다".format(name, posL[index]))
            print(name, " -> [Success] getPos")
    else:
        mc.postToChat("[{0}] 올바르지 않은 입력".format(name))
        print(name, " -> [Fail] getPos")
        print("args is ", args)

def setSize(name, args, cmd, index, sizeL):
    if args == 1:
        mc.postToChat("[{0}] setSize width height".format(name))
        print(name, " -> [Fail] setSize")
        print("args is ", args)
    elif args == 3:
        if cmd[1].isdigit() and cmd[2].isdigit():
            width = int(cmd[1])
            heigth = int(cmd[2])
            if(width > 320):
                width = 320
                mc.postToChat("[{0}] 폭은 최대 320입니다.".format(name))
            if(heigth > 320):
                heigth = 320
                mc.postToChat("[{0}] 높이는 최대 320입니다.".format(name))
            sizeL[index] = [width, heigth]
            mc.postToChat("[{0}] 크기가 {1}로 설정되었습니다.".format(name, sizeL[index]))
            print(name, " -> [Success] setSize")
        else:
            mc.postToChat("[{0}] 크기는 양의 정수만 입력해주세요.".format(name))
            print(name, " -> [Fail] setSize")
            print("not positive integer")
    else:
        mc.postToChat("[{0}] 올바르지 않은 입력".format(name))
        print(name, " -> [Fail] setSize")
        print("args is ", args)

while True:
    chatEvents = mc.events.pollChatPosts()
    chat = ""
    entityId = 0
    for chatEvent in chatEvents:
        chat = chatEvent.message
        entityId = chatEvent.entityId
        cmd = chat.split(" ")
        args = len(cmd)
        name = mc.entity.getName(entityId)
        if(cmd[0].split("")[0] == "!"):
            if chat == "!exit":
                mcpi_exit(name)
                break
                
            elif chat == "!reg":
                register(name, entityId, entityIdL, posL, sizeL)
                
            if entityId in entityIdL:
                index = entityIdL.index(entityId)
                
                if cmd[0] == "!setPos":
                    setPos(name, args, index, entityId, posL)
                    
                elif cmd[0] == "!getPos":
                    getPos(name, args, index, posL)
                    
                elif cmd[0] == "!setSize":
                    setSize(name, args, cmd, index, sizeL)
                elif cmd[0] == "getSize":
                    if sizeL[index][0] == -1:
                        mc.postToChat(name + "님은 아직 크기를 설정하지 않았습니다. setSize를 쳐서 크기를 설정해 주세요.")
                    else:
                        mc.postToChat("{0}님의 크기는 {1}입니다.".format(name, sizeL[index]))
                elif cmd[0] == "print":
                    mc.postToChat("print url")
            elif args == 2:
                if cmd[0] == "print":
                    img = ""
                    try:
                        bImg = urllib.request.urlopen(cmd[1]).read()
                        img = Image.open(BytesIO(bImg))
                    except:
                        mc.postToChat("이미지를 받아오는데 실패하였습니다. 다시 시도해 보십시오.")
                    else:
                        if posL[index][1] == -1:
                            mc.postToChat(name + "님은 아직 좌표를 설정하지 않았습니다. setPos를 쳐서 좌표를 설정해 주세요.")
                        elif sizeL[index][0] == -1:
                            mc.postToChat(name + "님은 아직 크기를 설정하지 않았습니다. setSize를 쳐서 크기를 설정해 주세요.")
                        else:
                            img = img.resize((sizeL[index][0], sizeL[index][1]))
                            pix = np.array(img)
                            x = posL[index][0]
                            y = posL[index][1]
                            z = posL[index][2]
                            for i in range(sizeL[index][1]):
                                for j in range(sizeL[index][0]):
                                    time.sleep(0.0005)
                                    setBlockRGB(x + i, y, z + j, pix[i][j])
        else:
            mc.postToChat(name + "님은 아직 등록하지 않으셨습니다 reg를 쳐서 등록해주세요.")
    if chat == "exit":
        break
