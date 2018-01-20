package com.company;

public class Main {

    static double f1(double x)
    {
        // -x^2 - x + 10
        return -Math.pow(x, 2) - x + 10;
    }

    public static void main(String[] args) {
        // write your code here
        System.out.println("\n\nCałkowanie numeryczne metodą trapezów\n");

        double lowerLimit, upperLimit, widthOfSingleTrapeze, integralValue = 0;
        int numberOfIntervals;
        // przedzialy
        lowerLimit = -10;
        upperLimit = 19;

        // im wieksze n tym wieksza dokladnosc (tym wiecej prostokątow)
        numberOfIntervals = 10000000;

        widthOfSingleTrapeze = (upperLimit - lowerLimit) / (double)numberOfIntervals;
        System.out.println("Szerokość pojedynczego trapezu = " + widthOfSingleTrapeze);

        long start = System.currentTimeMillis(); // start timing

        for (int i = 1; i <= numberOfIntervals; i++)
        {
            integralValue += f1(lowerLimit + i*widthOfSingleTrapeze);
        }
        integralValue += (f1(lowerLimit) + f1(upperLimit)) / 2;
        integralValue *= widthOfSingleTrapeze;


        long end = System.currentTimeMillis(); // start timing
        float executionTimeOfAlgorithm = end - start;
        executionTimeOfAlgorithm = executionTimeOfAlgorithm/1000;

        System.out.println("Funkcja podcałkowa: -x^2 - x + 10");
        System.out.println("Dolne ograniczenie: " + lowerLimit);
        System.out.println("Górne ograniczenie: " + upperLimit);
        System.out.println("Wynik calkowania metoda trapezów: " + integralValue);
        System.out.println("Wynik został uzyskany w ciągu: " + executionTimeOfAlgorithm + " sekund");
    }



}
