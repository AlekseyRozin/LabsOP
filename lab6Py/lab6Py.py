def setCoordinates(i):
    global x
    global y
    x = float(input("Точка {0} - Введите координату х: ".format(i)))
    y = float(input("Точка {0} - Введите координату х: ".format(i)))
    print()

def getDotDistance(x,y):
    return (x*x + y*y)**0.5

def getNearestDot():
    global nearestDot
    global nearestDistance
    for i in range(2,n+1):
        setCoordinates(i)
        currDistance = getDotDistance(x, y)
        if (currDistance < nearestDistance):
            nearestDistance = currDistance
            nearestDot = i

#основная программа -----------------------------------------------------------------------------
nearestDot = 1
n = int(input("Введите кол-во точек, координаты которых будете вводить: "))
setCoordinates(1)
nearestDistance = getDotDistance(x, y)
getNearestDot()
print("Ближе вего к началу координат находится точка ", nearestDot)