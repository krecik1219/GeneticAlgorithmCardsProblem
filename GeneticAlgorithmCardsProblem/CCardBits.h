#pragma once

#include <vector>
#include <random>
using std::vector;

class CCardBits
{
	friend std::ostream & operator << (std::ostream & out, const CCardBits & cBits);
public:
	CCardBits(int i_size);

	void vCrossOver(CCardBits & c_first, CCardBits & c_other, int i_cross_posi);

	double dGetDistance();

	int iTotalSum() const;

	int iTotalProduct() const;

private:
	int i_size;
	double d_distance;
	bool b_was_changed;
	vector<bool> v_bits;
}; // class CCardBits

