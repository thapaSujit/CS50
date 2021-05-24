from sys import argv
import cs50
# check command line rguements
if len(argv) != 2:
    print("Error!! Unable to execute the program.")
    exit()

# querry database for all students in house
# students should be sorted alphabetically by last name then first name
db = cs50.SQL("sqlite:///students.db")
rows = db.execute("SELECT * FROM students WHERE house = (?) ORDER BY last, first", argv[1])

# print out each students full name and birth year
for row in rows:
    if row['middle'] == None:
        print(f"{row['first']} {row['last']}, born {row['birth']}")
    else:
        print(f"{row['first']} {row['middle']} {row['last']}, born {row['birth']}")
