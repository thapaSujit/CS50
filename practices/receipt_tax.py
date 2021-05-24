class item():
    def __init__(self, name, ppp, quantity):
        self.name = name
        self.ppp = ppp
        self.quantity = quantity

    def price(self):
        return self.ppp * self.quantity

class fooditem(item):
    def __init__(self, name, ppp, quantity):
        super().__init__(name, ppp, quantity)

    def price(self):
        return super().price() * 1.07

class nonfooditem(item):
    def __init__(self, name, ppp, quantity):
        super().__init__(name, ppp, quantity)

    def price(self):
        return super().price() * 1.16

class specialitem(item):
    def __init__(self, name, ppp, quantity):
        return super().__init__(name, ppp, quantity)

    def price(self):
        if self.quantity % 2 != 0:
            self.quantity += 1
            return self.ppp * (self.quantity/2) * 1.16

        else:
            return self.ppp * self.quantity * 1.16

receipt = []
receipt.append(fooditem("Banana", 1, 2))
receipt.append(fooditem("Tomato", 1, 1))
receipt.append(fooditem("Pasta", 100, 1))
receipt.append(nonfooditem("Soap", 1, 1))
receipt.append(specialitem("Book", 10, 4))

for elem in receipt:
    print(elem.price())
    #print(elem.name())
    #print(elem.ppp())
    #print(elem.quantity())