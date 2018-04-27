#pragma once

#include <vector>
#include <random>
using std::vector;

class CCardBits
{
	friend std::ostream & operator << (std::ostream & out, const CCardBits & cBits);
public:
	CCardBits(int iSize);

	static void vCrossOver(CCardBits & cFirst, CCardBits & cOther, int iCrossPosi);

	double dGetDistance();
	void vSetDistance(double dDistance);
	bool bWasChanged();
	void vSetChanged(bool bChanged);
	// TODO implement mutation
	int iTotalSum() const;

	int iTotalProduct() const;

private:
	int i_size;
	double d_distance;
	bool b_was_changed;
	vector<bool> v_bits;
}; // class CCardBits

