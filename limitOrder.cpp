#include<bits/stdc++.h>

#define ld  long double
#define ll long long

using namespace std;

/*-----------------------------------------------------------------------------------------------------------------
  #1 Function totalQuantity() is for both ASK and BID data to calculate the total quantity of orders individaually.
-------------------------------------------------------------------------------------------------------------------*/

//To check and return the sum of the order quantity.

ld totalQuantity(ld Q[], int limit)
{
  ld total = 0;

  //This loop will calculate the total quantity of the order.

  for(int i = 0; i < limit; ++i)
  {
    total += Q[i];
  }

  //Returning the total number of orders to the function.

  return total;
}

/*---------------------------------------------------------------------------------------
  #2 Function calculateOrder() is to calculate the total value the orders and difference.
-----------------------------------------------------------------------------------------*/

//To calculate the total value and difference between ASK and BID orders.

void calculateOrder(ld AQ[], ld AP[], ld BQ[], ld BP[], int Alimit, int Blimit)
{
  ld totalA = 0, totalB = 0;

  //Calculating total value of ASK orders.

  for(int i = 0; i < Alimit; ++i)
    totalA += AQ[i] * AP[i];

  //Calculating total value of BID orders.

  for(int i = 0; i < Alimit; ++i)
    totalB += BQ[i] * BP[i];

  cout << "Total ASK Value: " << totalA << "\nTotal BID Value: " << totalB << "\n";
  cout << "Difference: " << abs(totalA - totalB);
}

/*---------------------------------------------------------------------------------
  #3 Function printChart() is to print the price and quantity chart of ASK and BID.
-----------------------------------------------------------------------------------*/

void printChart(ld AQ[], ld AP[], ld BQ[], ld BP[], int Alimit, int Blimit)
{
  cout << left << setw(15) << setfill(' ') << "ASK Price" << setw(15) << setfill(' ') << "ASK Quantity";
  cout << "\n";
  for(int i = 0; i < Alimit; ++i)
    cout << left << setw(15) << setfill(' ') << AP[i] << setw(15) << setfill(' ') << AQ[i] << "\n";

  cout << "------------------------------------------------\n";
  cout << left << setw(15) << setfill(' ') << "BID Price" << setw(15) << setfill(' ') << "BID Quantity";
  cout << "\n";
  for(int i = 0; i < Blimit; ++i)
    cout << left << setw(15) << setfill(' ') << BP[i] << setw(15) << setfill(' ') << BQ[i] << "\n";
}

/*------------------------------------------
  #4 Function is the main() driver function.
--------------------------------------------*/

int main()
{
  //Asking for the maximum supply. Because, crossing supply limit by the orders is illegal.

  ld supply;
  cout << "Put the maximum supply of your stock: ";
  cin >> supply;
  cout << "------------------------------------------------\n------------------------------------------------\n";

  //Assigning ASK and BID limits for the trade and will ask the user to put the order limit.

  int Alimit = 0, Blimit = 0;

  //Asking for the ASK order limit. And later we'll input the order details.

  cout << "Put the ASK order limit: ";
  cin >> Alimit;
  cout << "------------------------------------------------\n";
  ld AQ[Alimit]; ld AP[Alimit];

  for(int i = 0; i < Alimit; ++i)
  {
    cout << "ASK Quantity(" << i + 1 << "): ";
    cin >> AQ[i];
    cout << "ASK Price(" << i + 1 << "): ";
    cin >> AP[i];
  } cout << "------------------------------------------------\n";

  //Asking for the BID order limit. And later we'll input the order details.

  cout << "Put the BID order limit: ";
  cin >> Blimit;
  cout << "------------------------------------------------\n";
  ld BQ[Blimit]; ld BP[Blimit];

  for(int i = 0; i < Blimit; ++i)
  {
    cout << "BID Quantity(" << i + 1 << "): ";
    cin >> BQ[i];
    cout << "BID Price(" << i + 1 << "): ";
    cin >> BP[i];
  } cout << "------------------------------------------------\n";

  //Checking if the ASK/BID order limits crossing the  maximum supply or not.
  //If order limits are less than or equal to total supply.

  if(totalQuantity(AQ, Alimit) <= supply && totalQuantity(BQ, Blimit) <= supply)
    calculateOrder(AQ, AP, BQ, BP, Alimit, Blimit);
  else
  {
    cout << "INVALID ORDER LIMITS!\n";
    cout << "Your ASK order is " << abs(Alimit - supply) << " more/less than supply limit.\n";
    cout << "Your BID order is " << abs(Blimit - supply) << " more/less than supply limit.\n";
  }

  //Here the function printChart() is called to print all the orders available for ASK/BID.

  cout << "\n------------------------------------------------\n";
  printChart(AQ, AP, BQ, BP, Alimit, Blimit);
  cout << "------------------------------------------------\n";
  ld OQ = 0, OP = 0;
  cout << "Enter your limit order quantity: ";  cin >> OQ;
  cout << "Enter your limit order price: "; cin >> OP;

  cout << "------------------------------------------------\n";
  cout << left << setw(15) << setfill(' ') << "BID Quantity" << setw(15) << setfill(' ') << "BID Price";
  cout << "\n";

  for(int i = 0; i < Blimit; ++i)
  {
    if(OQ == BQ[i] && OP == BP[i])
    {
      cout << "[" << OQ << " orders are placed for " << OP << "].\n";
      continue;
    }
    else
    {
      cout << left << setw(15) << setfill(' ') << BQ[i] << setw(15) << setfill(' ') << BP[i] << "\n";
      continue;
    }
  }

  return 0;
}
