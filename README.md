# Limit Order Book(Trading)

>   In trading mainly there're two types of orders market order and limit order.
>
> As their names suggests, market order is traded with the price based on exactly at the situation of the market. This has high risk because in the unpredictable market holder can lose or gain value of the stock but at the same time holder can trade any amount of stocks less than or equal to the supply in any instance of time during market hours.
>
>   Here comes a safer way of trading called limit order, which actually triggers itself at a fixed price and quantity. In the unpredictable market expected price can reach the limit order's preferences but it'll take time, longer than market orders or maybe expected price never match the limit order's preferences. This kind of orders have the problem of uncertainty but less risk.

REFERENCES:
* [5minutefinance](https://www.5minutefinance.org/concepts/the-limit-order-book)
* [Investor.gov](https://www.investor.gov/introduction-investing/investing-basics/how-stock-markets-work/types-orders)
* [Option Trade India](https://www.youtube.com/watch?v=70MsA9vYht8)
* [TD Ameritrade](https://www.youtube.com/watch?v=9lMHnK9eqQw)

In this limit order book problem I've divided the problem into multiple subproblems in which "printChart()" function is printing the Ask and Bid order details which we call from the "main()" function and also provided the required data, "calculateChart()" is the function which is calculating the total value of Ask and Bid orders and their differences, on the other hand "totalQuantity()" is simply the summation of the individual type's order quantities which we've used to check if the order quantities exceeding the supply limit or not. "checkOrder()" is the final function which actually processing the limit order's data and checks the availability of the order. If the the order is available then the program will automatically place an order with same requirements as mentioned in the limit order.

Firstly, to understand the full workflow and logic I've used C++ and solved the problem and then implemented the same logic using Python. Uploaded both files in the repository.
