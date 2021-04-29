from PIL import Image
import numpy as np

color = ["white", "orange", "magenta", "light_blue", "yellow", "lime", "pink", "gray", "light_gray", "cyan", "purple", "blue", "brown", "green", "red", "black"]
ty = ["concrete", "terracotta"]
lst = []
mostColor = []

def colorCount(v, rgb, crgb):
    if v in rgb:
        index = rgb.index(v)
        crgb[index] += 1
    else:
        rgb.append(v)
        crgb.append(1)

for c in color:
    for t in ty:
        img = Image.open("blocks\\" + c + "_" + t + ".png")
        pix = np.array(img)
        ls = []
        for i in range(img.height):
            l = []
            for j in range(img.width):
                l.append(pix[i][j])
            ls.append(l)
        lst.append(ls)

for i in range(len(lst)):
    R = []
    G = []
    B = []
    cR = []
    cG = []
    cB = []
    c = 0
    for j in range(len(lst[i])):
        for k in range(len(lst[i][j])):
            colored = lst[i][j][k]
            colorCount(colored[0], R, cR)
            colorCount(colored[1], G, cG)
            colorCount(colored[2], B, cB)
            c += 1
    sumR = 0
    sumG = 0
    sumB = 0
    for l in range(len(R)):
        sumR += R[l]*cR[l]
    for l in range(len(G)):
        sumG += G[l]*cG[l]
    for l in range(len(B)):
        sumB += B[l]*cB[l]
    mR = cR.index(max(cR))
    mG = cG.index(max(cG))
    mB = cB.index(max(cB))
    mostColor.append([R[mR], G[mG], B[mB], int(round(sumR/256)), int(round(sumG/256)), int(round(sumB/256))])

for c in mostColor:
    print(c)
