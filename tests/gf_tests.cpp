#include "gf.cpp"
#include <gtest/gtest.h>


using namespace std;

TEST(PolynomialAdditionTest, addition)
{
	GF_N aes;
	ASSERT_EQ(0b01010101, aes.add(0b10101010, 0b11111111));
}

TEST(PolynomialMultiplicatonTest, multiplication)
{
	GF_N aes;
	ASSERT_EQ(0b11111100, aes.multiply(0b00010101, 0b00001100));
}

TEST(ModuloReductionTest, reduction)
{
	GF_N aes;
	ASSERT_EQ(0b00000100, aes.mod_reduction(0b00000100));
	ASSERT_EQ(0b000011011, aes.mod_reduction(0b100000000));
	//ASSERT_EQ(0b00000000,  aes.mod_reduction(0b10000100));
	//ASSERT_EQ(0b10000000, aes.mod_reduction(0b));
}

TEST(DegreeTest, degree)
{
	GF_N aes;
	ASSERT_EQ(0, aes.degree(0b00000001));
	ASSERT_EQ(1, aes.degree(0b00000010));
	ASSERT_EQ(7, aes.degree(0b10000000));
	ASSERT_EQ(-1, aes.degree(0));
}

TEST(TurnEveryBitExceptNth, byte)
{
	GF_N aes; 
	ASSERT_EQ(0b00010000, aes.turnOffBitsExceptNth(0b11111111, 4));
}

/*
TEST(InvesrionTest, testInverses)
{
	BankAccount instance;
	instance.deposite(100);
	EXPECT_EQ(100, instance.balance);
}
*/


int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);	
	return RUN_ALL_TESTS();
}
