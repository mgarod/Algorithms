from random import randint

i = 0
array = list()
size = 20
while i < size:
	array.append(randint(0,100))
	i += 1

print "Here is the unsorted array of size %d:" % len(array)
print array

# Begin BubbleSort - outer Loop n times
i = 0
while i < len(array):
	j = 0

	# Swap if the two numbers are inverted (value[i] > value[j] when i < j)
	# Each pass, the largest number is placed at the rightmost spot.
	# We ignore the last i items (minus 1 to avoid out of bounds comparison)
	while j < (len(array)-i-1): 
		if array[j] > array[j+1]:
			temp = array[j]
			array[j] = array[j+1]
			array[j+1] = temp
		j += 1

	i += 1
# End BubbleSort

print ""
print "Here is the sorted array of size %d:" % len(array)
print array