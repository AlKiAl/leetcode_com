class Solution {
 public:
  int maxProfit(vector<int>& prices) {
       /*
       profit: Максимальная прибыль, если сейчас у вас нет акции.
       hold: Максимальная прибыль, если сейчас вы держите акцию.
       */
    int profit = 0;
    int hold = -prices.front();

    for (const int price : prices) {
        // порядок строк не важен

        /*
        Выбираем между:
        Ничего не делать (оставить текущую акцию в портфеле: hold).
        Купить акцию сегодня (уменьшаем прибыль на текущую цену: profit - price).
        */
        hold = max(hold, profit - price);


        /*
        Выбираем между:
        Ничего не делать (оставить текущую прибыль: profit).
        Продать акцию сегодня (увеличиваем прибыль на текущую цену: hold + price).
        */
        profit = max(profit, hold + price);      

    }

    return profit;
  }
};
