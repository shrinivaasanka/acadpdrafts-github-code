/***************************************************************************************
ASFER - a ruleminer which gets rules specific to a query and executes them

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
 ERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

---------------------------------------------------------------------------------------------------
Copyright (C):
Srinivasan Kannan (alias) Ka.Shrinivaasan (alias) Shrinivas Kannan
Independent Open Source Developer, Researcher and Consultant
Ph: 9789346927, 9003082186, 9791165980
Open Source Products Profile(Krishna iResearch): http://sourceforge.net/users/ka_shrinivaasan
Personal website(research): https://sites.google.com/site/kuja27/
emails: ka.shrinivaasan@gmail.com, shrinivas.kannan@gmail.com, kashrinivaasan@live.com
---------------------------------------------------------------------------------------------------
*****************************************************************************************/

/*
#####################################################################################
 Old CPP test code written in 2006 for deriving error probability of majority voting
 and used 3 years ago in January 2010 during MSc thesis at IIT Chennai
 for deriving error probability of majority voting 
(Full report with results for Classification based on indegrees, TDT, Summarization, Citation graph Maxflow and 
Interview Algorithm based on Recursive Gloss Overlap Definition Graph: 
http://sourceforge.net/projects/acadpdrafts/files/MScThesis-Writeup-Complete.pdf/download)

For publications:
 1. http://arxiv.org/abs/1006.4458
 2. http://www.nist.gov/tac/publications/2010/participant.papers/CMI_IIT.proceedings.pdf
 and other publication drafts for majority voting BPNC circuits in https://sites.google.com/site/kuja27/
#####################################################################################
*/

/*
Updated draft for Majority Voting Error Probability based on hypergeometric functions has been uploaded at:
1.https://sites.google.com/site/kuja27/CircuitForComputingErrorProbabilityOfMajorityVoting_2014.pdf?attredirects=0&d=1
(and)
2.https://sites.google.com/site/kuja27/CircuitForComputingErrorProbabilityOfMajorityVoting_2014.tex?attredirects=0&d=1

Special case of convergence of the series when p=0.5 
----------------------------------------------------
P(good) = (2n)!/(4^n) { 1/(n+1)!(n-1)! + 1/(n+2)!(n-2)! + ... + 1/(n+n)!(n-n)!}
has been derived and shown to be 0.5 in the handwritten notes uploaded at:
http://sourceforge.net/p/asfer/code/HEAD/tree/cpp-src/miscellaneous/MajorityVotingErrorProbabilityConvergence.JPG
But when the individual terms above differ in exponents of the probability terms (i.e there is no uniformity) ,the convergence has to be established only through hypergeometric functions.

Special case of convergence of the series when p=1:
---------------------------------------------------
1= 0 + 0 + 0 + ...+ (2n)C(cn) (1)^n (0)^(0) = 1
Thus with zero error both pseudorandom choice and majority vote yield P(good)= 100%.
*/

using namespace std;
#include <iostream>
#include <fstream>

extern "C"
{
#include <stdio.h>
}

long double factorial(long double);
long double power_of_4(long double);

int main()
{
/*
P(good) = (2n)!/(4^n) { 1/(n+1)!(n-1)! + 1/(n+2)!(n-2)! + ... + 1/(n+n)!(n-n)!}
*/
	long double n = 0.0, i=0.0;
	long double prevsum = 0.0, sum = 0.0, prevsumdiff = 0.0, sumdiff = 0.0, term1 = 0.0;
	for(n = 0.0; n <= 30000.0; n++)
	{
		term1 = factorial(2*n) / power_of_4(n);
		for (i=1.0; i <= n ; i++)
			sum = sum + (1.0 / (factorial(n+i) * factorial(n-i)));
		sum = term1 * sum;
		cout << "Probability of good choice for population of " << 2*n << "=" << sum*100.0 <<endl;
		sumdiff = sum - prevsum;
		cout << "prob - prevprob = " << sumdiff << endl;
		cout << "Convergence test: (sum - prevsum)/prevsum = " << sumdiff/prevsum << endl;
		prevsum = sum;
		prevsumdiff = sumdiff;
		sum =0.0;
	}

}


long double factorial(long double n)
{
	if (n==0.0)
		return 1.0;
	else
		return (long double) n*factorial(n-1);
}

long double power_of_4(long double n)
{
	long double power = 1.0 ;
	long double i;
	for (i=n;i > 0.0;i--)
		power = power * 4.0;
	return power;
}
