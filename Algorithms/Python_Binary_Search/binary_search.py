def binarysearch(element, l):
	if len(l) == 0:
		return false

	mid = len(l) / 2

	if element == l[mid]:
		return True
	elif element < l[mid]:
		return bs_helper(0, mid-1, element, l)
	else:
		return bs_helper(mid+1, len(l)-1, element, l)


def bs_helper(left, right, element, l):
	mid = (left+right) / 2

	if element == l[mid]:
		return True
	elif not (left < right):
		return False;
	elif element < l[mid]:
		return bs_helper(left, mid-1, element, l)
	else:
		return bs_helper(mid+1, right, element, l)

numbers = [5,3,18,-4,1,2,6,-9,-3,12,4,9]
numbers.sort()
print numbers
print "-3?",binarysearch(-3,numbers)
print "10?",binarysearch(10,numbers)
print "22?",binarysearch(22,numbers)
print "18?",binarysearch(18,numbers)
print "6?",binarysearch(6,numbers)