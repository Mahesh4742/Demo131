#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      Mahesh
#
# Created:     28-05-2023
# Copyright:   (c) Mahesh 2023
# Licence:     <your licence>
#-------------------------------------------------------------------------------

import time

start = time.time()

class Node:
    def __init__(self, my_data):
        self.data = my_data
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.head = None

    def add_data(self, my_data):
        ptr_1 = Node(my_data)
        temp = self.head
        ptr_1.next = self.head

        if self.head is not None:
            while temp.next != self.head:
                temp = temp.next
            temp.next = ptr_1
        else:
            ptr_1.next = ptr_1
            self.head = ptr_1

    def print_it(self):
        temp = self.head
        if self.head is not None:
            while True:
                print(temp.data)
                temp = temp.next
                if temp == self.head:
                    break

my_list = CircularLinkedList()
print("Elements are added to the list")
my_list.add_data(56)
my_list.add_data(78)
my_list.add_data(12)


print("The data is:")
my_list.print_it()

end = time.time()
print(f"Runtime of the program is {end - start}")
