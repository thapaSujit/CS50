class cordinate(object):
    def __init__(self, latitude, longitude):
        self.latitude = latitude
        self.longitude = longitude

    def return_coord(self):
        return self.latitude, self.longitude

class location(object):
    locations = []
    cod_id = 0

    def __init__(self, latitude, longitude, name = ""):
        self.name = name
        self.cordinate = cordinate(latitude, longitude)
        location.locations.append(self)
        self.id = location.cod_id + 1 
        location.cod_id += 1
        #location.cod_id +=1
        #self.id = location.cod_id


c = cordinate(2, 3)
print (c.latitude)
print (c.longitude)
print(c.return_coord())

l = location(2, 3, "Nepal")
print(l.name)
#print(l.return_location())
print(l.id)

l = location(2, 3, "Kathmandu")
print(l.name)
#print(l.return_location())
print(l.id)

l = location(2, 3, "Ramkot")
print(l.name)
#print(l.return_location())
print(l.id)

l = location(2, 3, "Ramkot")
print(l.name)
#print(l.return_location())
print(l.id)
l = location(2, 3, "Gyaneshwor")
print(l.name)
#print(l.return_location())
print(l.id)
l = location(2, 3, "Baneshwor")
print(l.name)
#print(l.return_location())
print(l.id)
l = location(2, 3, "Nagarko")
print(l.name)
#print(l.return_location())
print(l.id)

#print(loctions)