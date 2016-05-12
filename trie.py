class Node:
	def __init__(self, c=None):
		self.next = {}
		self.word = False
		self.letter = c

class Trie:
	def __init__(self):
		self.head = Node()

	def insert(self, string):
		p = self.head
		for c in string:
			if not p.next.has_key(c):
				p.next[c] = Node(c)
			p = p.next[c]
		p.word = True

	def contains(self, string):
		p = self.head
		for c in string:
			if not p.next.has_key(c):
				return False
			p = p.next[c]
		if p.word:
			return True
		return False

t = Trie()
print "Inserting hello"
t.insert("hello")
print "Contains hello? {}".format(t.contains("hello"))
print "Contains world? {}".format(t.contains("world"))

print "\nInserting world"
t.insert("world")
print "Contains world? {}".format(t.contains("world"))

print "Contains hell? {}".format(t.contains("hell"))
print "\nInserting hell"
t.insert("hell")
print "Contains hell? {}".format(t.contains("hell"))
