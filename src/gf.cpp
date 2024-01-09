#include "gf.h"
#include <iostream>
#include <vector>

using namespace std;

class GF_N
{
	public:
		//the irreducicle polynomial for AES
		unsigned int prime_poly = 0b100011011;
		unsigned int deg_prime = 8;
		
		void set_poly(unsigned int a){
			prime_poly = a;
			deg_prime = degree(a);
		}

		//additon mod 2 is equivalent to XOR
		unsigned int add(unsigned int a, unsigned int b){ return a^b;}
		
		//multiply a by each term of b seperately then add the result
		unsigned int multiply(unsigned int a, unsigned int b){
			unsigned int c = 0;
			int i = 0;
			while(b > 0){
				if(b & 1) c ^= a << i;	
				b >>= 1;
				i++;
			}
			return c;
		}

		//reduce the polynomial mod the prime polynomial
		unsigned int mod_reduction(unsigned int a){
			unsigned int deg_a = degree(a);
			if(deg_a < deg_prime) return a;
			else if(deg_a == deg_prime){
				unsigned int k = turnOffBitsExceptNth(a, deg_a);
				return prime_poly ^ k;
			}
			else return multiply(prime_poly, a);
		}

		//return the degree of a polynomial
		int degree(unsigned int a){
			unsigned int d = 0;
			if(a == 0){
				std::cerr << "Degree is undefined for zero polynomial" << std::ends;
				return -1;
			}
			while( (a >> d) > 0) ++d;
			return d-1;
		}

		//turn off every bit except the n'th in a byte 
		unsigned int turnOffBitsExceptNth(unsigned int d, unsigned int n){
			unsigned int mask = 1 << n;
			return (d & mask);
		}

		//return the remainder when two polys are divided not in field
		unsigned int rem(unsigned int a, unsigned int b){
			if(b == 0){
				std::cerr << "cannot divide by 0" << std::ends;
				return 0;
			}
			else if(a == 0) return 0;
			unsigned int result = a;
			unsigned int pos = 0;
			while(degree(result) >= degree(b)){
				pos = degree(result) - degree(b);
				result ^= b << pos;
			}
			return result;	
		}

		//find the inverse of this polynomial using EEA
		std::vector<unsigned int> extended_euclid_rec(unsigned int a,
				unsigned int b){
			unsigned int d, x, y;
			std::vector<unsigned int> result = {0, 0, 0};
			if(b == 0){
				result = {a, 1, 0};
				return result;
			}
			return result;
		}
	
};

/*
int main(int argc, char **argv)
{
	return 1;
}
*/



