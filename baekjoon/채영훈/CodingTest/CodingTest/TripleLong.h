#pragma once
#include <string>

using namespace std;

struct TripleLong
{
public:
	TripleLong();
	TripleLong(const string& val);
	~TripleLong();

	const bool isMinus(const TripleLong& val) const noexcept;
	const string SetVal(const string& val);
	const string GetVal() const;

	TripleLong& operator--();
	TripleLong& operator++();

	TripleLong& operator+=(TripleLong& rhs);
	TripleLong& operator-=(TripleLong& rhs);
	TripleLong& operator*=(TripleLong& rhs);
	TripleLong& operator/=(TripleLong& rhs);
	TripleLong& operator%=(TripleLong& rhs);
	TripleLong& operator=(const TripleLong& rhs);

	TripleLong operator+(TripleLong& rhs);
	TripleLong operator-(TripleLong& rhs);
	TripleLong operator*(TripleLong& rhs);
	TripleLong operator/(TripleLong& rhs);
	TripleLong operator%(TripleLong& rhs);
private:
public:
private:
	string val;
};
