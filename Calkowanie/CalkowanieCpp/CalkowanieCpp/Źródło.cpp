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
	std::cout << "Ca�kowanie numeryczne metod� prostok�t�w\n" << std::endl;


	double lowerLimit{}, upperLimit{}, widthOfSingleRectangle{}, integralValue{};
	int numberOfRectangles{};

	// przedzialy
	lowerLimit = -10;
	upperLimit = 19;

	// im wieksze n tym wieksza dokladnosc (tym wiecej prostok�tow)
	numberOfRectangles = 10000000;

	widthOfSingleRectangle = (upperLimit - lowerLimit) / (double)numberOfRectangles;

	std::cout << "Szeroko�� pojedynczego prostok�ta = " << widthOfSingleRectangle << std::endl;

	clock_t start = clock();

	for (int i = 1; i <= numberOfRectangles; i++)
	{
		integralValue += f1(lowerLimit + i*widthOfSingleRectangle)*widthOfSingleRectangle;
	}
	clock_t end = clock();

	double executionTimeOfAlgorithm = double(end - start)/ CLOCKS_PER_SEC;


	std::cout << "Wynik calkowania metoda prostokatow: " << integralValue << std::endl;
	std::cout << "Wynik zosta� uzyskany w ci�gu: " << (end - start) << " takt�w procesora" << std::endl;
	std::cout << "Takty procesora w sekundzie: " << CLOCKS_PER_SEC << std::endl;
	std::cout << "Wynik zosta� uzyskany w ci�gu: " << executionTimeOfAlgorithm << "s" << std::endl;



	std::system("pause");
	return EXIT_SUCCESS;
}