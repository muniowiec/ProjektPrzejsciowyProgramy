#include<iostream>
#include<locale.h>
#include<ctime>
#include <iomanip>

double f1(double x)
{
	// -x^2 - x + 10
	return -pow(x, 2) - x + 10;
}

int main()
{
	setlocale(LC_ALL, "polish");
	std::cout.precision(6);
	std::cout.setf(std::ios::fixed);
	std::cout << "Ca³kowanie numeryczne metod¹ trapezów\n" << std::endl;


	double lowerLimit{}, upperLimit{}, widthOfSingleTrapeze{}, integralValue{};
	int numberOfIntervals{};

	// przedzialy
	lowerLimit = -10;
	upperLimit = 19;

	// im wieksze n tym wieksza dokladnosc (tym wiecej prostok¹tow)
	numberOfIntervals = 1000000;

	widthOfSingleTrapeze = (upperLimit - lowerLimit) / (double)numberOfIntervals;

	std::cout << "Szerokoœæ pojedynczego trapezu = " << widthOfSingleTrapeze << std::endl;

	clock_t start = clock();

	for (int i = 1; i <= numberOfIntervals; i++)
	{
		integralValue += f1(lowerLimit + i*widthOfSingleTrapeze);
	}
	integralValue += (f1(lowerLimit) + f1(upperLimit)) / 2;
	integralValue *= widthOfSingleTrapeze;
	clock_t end = clock();

	double executionTimeOfAlgorithm = double(end - start) / CLOCKS_PER_SEC;


	std::cout << "Wynik calkowania metoda trapezów: " << integralValue << std::endl;
	std::cout << "Wynik zosta³ uzyskany w ci¹gu: " << (end - start) << " taktów procesora" << std::endl;
	std::cout << "Takty procesora w sekundzie: " << CLOCKS_PER_SEC << std::endl;
	std::cout << "Wynik zosta³ uzyskany w ci¹gu: " << executionTimeOfAlgorithm << "s" << std::endl;



	std::system("pause");
	return EXIT_SUCCESS;
}