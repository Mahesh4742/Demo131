#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      Mahesh
#
# Created:     24-05-2023
# Copyright:   (c) Mahesh 2023
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def linear_search(a, key):
    n = len(a)
    for i in range(n):
        if a[i] == key:
            return i
    return -1

a = [5,8,4,6,9,2]
print("The array elements are:", a)

k = int(input("Enter the key element to search: "))


index = linear_search(a, k)

if index == -1:
    print("Search Unsuccessful")
else:
    print("Search Successful, key found at location:", index + 1)


