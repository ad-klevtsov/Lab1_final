#pragma once
#include <iostream>
#include <string>
class vector {
private:
	size_t size;
	double* v;
public:
	vector();
	vector(const size_t size);
	vector(const vector& vec);
	size_t GetSize() const; //GetSize
	double& operator[] (const size_t index);
	double operator[] (const size_t index) const;
	vector operator+= (const vector& vec);
	vector operator+ (const vector& vec);
	vector& operator= (const vector& vec);
	vector operator-= (const vector& vec);
	vector operator- (const vector& vec);
	double operator* (const vector& vec); //scalar
	vector operator*= (const double x); //multiplied by number
	vector operator* (const double x); //multiplied by number
	vector operator/= (const double x);
	vector operator/ (const double x);
	~vector();
	friend std::ostream& operator<< (std::ostream& out, const vector& point); //output
};

