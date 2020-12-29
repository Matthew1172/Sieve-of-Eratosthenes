'''
@author Matthew Pecko
An algorithm to perform a seive of Eratosthenes. Each number is represented as a Number object.
'''
import math

# Simple data structure to store the representaion and value of a number
class MyNumber:
    number = None
    value = None
    def __init__(self, number, value):
        self.number = number
        self.value = value

    def __str__(self):
        return "{} \t {} ".format(self.number, self.value)

    def getNumber(self):
        return self.number

    def getValue(self):
        return self.value

    def setValue(self, value):
        self.value = value

    def printFormatted(self):
        print("My number is: ", self.number, " | My value is: ", self.value)



def main():
    '''
    Overhead loop
    Start with the first prime and go to MAX + 1 to make MAX inclusive, storing a True value for every number.
    '''
    MIN = 2
    MAX = 2**16

    A = []

    for n in range(MIN, MAX+1):
        A.append(MyNumber(n, True))


    # Do not exceed the sqrt of the size of list because ??? wikipedia pseudocode told me so..
    size = int(math.sqrt(len(A)))

    i = 0
    while A[i].getNumber() <= size:
        if A[i].getValue() is True:
            # Start at the prime number squared for optimization, and keep track of a counter to include all multiples of the prime
            j = A[i].getNumber()**2
            counter = 0

            # go to length of the list plus 1 to insure the last number is tested and not skipped
            while j <= len(A) + 1:

                # Becuase the index of the list starts with 0 and not 2, I have to move the pointer two indicies before j for alignment.
                A[j-2].setValue(False)

                # Increment j by a multiple of the prime
                counter += 1
                j = A[i].getNumber()**2 + counter * A[i].getNumber()
        i += 1

    for n in A:
        if n.getValue():
            print(n)

if __name__ == "__main__":
    main()
