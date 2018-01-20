package com.company;

public class Main {

    static double f1(double x)
    {
        // -x^2 - x + 10
        return -Math.pow(x, 2) - x + 10;
    }

    public static void main(String[] args) {
	// write your code here
        System.out.println("Całkowanie numeryczne metodą prostokątów\n");

        double lowerLimit, upperLimit, widthOfSingleRectangle, integralValue = 0;
        int numberOfRectangles;
        // przedzialy
        lowerLimit = -10;
        upperLimit = 19;

        // im wieksze n tym wieksza dokladnosc (tym wiecej prostokątow)
        numberOfRectangles = 10000000;

        widthOfSingleRectangle = (upperLimit - lowerLimit) / (double)numberOfRectangles;
        System.out.println("Szerokość pojedynczego prostokąta = " + widthOfSingleRectangle);

        long start = System.currentTimeMillis(); // start timing

        for (int i = 1; i <= numberOfRectangles; i++)
        {
            integralValue += f1(lowerLimit + i*widthOfSingleRectangle)*widthOfSingleRectangle;
        }

        long end = System.currentTimeMillis(); // start timing
        float executionTimeOfAlgorithm = end - start;
        executionTimeOfAlgorithm = executionTimeOfAlgorithm/1000;

        System.out.println("Wynik calkowania metoda prostokatow: " + integralValue);
        System.out.println("Wynik został uzyskany w ciągu: " + executionTimeOfAlgorithm + " sekund");
    }



}
