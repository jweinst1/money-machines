#include <stdio.h>
#include <stdlib.h>

/**
 * Buyer cellular automata example
 * Written by Joshua Weinstein, all rights reserved.
 */

typedef struct
{
	float cash;
	float supply;
} buyer_t;


float buyer_price(const buyer_t* b)
{
	return b->cash / b->supply;
}

float buyer_wanted_supply(const buyer_t* buying, const buyer_t* selling)
{
	return(buying->cash / buying->supply) / (selling->cash / selling->supply);
}

void buyer_transaction(buyer_t* buying, buyer_t* selling)
{
	float change_amount = buyer_wanted_supply(buying, selling);
	float cash_amount = change_amount * buyer_price(selling);
	buying->supply += change_amount;
	buying->cash -= cash_amount;
	selling->supply -= change_amount;
	selling->cash += cash_amount;
}

void buyer_trade(buyer_t* cells, unsigned size)
{
	unsigned i;
	for(i = 0; i < size; i++) {
		unsigned j;
		for(j = i + 1; j < size; j++) {
			buyer_transaction(cells + i, cells + j);
		}
	}
}

void buyer_print(buyer_t* cells, unsigned size)
{
	unsigned i = 0;
	puts("------------------------");
	while(i < size) {
		printf("(cash:%f, supply:%f), ", cells[i].cash, cells[i].supply);
		++i;
	}
	puts("\n------------------------");
}

static buyer_t CELLS[] = {
	{25.0, 10.0},
	{25.0, 10.0},
	{25.0, 10.0},
	{25.0, 10.0},
	{25.0, 10.0}
};


int main(int argc, char const *argv[])
{
	int t;
	int max_times;
	size_t cell_count = (sizeof(CELLS)/ sizeof(buyer_t));
	if(argc != 2) {
		fprintf(stderr, "%s\n", "Expected only 1 argument");
		exit(1);
	}
	sscanf(argv[1], "%d", &max_times);
	puts("Generation 0:");
	buyer_print(CELLS, cell_count);
	for(t = 1; t <= max_times; t++) {
		printf("Generation: %d\n", t);
		buyer_trade(CELLS, cell_count);
		buyer_print(CELLS, cell_count);
	}
	return 0;
}
