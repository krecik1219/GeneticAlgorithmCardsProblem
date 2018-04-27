#include "CCardBits.h"


CCardBits::CCardBits(int i_size) : i_size(i_size), v_bits(i_size)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::bernoulli_distribution d(0.5);

	for (int ii = 0; ii < i_size; ++ii)
		v_bits[ii] = d(gen);
} // CCardBits(int i_size) : i_size(i_size) 

void CCardBits::vCrossOver(CCardBits & c_first, CCardBits & c_other, int i_cross_posi)
{
	vector<bool> v_temp(i_cross_posi);

	for (int ii = 0; ii < i_cross_posi; ++ii)
		v_temp[ii] = c_first.v_bits[ii];


	int i_posi = c_other.v_bits.size() - i_cross_posi;
	for (int ii = 0; ii < i_cross_posi; ++ii)
	{
		c_first.v_bits[ii] = c_other.v_bits[i_posi];
		c_other.v_bits[i_posi] = v_temp[ii];
		++i_posi;
	} // for (int ii = 0; ii < i_cross_posi; ++ii)
} // void cCrossOver(CCardBits & c_first, CCardBits & c_other, int i_cross_posi)

int CCardBits::iTotalSum() const
{
	int i_total_sum = 0;
	for (int ii = 0; ii < i_size; ++ii)
	{
		if (!v_bits[ii])
			i_total_sum += ii + 1;
	} // for (int ii = 0; ii < i_size; ++ii)

	return i_total_sum;
} // int iTotalSum

int CCardBits::iTotalProduct() const
{
	int i_total_product = 0;
	for (int ii = 0; ii < i_size; ++ii)
	{
		if (v_bits[ii])
		{
			if (i_total_product == 0)
				++i_total_product;

			i_total_product *= ii + 1;
		} // if (v_bits[ii] == true)
	} // for (int ii = 0; ii < i_size; ++ii)

	return i_total_product;
} // int iTotalProduct()

std::ostream & operator << (std::ostream & out, const CCardBits & cBits)
{
	out << "{ ";
	for (int ii = 0; ii < cBits.i_size; ++ii)
	{
		if (!cBits.v_bits[ii])
			out << "0 ";
		else
			out << "1 ";
	}
	out << "} Size: " << cBits.i_size << " Sum: " << cBits.iTotalSum() << " Product: " << cBits.iTotalProduct() << std::endl;

	return out;
}