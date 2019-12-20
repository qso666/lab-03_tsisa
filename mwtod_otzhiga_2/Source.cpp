#include <iostream>
#include "math.h"
#include <random>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
double random(double left, double right)
{
	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(left * 100000000, right * 100000000);
	double x = distribution(generator);
	return x / 100000000;
}
double function(double x)
{
	double y = exp(-0.1 * x) * sin(x) - 2;
	return y;
}
double multifunction(double x)
{
	double y = (exp(-0.1 * x) * sin(x) - 2) * sin(5 * x);
	return y;
}
bool probability(double prob)
{
	double value = random(0, 1);
	if (value <= prob)
		return true;
	else
		return false;
}
void metod_otzhiga(double left, double right)
{
	double x, xk, P, df, xmin;
	std::string p;
	double Tmax = 1000;
	double Tmin = 0.001;
	double T = Tmax;
	xk = random(left, right);
	xmin = xk;
	int i = 1;
	std::cout << std::fixed;
	std::cout << std::setw(4) << "N" << "|" << std::setw(12) << "T" << "|" << std::setw(10) << "x" << "|" << std::setw(12) << "f(x)" << "|" << std::setw(12) << "P" << "|" << std::setw(13) << "Performed?" << "|" << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
	while (T > Tmin)
	{

		if (T == 1000)
		{
			P = 1;
			p = "yes";
			std::cout << std::setw(4) << i << "|" << std::setw(12) << T << "|" << std::setw(10) << xk << "|" << std::setw(12) << function(xk) << "|" << std::setw(12) << P << "|" << std::setw(13) << p << "|" << std::endl;
			T = Tmax * 0.95;
			Tmax = T;
			i++;
			continue;
		}
		x = random(left, right);
		df = function(x) - function(xk);
		if (df <= 0)
		{
			P = 1;
			xk = x;
			p = "yes";
		}
		else
		{
			P = exp(-df / T);
			probability(P);
			if (probability(P) == true)
			{
				xk = x;
				p = "yes";
			}
			else
			{
				p = "no";
			}
		}
		std::cout << std::setw(4) << i << "|" << std::setw(12) << T << "|" << std::setw(10) << xk << "|" << std::setw(12) << function(xk) << "|" << std::setw(12) << P << "|" << std::setw(13) << p << "|" << std::endl;
		if (function(xk) < function(xmin))
		{
			xmin = xk;
		}
		T = Tmax * 0.95;
		Tmax = T;
		i++;
	}
	std::cout << "---------------------------------------------------------------------" << std::endl;
	std::cout << "Xmin=" << xmin << ' ' << "Fmin=" << function(xmin);
	std::cout << std::endl << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
	std::cout << std::setw(4) << "N" << "|" << std::setw(12) << "T" << "|" << std::setw(10) << "x" << "|" << std::setw(12) << "f(x)" << "|" << std::setw(12) << "P" << "|" << std::setw(13) << "Performed?" << "|" << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
	xk = random(left, right);
	xmin = xk;
	Tmax = 1000;
	Tmin = 0.001;
	T = Tmax;
	i = 1;
	while (T > Tmin)
	{
		if (T == 1000)
		{
			P = 1;
			p = "yes";
			std::cout << std::setw(4) << i << "|" << std::setw(12) << T << "|" << std::setw(10) << xk << "|" << std::setw(12) << function(xk) << "|" << std::setw(12) << P << "|" << std::setw(13) << p << "|" << std::endl;
			T = Tmax * 0.95;
			Tmax = T;
			i++;
			continue;
		}
		x = random(left, right);
		df = multifunction(x) - multifunction(xk);
		if (df <= 0)
		{
			P = 1;
			xk = x;
			p = "yes";
		}
		else
		{
			P = exp(-df / T);
			probability(P);
			if (probability(P) == true)
			{
				xk = x;
				p = "yes";
			}
			else
			{
				p = "no";
			}
		}
		std::cout << std::setw(4) << i << "|" << std::setw(12) << T << "|" << std::setw(10) << xk << "|" << std::setw(12) << function(xk) << "|" << std::setw(12) << P << "|" << std::setw(13) << p << "|" << std::endl;
		if (multifunction(xk) < multifunction(xmin))
		{
			xmin = xk;
		}
		T = Tmax * 0.95;
		Tmax = T;
		i++;
	}
	std::cout << "---------------------------------------------------------------------" << std::endl;
	std::cout << "Xmin=" << xmin << ' ' << "Fmin=" << multifunction(xmin);
}
int main()
{
	metod_otzhiga(-3, 0);
	return 0;
}