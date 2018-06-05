#ifndef COIN_CHANGE_H_INCLUDED
#define COIN_CHANGE_H_INCLUDED

int read_no_coin_types();
void read_denominations(int *denominations, int no_coin_types);
void display_results(int *denominations, int iterator, int no_coins, int *count_coint_types, int no_coin_types);
int determinate_no_coins(int amount, int *denomintaions, int iterator, int no_coins, int *count_coint_types);

#endif // COIN_CHANGE_H_INCLUDED
