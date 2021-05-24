class item(object):
    def __init__(self, name, qty, ppp):
        self.name = name
        self.qty = qty
        self.ppp = ppp

    def __add__(self, other):
        if isinstance(other, int):  #-->if other is of data type int then it is added directly
            return self.ppp * self.qty + other
        else:
            return self.ppp * self.qty + other.ppp * other.qty


i1 = item("Apple", 1, 10)
i2 = item("Banana", 2, 10)
print(f"Overall: {i1 + i2}")

i1 = item("Apple", 10, 10)
print(f"Overall: {i1 + 100}")