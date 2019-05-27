#include <stdio.h>
#include <stdlib.h>

#define CELL_COUNT 21
static int CELLS[CELL_COUNT] = { 1, 0, 0, 1, 1, 0, 0, 0, 1 };

typedef struct {
	int match1;
	int match2;
	int match3;
	int next;
} rule_t;

static rule_t RULES[] = {
	{1, 1, 1, 0},
	{0, 1, 0, 1},
	{1, 0, 1, 0},
	{0, 0, 0, 1},
	{1, 0, 0, 0}
};

void cells_transition(int* next_gen, const int* cells)
{
	unsigned i;
	for(i = 0; i < CELL_COUNT - 2; i++)
	{
		unsigned j;
		int found = 0;
		for(j = 0; j < (sizeof(RULES)/sizeof(rule_t)); j++)
		{
			if(RULES[j].match1 == cells[i] &&
				RULES[j].match2 == cells[i + 1] &&
				RULES[j].match3 == cells[i + 2]
				)
			{
				next_gen[i] = RULES[j].next;
				found = 1;
			}
		}
		if(!found)
			next_gen[i] = 1;
	}
}

void print_cells(const int* cells)
{
	unsigned i;
	for(i = 0 ; i < CELL_COUNT - 1;i++)
	{
		printf("%d ", cells[i]);
	}
	putc('\n', stdout);
}

int main(int argc, char const *argv[])
{
	int gen2[CELL_COUNT];
	print_cells(CELLS);
	cells_transition(gen2, CELLS);
	print_cells(gen2);
	cells_transition(CELLS, gen2);
	print_cells(CELLS);
	cells_transition(gen2, CELLS);
	print_cells(gen2);
	cells_transition(CELLS, gen2);
	print_cells(CELLS);
	cells_transition(gen2, CELLS);
	print_cells(gen2);
	cells_transition(CELLS, gen2);
	print_cells(CELLS);
	cells_transition(gen2, CELLS);
	print_cells(gen2);
	cells_transition(CELLS, gen2);
	print_cells(CELLS);
	return 0;
}
