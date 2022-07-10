# Programming Drill 1.1.1 Write a program that accepts two complex numbers and
# outputs their sum and their product.
import cmath

complex_number1 = complex(input("First complex number with j instead of i:"))
complex_number2 = complex(input("Second complex number with j instead of i:"))

complex_sum = complex_number1 + complex_number2
complex_product = complex_number1 * complex_number2
print("Sum of complex numbers: " + str(complex_sum))
print("Product of complex numbers: " + str(complex_product))
