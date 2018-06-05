#include <stdio.h>
#include <stdlib.h>
#include "coin_change.h"

int main()
{
    int *denominations;
    int *count_coin_types;
    int no_coin_types;
    int iterator;
    int no_coins;

        no_coin_types = read_no_coin_types();
        denominations = (int*)calloc(no_coin_types,sizeof(int));
        count_coin_types = (int*)calloc(no_coin_types,sizeof(int));

        read_denominations(denominations, no_coin_types);

        iterator = no_coin_types - 1;
        no_coins = 0;

        display_results(denominations, iterator, no_coins, count_coin_types, no_coin_types);

        free(count_coin_types);
        free(denominations);

    return 0;
}
