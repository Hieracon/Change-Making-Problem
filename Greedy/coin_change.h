#ifndef COIN_CHANGE_H_INCLUDED
#define COIN_CHANGE_H_INCLUDED

int read_no_coin_types();
void read_denominations(int *denominations, int no_coin_types);
void display_results(int *count_coin_types, int *denominations, int no_coin_types);

#endif // COIN_CHANGE_H_INCLUDED
