"""------------------------------------------------------------------------
    #3 totalQuantity() function calculates the total quantity of orders.
------------------------------------------------------------------------"""

def totalQuantity(TEMP):
    total = float(0)
    for i in range(len(TEMP)):
        total = total + TEMP[i];

    return total

"""------------------------------------------------------------------------
    #1 printChart() function is to display the orders in a visual chart.
------------------------------------------------------------------------"""

def printChart(AQ, AP, BQ, BP):
    print("------------------------------------------------")
    print('ASK Price', "{:>15}".format('ASK Quantity'))
    for i in range(len(AQ)):
        print(AP[i], "{:>15}".format(AQ[i]))

    print("------------------------------------------------")
    print('BID Price', "{:>15}".format('BID Quantity'))
    for i in range(len(AQ)):
        print(BP[i], "{:>15}".format(BQ[i]))


"""---------------------------------------------------------------------------------------
    #2 calculateOrder() function is to sum up the order values and find the difference.
---------------------------------------------------------------------------------------"""

def calculateOrder(AQ, AP, BQ, BP):
    totalA, totalB = float(0), float(0)

    for i in range(len(AQ)):
        totalA = totalA + (AQ[i] * AP[i])

    for i in range(len(BQ)):
        totalB = totalB + (BQ[i] * BP[i])

    print("------------------------------------------------")
    print("Total ASK Value: ", totalA)
    print("Total BID Value: ", totalB)
    print("Difference: ", abs(totalA - totalB))

"""-------------------------------------------------------------------------------------------------------------------
    #4 checkOrder() function checks compares the limit order with the market order and place the order if possible.
-------------------------------------------------------------------------------------------------------------------"""

def checkOrder(OQ, OP, BQ, BP):
    print("------------------------------------------------")
    print('BID Price', "{:>15}".format('BID Quantity'))
    for i in range(len(BQ)):
        if(OQ == BQ[i] and OP == BP[i]):
            print('[', OQ, 'orders are placed for', OP, ']')
            continue
        else:
            print(BP[i], "{:>15}".format(BQ[i]))
            continue

"""-----------------------
    #5 Driver function.
-----------------------"""

print("Put the maximum supply of your stock: ", end = '')
supply = float(input())

print("------------------------------------------------")
print("Put the ASK oder limit: ", end = '')
Alimit = int(input())
print("------------------------------------------------")

AQ = []
AP = []

for i in range(Alimit):
    print("ASK Quantity: ", end = '')
    AQ.append(float(input()))
    print("ASK Price: ", end = '')
    AP.append(float(input()))

print("------------------------------------------------")
print("Put the BID oder limit: ", end = '')
Blimit = int(input())
print("------------------------------------------------")

BQ = []
BP = []

for i in range(Blimit):
    print("BID Quantity: ", end = '')
    BQ.append(float(input()))
    print("BID Price: ", end = '')
    BP.append(float(input()))

printChart(AQ, AP, BQ, BP)

if(totalQuantity(AQ) <= supply and totalQuantity(BQ) <= supply):
    calculateOrder(AQ, AP, BQ, BP)

else:
    print("------------------------------------------------")
    print('INVALID ORDER LIMITS!')

print("------------------------------------------------")
print("Enter limit order quantity: ", end = '')
OQ = float(input())
print("Enter limit order price: ", end = '')
OP = float(input())

checkOrder(OQ, OP, BQ, BP)
