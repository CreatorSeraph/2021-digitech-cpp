#include "TripleLong.h"
#include "stdafx.h"

TripleLong::TripleLong()
{
}

TripleLong::TripleLong(const string& val)
{
	SetVal(val);
}

TripleLong::~TripleLong()
{
}

const bool TripleLong::isMinus(const TripleLong& val) const noexcept
{
	if (val.val.empty()) return false;
	else return (val.val[0] == '-');
}

const string TripleLong::SetVal(const string& val)
{
	this->val = val;
	return GetVal();
}

const string TripleLong::GetVal() const
{
	return val;
}

TripleLong& TripleLong::operator--()
{
	TripleLong one = TripleLong("1");
	this->operator-=(one);
	return *this;
}

TripleLong& TripleLong::operator++()
{
	TripleLong one = TripleLong("1");
	this->operator+=(one);
	return *this;
}

TripleLong& TripleLong::operator+=(TripleLong& rhs)
{
	this->operator=(this->operator+(rhs));
	return *this;
}

TripleLong& TripleLong::operator-=(TripleLong& rhs)
{
	this->operator=(this->operator-(rhs));
	return *this;
}

TripleLong& TripleLong::operator*=(TripleLong& rhs)
{
	this->operator=(this->operator*(rhs));
	return *this;
}

TripleLong& TripleLong::operator/=(TripleLong& rhs)
{
	this->operator=(this->operator/(rhs));
	return *this;
}

TripleLong& TripleLong::operator%=(TripleLong& rhs)
{
	this->operator=(this->operator%(rhs));
	return *this;
}

TripleLong& TripleLong::operator=(const TripleLong& rhs)
{
	SetVal(rhs.val);
	return *this;
}

TripleLong TripleLong::operator+(TripleLong& rhs)
{
	int r_size = 0, v_size = 0, ov_size = 0;

	v_size = val.size();
	ov_size = rhs.val.size();
	r_size = min(v_size, ov_size) + 1;

	int i = 0, sum = 0, ten = 0, miss = max(v_size, ov_size) - (r_size - 1);
	string result = "", add = "";
	result.resize(r_size + miss, '0');

	for (i = 0; i < miss; i++)
		add += "0";

	if (v_size > ov_size)
		rhs.val = add + rhs.val;
	else
		val = add + val;

	for (i = max(v_size, ov_size) - 1; i >= 0; --i)
	{
		sum = (val.c_str()[i] - '0') + (rhs.val.c_str()[i] - '0') + ten;
		ten = sum / 10;
		sum = sum % 10;
		if (sum != 0)
			result[i + 1] = sum + '0';
	}
	if (ten != 0)
		result[0] = ten + '0';

	for (i = 0; result[i] == '0' && i < result.size() - 1; i++);

	return TripleLong(result.c_str() + i);
}

TripleLong TripleLong::operator-(TripleLong& rhs)
{
	return TripleLong();
}

TripleLong TripleLong::operator*(TripleLong& rhs)
{
	int r_size = 0, v_size = 0, ov_size = 0;

	v_size = val.size();
	ov_size = rhs.val.size();
	r_size = min(v_size, ov_size) + 1;

	int mul = 0, ten = 0, miss = max(v_size, ov_size) - (r_size - 1);
	string add = "";

	for (int i = 0; i < miss; i++)
		add += "0";

	if (v_size > ov_size)
		rhs.val = add + rhs.val;
	else
		val = add + val;

	int max_size = max(v_size, ov_size);
	vector<TripleLong> temp(max_size);
	TripleLong result("0");

	int l, u;
	for (l = max_size - 1; l >= 0; l--)
	{
		for (int k = 0; k < abs(l - (max_size - 1)); k++)
			temp[l].SetVal(temp[l].val + "0");
		for (u = max_size - 1; u >= 0; u--)
		{
			mul = (val[u] - '0') * (rhs.val[l] - '0') + ten;
			if (mul >= 10)
			{
				ten = mul / 10;
				mul %= 10;
			}
			else
				ten = 0;
			temp[l].SetVal(to_string(mul) + temp[l].val);
		}

		temp[l].SetVal(to_string(ten) + temp[l].val);
		ten = 0;
		result += temp[l];
	}

	return result;
}

TripleLong TripleLong::operator/(TripleLong& rhs)
{
	return TripleLong();
}

TripleLong TripleLong::operator%(TripleLong& rhs)
{
	return TripleLong();
}
