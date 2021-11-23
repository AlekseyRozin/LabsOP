def setCoordinates(i):
    global x
    global y
    x = float(input("Точка {0} - Введите координату х: ".format(i)))
    y = float(input("Точка {0} - Введите координату х: ".format(i)))

def getDotDistance(x,y):
    return (x*x + y*y)**0.5

def getNearestDot(nearestDistance):
    for i in range(2,n+1):
        setCoordinates(i)
        print()
        currDistance = getDotDistance(x, y)
        if (currDistance < nearestDistance):
            nearestDistance = currDistance
            nearestDot = i
    print("Ближе вего к началу координат находится точка ", nearestDot)

#основная программа -----------------------------------------------------------------------------
nearestDot, x, y = 1, 0, 0
n = int(input("Введите кол-во точек, координаты которых будете вводить: "))
setCoordinates(1)
print()
nearestDistance = getDotDistance(x, y)
getNearestDot(nearestDistance)
