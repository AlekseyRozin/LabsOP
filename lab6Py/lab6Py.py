def getDotDistance(x,y):
    return (x*x + y*y)**0.5

def setCoordinates(i):
    x = float(input("\nТочка {0} - Введите координату х: ".format(i)))
    y = float(input("Точка {0} - Введите координату х: ".format(i)))
    return x, y

def getNearestDot():
    x, y = setCoordinates(1)
    nearestDistance = getDotDistance(x, y)
    for i in range(2,n+1):
        x, y = setCoordinates(i)
        currDistance = getDotDistance(x, y)
        if (currDistance < nearestDistance):
            nearestDistance = currDistance
            nearestDot = i
    return nearestDot

#основная программа -----------------------------------------------------------------------------
nearestDot = 1
n = int(input("Введите кол-во точек, координаты которых будете вводить: "))
print("\nБлиже вего к началу координат находится точка ", getNearestDot())
print()