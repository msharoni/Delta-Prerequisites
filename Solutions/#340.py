import math
def fun(List):
    shortest =  distance(List[0],List[1])
    points=[]
    for i in range(len(List)):
        for j in range(len(List)):
            if(i!=j):
                distance(List[i],List[j])
                if(distance<=shortest):
                    shortest = distance
                    points = [List[i],List[j]]
    return points
def distance(p1,p2):
    return math.sqrt(abs(p1[0] - p2[0])**2 + abs(p1[1] - p2[1])**2)
print(fun([(1, 1), (-1, -1), (1, 3.9), (6, 1), (-1, -6), (-4, -3)]))
