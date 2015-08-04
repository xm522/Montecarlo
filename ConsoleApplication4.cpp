// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

int main()
{
	int seed = 0;
	double k = 0;

	double count = 0; /* # of points in the 1st quadrant of unit circle */
	//double z;
	//double pi;

	int j = 0;

	cout << "program will attempt to aproximate the value of pi to a statistical errors of order 1%, 0.01% and 0.00001%" << endl;
	cout << "lets choose our seed: ";
	cin >> seed;

	cout << " lets's check our seed: " << seed << endl;
	srand(seed);
	while (j < 3)
	{
		double pi;
		int i = 0;
		double h = 0;
		double U = 0;
		double npq = 0;
		double hh;
		double p;
		double q;
		double npq_2;
		cout << " we will now choose our number of iterations: ";
		cin >> k;
		count = 0;
		for (i = 0; i < k; i++)
		{
			double x, y;
			double z;


			x = (double)rand() / RAND_MAX;
			y = (double)rand() / RAND_MAX;
			z = x*x + y*y;
			if (z <= 1) count++;
			if (z > 1) h++;
		}
		pi = (double)count / k * 4;
		//   printf("# of trials= %d , estimate of pi is %g \n",k,pi);
		cout << " estimate for pi: " << pi << "  , for number of runs: " << k << endl;
		p = h / k;
		q = count / k;
		cout << "count: " << count << endl;
		cout << "p: " << p << endl;
		cout << "q: " << q << endl;
		npq = k*p*q;
		npq_2 = sqrt(npq*npq);
		cout << "npq: " << npq << " npq^2 (npq_2): " << npq_2 << endl;
		hh = (4.0 / k)*(4.0 / k);
		cout << "hh: " << hh << endl;
		U = sqrt(npq_2 * hh);

		cout << "statistical error for n # of runs: " << U << endl;

		// int yes = 0;
		// int no = 1;
		int jj;
		cout << " would you like to know the counts necessary for uncertainties of 1%, .1%, and .00001%? " << endl;
		cout << "choose 0 fo yes, and anything 1 and above for no: ";
		cin >> jj;

		while (jj < 1)
		{

			// k_1, _2, & _2 are the % divided by 100 to get interger form
			double N_1; // we will use this as our # of iterations
			double N_2;
			double N_3;
			double k_1 = 0.01; // we will use this as variance for 1%
			double k_2 = 0.001; // we will use this as var. for .1%
			double k_3 = 0.0000001; // variance for .00001%

			N_1 = (16 * p*q) / (k_1*k_1);
			cout << " number of iterations required for 1% " << N_1 << endl;
			N_2 = (16 * p*q) / (k_2*k_2);
			cout << " number of iterations required for .1% " << N_2 << endl;
			N_3 = (16 * p*q) / (k_3*k_3);
			cout << " number of iterations required for .00001% " << N_3 << endl;

			jj++;

		}
	}

	/* finding the statistical error is going to be Sig(pi) = sqrt([count_total * count out *(1- count out)]^2/[cont out] (*4 (numerator))) */

	// through recursive runs of the code i calculated p & q to 4 unchanging decimal places.
	// we can use this as a way to calculate the the k requred for a certain uncertainty.
	// also it is important to note the values of p & q are invariant of the seed.
	// we can also use the p & q generated from the code

}

