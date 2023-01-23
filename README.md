# binaryExpressionTree
A C++ program which accepts infix arithmetic expressions involving single-digit operands and the operators + (addition), - (subtraction), * (multiplication), and / (division) and outputs equivalent prefix expressions.
All input expressions are valid, fully paranthesized expressions with a single space before and after all operators. The input file will be infix.dat. For this example, infix.dat has the following operations within it to be converted to the prefix:  
(3 + 4)  
((5 + 4) * 8)  
((0 * (1 + 2)) / (3 - (4  +  5))  *  (6 / 7 / (8 * 9)))  
(1 - 3 * (4 + 5 * 6) + 7)
Sample output of first two lines:
+ 3 4  
* + 5 4 8  
