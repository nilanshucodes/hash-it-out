# Credit Card Validator (Luhn Algorithm)

This is a simple C++ program that checks the validity of a credit card number using the **Luhn algorithm**.

## How It Works
1. The program takes a credit card number as input.
2. It separates the digits into **odd** and **even** positions (from right to left).
3. The sum of digits from odd positions is calculated.
4. The digits from even positions are doubled, and their individual digits are summed.
5. The total sum is computed and checked if it's a multiple of 10.
6. If the result is divisible by 10, the card number is **valid**; otherwise, it is **invalid**.

## Code Explanation
- `getdigits(int number)`: Extracts and sums the digits of a given number.
- `sumodddigits(string cardnumber)`: Sums the digits at odd positions.
- `sumevendigits(string cardnumber)`: Doubles the even-positioned digits and sums their individual digits.
- `main()`: Handles input and determines if the card is valid based on the sum.

EXAMPLE:-
Enter a credit card number: 378282246310005
378282246310005 is valid
