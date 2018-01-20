import time

def f1(x):
    return -x*x - x + 10


print("Całkowanie numeryczne metodą prostokątów\n")

lowerLimit = -10
upperLimit = 19

numberOfRectangles = 10000000
integralValue = 0
widthOfSingleTrapeze = (upperLimit - lowerLimit) / numberOfRectangles

print("Szerokość pojedynczego prostokąta = " + str(widthOfSingleTrapeze))

start = time.clock()
for i in range(0, numberOfRectangles):
    integralValue += f1(lowerLimit + i*widthOfSingleTrapeze)

integralValue += (f1(lowerLimit) + f1(upperLimit)) / 2
integralValue *= widthOfSingleTrapeze
end = time.clock()
executionTimeOfAlgorithm = end - start

print("Wynik calkowania metoda prostokatow: " + str(integralValue))
print("Wynik został uzyskany w ciągu: " + str(executionTimeOfAlgorithm) + "s")
