import cs50
from sys import argv
import csv

# openning of the database to be used after
db = cs50.SQL("sqlite:///students.db")

# check command line rguements
if len(argv) != 2:
    print("Error!! Unable to execute the program.")
    exit()

# open CSV file  given by command line arguments
with open(argv[1], 'r') as import_file:
    
    # --------------HINT-----------
    # use csv.reader or csv.dictreader
    # use split methood on strings to split into words
    # use none for students middle name if they dont have one
    # use db.execute to insert row ino the table
   
    # Create DictReader
    reader = csv.DictReader(import_file)

    # .schema
    # id INTEGER PRIMARY KEY AUTOINCREMENT,
    # first VARCHAR(255),
    # middle VARCHAR(255),
    # last VARCHAR(255),
    # house VARCHAR(10),
    # birth INTEGER
    # for each row , parse row
    for row in reader:
        # split the name in to two or 3 parts based on he total strings in the split_name
        split_name = row['name'].split()
        if len(split_name) < 3:
            first = split_name[0]
            middle = None
            last = split_name[1]
            
        else:
            first = split_name[0]
            middle = split_name[1]
            last = split_name[2]
            
        house = row["house"]
        birth = row["birth"]
        
        # insert each student ino the students table of students.db
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first, middle, last, house, birth)
        
print("Done With Import.py")