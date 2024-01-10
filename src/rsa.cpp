#include "rsa.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#define MOD(x, n) ((x % n + n) % n)

using namespace std;

class RSA{
	public:

	long key_gen(long p, long q){
		std::random_device rd;
		std::mt19937 gen(rd());
		long n = p * q, phi = (p-1)*(q-1), e, d;
		std::vector<long> stack;
		//choosing e should be random
		//push all element such that gcd(i, phi) = 1 onto the stack
		for(int i = 0; i < phi; i++){
			if(gcd(i, phi) == 1)
			{
				stack.push_back(i);
			}
		}
		//shuffle the stack
		std::shuffle(stack.begin(), stack.end(), gen);
		//since that stack is shuffled, any index should be sufficent
		e = stack[0];
		//find the inverse of e mod phi	
		return n;
	}
	
	long eea(long a, long b){
		long x, y;
		return extended_euclid_rec(a, b, x, y);
	}

	long extended_euclid_rec(long a, long b, long &x, long &y)
	{
		if(b == 0){
			x = 1;
			y = 0;
			return a;
		}
		long r = extended_euclid_rec(b, a%b, x, y), t = y;
		y = x - (a/b) * y;
		x = t;
		return r;
	}

	//using Euclid, compute the gcd of two longs
	long gcd(long a, long b){
		long q, r;
		while(b > 0){
			q = a/b;
			r = a - q * b;
			a = b;
			b = r;
		}
		return a;
	}

	//recurisive version
	long gcd_rec(long a, long b){
		long r = MOD(a, b), gcd;
		if(r == 0) return b;
		gcd = gcd_rec(b, r);
		return gcd;
	}

};

/*
 *int main(int argc, char **argv)
  {
  	return 1;
  }
 */
