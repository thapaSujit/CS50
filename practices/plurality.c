from sys import argv, exit
import csv

#Checking if the command line arguement is valid (=3), if not, printing error message.
if len(argv) != 3:
    print("Invalid Command line Arguement. Try again!!")
    exit(1)

#open the CSV file and DNA sequence , read contents into memory(Pythons CSV module reader and dictreader can be helpful), storing  dna sequence into a string
#argv[0] is the name of the file. the name "python" is not command line arguement
#reading the sequences and storing in the string
with open(argv[2], "r") as dna_sequence_file:
    dna_sequence_file_reader = csv.reader(dna_sequence_file)
    for row in dna_sequence_file_reader:
        dna_list = row
        print(dna_list)

dna = dna_list[0]
sequences = {}
print(dna)
print(sequences)
#accessing the textfile and getting the DNA sequenes
with open(argv[1], "r") as text_file:
    text_file_reader = csv.reader(text_file)

    #the pop(0) will remove the first element in the row
    for row in text_file_reader:
        person_dna_sequence = row
        person_dna_sequence.pop(0)
        print(person_dna_sequence)
        break
#copying the list into dictionaries

for number in person_dna_sequence:
    sequences[number] = 1
print (sequences)

#iterating over the seqences
for key in sequences:
    max_str = 0
    cur_str = 0
    for i in range(len(dna)):
        print(i)
        while cur_str > 0:
            cur_str -= 1
            print(cur_str)
            continue

        cur_4_bases = dna[i: i + len(key)]
        if cur_4_bases == key:
            while dna[i - len(key): i] == cur_4_bases:
                cur_str += 1
                print (f"current, {cur_str}")
                i += len(key)

        if cur_str > max_str:
            max_str = cur_str

    sequences[key] += max_str
print(sequences)

with open(argv[1], newline = '') as text_file:
    text_file_reader = csv.DictReader(text_file)
    for person in text_file_reader:
        match = 0
        print(person)
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        if match == len(sequences):
            print(person['name'])
            exit(0)
    print("No match")


