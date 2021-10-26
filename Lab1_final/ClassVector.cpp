#include <iostream>
#include "ClassVector.h"

vector::vector() { //basic
	size = 0;
	v = NULL;
}

vector::vector(const size_t size) {  //parametric
	this->size = size;
	v = new double[size];
	for (size_t i = 0; i < size; i++) {
		v[i] = 0;
	}
}

vector::vector(const vector& vec) {   //copy
	size = vec.size;
	v = new double[size];
	for (size_t i = 0; i < vec.size; i++)
	{
		v[i] = vec.v[i];
	}
}

size_t vector::GetSize() const
{
	return size;
}

double& vector::operator[] (const size_t index)
{
	if (index > size) throw ("Invalid index");
	return v[index];
}

double vector::operator[] (const size_t index) const
{
	if (index > size) throw("Invalid index");
	return v[index];
}

vector vector::operator+= (const vector& vec)
{
	if (size != vec.size) throw("Different sizes");
	for (size_t i = 0; i < size; i++)
	{
		v[i] += vec.v[i];
	}
	return *this;
}

vector vector::operator+ (const vector& vec)
{
	if (size != vec.size) throw("Different sizes");
	vector tmp(*this);
	tmp += vec;
	return tmp;
}

vector& vector::operator= (const vector& vec)
{
	if (this == &vec) return *this;
	if (size != vec.size)
	{
		delete[] v;
		size = vec.size;
		v = new double[size];
		for (size_t i = 0; i < size; i++)
		{
			v[i] = vec.v[i];
		}
		return *this;
	}
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			v[i] = vec.v[i];
		}
		return *this;
	}
}

vector vector::operator-= (const vector& vec)
{
	if (size != vec.size) throw("Different sizes");
	for (size_t i = 0; i < size; i++)
	{
		v[i] -= vec.v[i];
	}
	return *this;
}


vector vector::operator- (const vector& vec)
{
	if (size != vec.size) throw("Different sizes");
	vector tmp(*this);
	tmp -= vec;
	return tmp;
}

double vector::operator* (const vector& vec)
{
	if (size != vec.size) throw("Different sizes");
	double result = 0;
	for (size_t i = 0; i < size; i++) {
		result += vec.v[i] * v[i];
	}
	return result;
}

vector vector::operator*= (const double x) //multiplied by number
{
	for (size_t i = 0; i < size; i++) {
		v[i] = v[i] * x;
	}
	return *this;
}

vector vector::operator* (const double x)  //multiplied by number
{
	vector tmp = *this;
	tmp *= x;
	return tmp;
}

vector vector::operator/= (const double x)
{
	if (x == 0) throw("Invalid denominator");
	for (size_t i = 0; i < size; ++i) {
		v[i] /= x;
	}
	return *this;
}

vector vector::operator/ (const double x)
{
	if (x == 0) throw("Invalid denominator");
	vector tmp = *this;
	tmp /= x;
	return tmp;
}

vector::~vector()
{
	delete[] v;
}

std::ostream& operator<< (std::ostream& out, const vector& vec)
{
	out << "Size:" << vec.GetSize() << std::endl;
	for (size_t i = 0; i < vec.GetSize(); i++)
	{
		out << vec[i] << std::endl;
	}
	return out;
}
