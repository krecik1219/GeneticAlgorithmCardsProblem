#pragma once
#include <vector>
#include <random>
#include "CCardBits.h"

class CCardBits;

static const int i_ITERATIONS_NUM = 100;  // important, pg parameter
static const int i_POPULATION_SIZE = 100;  // important, pg parameter
static const double d_CROSSOVER_PROB = 0.55;
static const double d_MUTATION_PROB = 0.3;

class CPGAlg
{
public:
	CPGAlg(int iProblemSize, int iExpectedSum, int iExpectedProduct);
	~CPGAlg();
	
	CCardBits cRunIteration();

private:

	void v_initialize();
	void v_evaluate_all();
	void v_evaluate_single(CCardBits * pcCard);
	void v_selection();
	void v_parents_crossover();
	void v_mutation();
	void v_delete_population();

	std::vector<CCardBits*> v_population;
	std::vector<CCardBits*> v_parents;
	CCardBits * pc_best_cards_set;

	int i_problem_size;
	int i_expected_sum;
	int i_expected_product;
	double d_current_min_distance;

	std::random_device c_rd;
	std::mt19937 c_gen;
	std::uniform_real_distribution<> c_rnd_double_gen;
};

