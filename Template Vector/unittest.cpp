#include <gtest/gtest.h>
#include "vector.h"

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(TestVectorCTORs, constructor) 
{
	Vector<int> vector;
	Vector<int> vector1(5, 100);
	Vector<int> vector2 = vector1;
	vector2 = vector;
}

TEST(TestVectorFunctions, TestResizeFunc) 
{
	Vector<int> vector(5, 9);

	vector.resize(10, 8);
}

TEST(TestVectorFunctions, TestReserveFunc) 
{
	Vector<int> vector(5, 9);

	vector.reserve(10);
}

TEST(TestVectorOperators,TestIndexOperator) 
{
	Vector<int> vector(5, 9);
	ASSERT_TRUE(vector[1] == 9);

	vector[1] = 8;
	ASSERT_TRUE(vector[1] == 8);
}

TEST(TestVectorFunctions, TestAtFunc) 
{
	Vector<int> vector(5, 9);
	ASSERT_TRUE(vector.at(1) == 9);

	vector[1] = 8;
	ASSERT_TRUE(vector.at(1) == 8);

	ASSERT_THROW(vector.at(10) = 8, std::out_of_range);
}

TEST(TestVectorFunctions, TestDataFunc) 
{
	Vector<int> vector(5, 9);
	int *tmp = vector.data();
	tmp[0] = 1;
}

TEST(TestVectorFunctions, TestAssignFunc) 
{
	Vector<int> vector(5,9);
	vector.assign(2,3);
	ASSERT_EQ(vector[1],3);
	ASSERT_EQ(vector.size(), 2);
	ASSERT_EQ(vector.capacity(), 2);
}


TEST(TestVectorFunctions, TestPushBackFunc) 
{
	Vector<int> vector(2,9);
	vector.push_back(2);
	ASSERT_EQ(vector[2],2);
	ASSERT_EQ(vector.size(), 3);
	ASSERT_GE(vector.capacity(), 3);
}

TEST(TestVectorFunctions, TestPopBackFunc) 
{
	Vector<int> vector(2,9);
	vector.pop_back();
	ASSERT_THROW(vector.at(1),std::out_of_range);
	ASSERT_EQ(vector.size(), 1);
	ASSERT_GE(vector.capacity(), 1);
}

TEST(TestVectorFunctions, TestInsertFunc) 
{
	Vector<int> vector(4,9);
	vector.insert(&(vector[1]),3,7);
	ASSERT_EQ(vector[0],9);
	ASSERT_EQ(vector[1],7);
	ASSERT_EQ(vector[6],9);
	ASSERT_EQ(vector.size(), 7);
	ASSERT_EQ(vector.capacity(), 7);
	vector.insert(&(vector[0]),2,5);
	Vector<int> vector2;
	vector2.insert(0,2,5);
}


TEST(TestVectorFunctions, TestEraseFunc) 
{
	Vector<int> vector;
	for(int i=0; i<10;vector.push_back(i),++i);

	vector.erase(&vector[3]);        
	ASSERT_EQ(vector[3],4);
	ASSERT_EQ(vector.size(),9);
	vector.erase(&vector[2],5);
	ASSERT_EQ(vector[4],9);
	ASSERT_EQ(vector.size(),4);
}


TEST(TestVectorFunctions, TestClearFunc) 
{
	Vector<int> vector;
	for(int i=0; i<10;vector.push_back(i),++i);

	vector.clear();        

	ASSERT_EQ(vector.size(),0);
	ASSERT_THROW(vector.at(1),std::out_of_range);
}


