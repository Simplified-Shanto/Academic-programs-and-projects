tc = int(input())

while(tc> 0):
    tc-=1
    n = int(input())
    wordDict = {

    }
    points = [0, 0, 0]
    p1 = input()
    p1 =  p1.split()
    p2 = input()
    p2 = p2.split()
    p3 = input()
    p3 = p3.split()


    for x in p1:
        if x in wordDict:
            wordDict[x].append(0)
        else:
            wordDict[x] = []
            wordDict[x].append(0)
    
    for x in p2:
        if x in wordDict:
            wordDict[x].append(1)
        else:
            wordDict[x] = []
            wordDict[x].append(1)

    for x in p3:
        if x in wordDict:
            wordDict[x].append(2)
        else:
            wordDict[x] = []
            wordDict[x].append(2)

    
    
    for x in wordDict:
        if len(wordDict[x]) == 1:
            points[wordDict[x][0]] +=3
        elif len(wordDict[x]) == 2:
            points[wordDict[x][0]]+=1
            points[wordDict[x][1]]+=1





    print(str(points[0]) + " " + str(points[1]) + " " + str(points[2]))