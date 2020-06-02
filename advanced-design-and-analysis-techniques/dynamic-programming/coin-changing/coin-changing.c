#include <stdio.h>
#include <stdlib.h>

int coins_n, amount;

int *coins;
int *dp;
int *coin_used;

int min(int a, int b) { return a <= b ? a : b; }

void optimally_exchange(int amount) {
  int exchange_amount, i;
  for (exchange_amount = 1; exchange_amount <= amount; exchange_amount++)
    dp[exchange_amount] = 1 << 16;

  dp[0] = 0;
  for (exchange_amount = 1; exchange_amount <= amount; exchange_amount++)
    for (i = 0; i < coins_n; i++)
      if (coins[i] <= exchange_amount)
        if (1 + dp[exchange_amount - coins[i]] < dp[exchange_amount])
          dp[exchange_amount] = 1 + dp[exchange_amount - coins[i]],
          coin_used[exchange_amount] = coins[i];
}

void print_exchange(int n) {
  printf("%d", coin_used[n]);
  if (n - coin_used[n])
    printf(" + "), print_exchange(n - coin_used[n]);
}

int main() {
  int i;
  scanf("%d %d", &coins_n, &amount);

  coins = (int *)malloc(sizeof(int) * (coins_n));
  dp = (int *)malloc(sizeof(int) * (amount + 1));
  coin_used = (int *)malloc(sizeof(int) * (amount + 1));

  for (i = 0; i < coins_n; i++)
    scanf("%d", &coins[i]);

  for (i = 0; i < coins_n; i++)
    printf("%d\n", coins[i]);

  optimally_exchange(amount);

  printf("optimal exchange uses %d coins\n", dp[amount]);
  printf("optimal change is %d = ", amount);
  print_exchange(amount);

  free(coins);
  free(dp);
  free(coin_used);
  return 0;
}