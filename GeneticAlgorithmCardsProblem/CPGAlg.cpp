#include "CPGAlg.h"



CPGAlg::CPGAlg(int iProblemSize, long long iExpectedSum, long long iExpectedProduct) :
pc_best_cards_set(nullptr), i_problem_size(iProblemSize), i_expected_sum(iExpectedSum),
i_expected_product(iExpectedProduct), d_current_min_distance(INFINITY),
c_gen(c_rd()), c_rnd_double_gen(0, 1)
{
	v_initialize();
}

CPGAlg::~CPGAlg()
{
	v_delete_population();
}

CCardBits CPGAlg::cRunIteration()
{
	v_selection();
	v_parents_crossover();
	v_mutation();
	v_evaluate_all();

	return *pc_best_cards_set;
}

void CPGAlg::v_initialize()
{
	for (int i = 0; i < i_POPULATION_SIZE; ++i)
	{
		v_population.push_back(new CCardBits(i_problem_size));
	}
	v_evaluate_all();
}

void CPGAlg::v_evaluate_all()
{
	int i_pop_size = v_population.size();
	for(int i=0; i<i_pop_size; ++i)
	{
		CCardBits * pc_card = v_population[i];
		if(pc_card->bWasChanged())
		{
			v_evaluate_single(pc_card);
			if(pc_card->dGetDistance() < d_current_min_distance)
			{
				d_current_min_distance = pc_card->dGetDistance();
				delete pc_best_cards_set;
				pc_best_cards_set = new CCardBits(*pc_card);
			}
		}
	}
}

void CPGAlg::v_evaluate_single(CCardBits * pcCard)
{
	long double i_sum = pcCard->iTotalSum();
	long double i_product = pcCard->iTotalProduct();
	
	long double i_distance = (i_expected_sum - i_sum) * (i_expected_sum - i_sum) + (i_expected_product - i_product) * (i_expected_product - i_product);

	pcCard->vSetDistance(i_distance);
}

void CPGAlg::v_selection()
{
	int i_selected_index;
	int i_population_size = v_population.size();
	std::random_device c_random_device;
	std::mt19937 c_generator(c_random_device());
	std::uniform_int_distribution<> c_rnd_gen(0, i_population_size - 1);
	for(int i=0; i<i_population_size; ++i)
	{
		i_selected_index = c_rnd_gen(c_generator);
		CCardBits * pc_selected_1 = v_population[i_selected_index];
		i_selected_index = c_rnd_gen(c_generator);
		CCardBits * pc_selected_2 = v_population[i_selected_index];
		if (pc_selected_1->dGetDistance() <= pc_selected_2->dGetDistance())
		{
			v_parents.push_back(new CCardBits(*pc_selected_1));
		}
		else
		{
			v_parents.push_back(new CCardBits(*pc_selected_2));
		}

	}
}

void CPGAlg::v_parents_crossover()
{
	v_delete_population();
	int i_half_population = v_parents.size() / 2;
	double d_rnd;
	for (int i = 0; i < i_half_population; ++i)
	{
		CCardBits * pc_parent_1 = v_parents[i];
		CCardBits * pc_parent_2 = v_parents[i_POPULATION_SIZE - 1 - i];
		d_rnd = c_rnd_double_gen(c_gen);
		if(d_rnd >= 1.0 - d_CROSSOVER_PROB)
		{
			CCardBits::vCrossOver(*pc_parent_1, *pc_parent_2);
			pc_parent_1->vSetChanged(true);
			pc_parent_2->vSetChanged(true);
		}
		v_population.push_back(pc_parent_1);
		v_population.push_back(pc_parent_2);
	}
	v_parents.clear();
}

void CPGAlg::v_mutation()
{
	int i_population_size = v_population.size();
	double d_rnd;
	for(int i = 0; i<i_population_size; ++i)
	{
		d_rnd = c_rnd_double_gen(c_gen);
		if (d_rnd >= 1.0 - d_MUTATION_PROB)
		{
			v_population[i]->vMutation();
			v_population[i]->vSetChanged(true);
		}
		else
			v_population[i]->vSetChanged(v_population[i]->bWasChanged() | false);
	}
}

void CPGAlg::v_delete_population()
{
	int i_population_size = v_population.size();
	for(int i=0; i<i_population_size; ++i)
	{
		delete v_population[i];
	}
	v_population.clear();
	int x = 5;
}


