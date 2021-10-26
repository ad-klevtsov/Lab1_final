#include "pch.h"
#include "../Lab1_final/ClassVector.h"
#include "../Lab1_final/ClassVector.cpp"

TEST(vector, Constructor) {
	vector a;
	EXPECT_EQ(0, a.GetSize());
}

TEST(vector, Constructor_Parametric) {
	vector a(3);
	EXPECT_EQ(3, a.GetSize());
}

TEST(vector, Constructor_Copy) {
	vector a(3);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	vector b = a;
	EXPECT_EQ(a[0], b[0]);
	EXPECT_EQ(a[1], b[1]);
	EXPECT_EQ(a[2], b[2]);
}


TEST(vector, Method_GetSize) {
	vector a(3);
	EXPECT_EQ(3, a.GetSize());
}

TEST(vector, Operator_SquareBrackets) {
	vector a(3);
	a[0] = 1;
	EXPECT_EQ(1, a[0]);
}

TEST(vector, Operator_SquareBrackets_Exception) {
	vector a(3);
	EXPECT_THROW(a[-1], const char*);
}

TEST(vector, Operator_Plus) {
	vector a(3);
	vector b(4);
	EXPECT_THROW(a + b, const char*);
}

TEST(vector, Operator_ScalarMultiplication) {
	vector a(3);
	vector b(4);
	EXPECT_THROW(a * b, const char*);
}

TEST(vector, Operator_MultiplicationByNumber) {
	vector a(3);
	a[0] = 1; 
	a[1] = 1;
	a[2] = 1;
	vector b = a * 2; 
	EXPECT_EQ(2, b[0]);
	EXPECT_EQ(2, b[1]);
	EXPECT_EQ(2, b[2]);
}

TEST(vector, Operator_DivisionByNumber) {
	vector a(3);
	a[0] = 2;
	a[1] = 2;
	a[2] = 2;
	vector b = a / 2;
	EXPECT_EQ(1, b[0]);
	EXPECT_EQ(1, b[1]);
	EXPECT_EQ(1, b[2]);
}

TEST(vector, Operator_DivisionByNumber_Exception) {
	vector a(3);
	a[0] = 2;
	a[1] = 2;
	a[2] = 2;
	EXPECT_THROW(a / 0, const char*);
}