#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      Mahesh
#
# Created:     06-06-2023
# Copyright:   (c) Mahesh 2023
# Licence:     <your licence>
#-------------------------------------------------------------------------------

import time
start = time.time()
stack = []
stack.append('a')
stack.append('b')
stack.append('c')
print('Initial stack')
print(stack)
print('\nElements popped from stack:')
print(stack.pop())
print(stack.pop())
print(stack.pop())
print('\nStack after elements are popped:')
print(stack)
end = time.time()
print(f"Runtime of the program is {end - start}")