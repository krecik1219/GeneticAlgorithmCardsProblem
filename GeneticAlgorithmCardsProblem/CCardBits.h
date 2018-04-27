#pragma once

#include <vector>
#include <random>
using std::vector;

class CCardBits
{
	friend std::ostream & operator << (std::ostream & out, const CCardBits & cBits);
public:
	CCardBits(int iSize);

	static void vCrossOver(CCardBits & cFirst, CCardBits & cOther);  // implement random point and crossover

	long double dGetDistance();
	void vSetDistance(long double dDistance);
	bool bWasChanged();
	void vSetChanged(bool bChanged);
	void vMutation();
	//void vMutation2();  // another one, just in case, random bits string xor
	long long iTotalSum() const;

	long long iTotalProduct() const;

private:
	int i_size;
	long double d_distance;
	bool b_was_changed;
	vector<bool> v_bits;
}; // class CCardBits

