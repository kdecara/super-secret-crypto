#include "rsa.cpp"
#include <gtest/gtest.h>


using namespace std;

TEST(gcd, gcd_1)
{
	RSA rsa;
	ASSERT_EQ(rsa.gcd(5, 5), 5);
	ASSERT_EQ(rsa.gcd_rec(105, 10), rsa.gcd(105, 10));
	ASSERT_EQ(rsa.gcd(40, 2), 2); 
}

TEST(eea, eea_1)
{
	RSA rsa;
	ASSERT_EQ(rsa.eea(5, 7), 2);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);	
	return RUN_ALL_TESTS();
}
