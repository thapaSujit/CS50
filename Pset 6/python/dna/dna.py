from sys import argv, exit
import csv

# Checking if the command line arguement is valid (=3), if not, printing error message.
if len(argv) != 3:
    print("Invalid Command line Arguement. Try again!!")
    exit(1)

# open the CSV file and DNA sequence , read contents into memory(Pythons CSV module reader and dictreader can be helpful), storing  dna sequence into a string
# argv[0] is the name of the file. the name "python" is not command line arguement
# reading the sequences and storing in the string
with open(argv[2], "r") as dna_sequence_file:
    dna_sequence_file_reader = csv.reader(dna_sequence_file)
    for row in dna_sequence_file_reader:
        dna_list = row
        print(dna_list)

# copying the list into dictionaries
dna = dna_list[0]
print(dna)


# accessing the textfile and getting the DNA sequenes
with open(argv[1], "r") as text_file:
    text_file_reader = csv.reader(text_file)

    # the pop(0) will remove the first element in the row
    for row in text_file_reader:
        person_dna_sequence = row
        person_dna_sequence.pop(0)
        # print(person_dna_sequence)
        break
# copying the above list into a dictionary
sequences = {}

# print(sequences)
for number in person_dna_sequence:
    sequences[number] = 1

print (sequences)

# iterating over the seqences. if the repetitions of the values from sequence dictionary are founf, it counts them
for key in sequences:
    max_str = 0
    cur_max_str = 0
    for i in range(len(dna)):

        # to make sure that maxstr is not the summation of total strs in the list but the maximum number of times it repeats continuously,
        # if cur_str is greater than 0, we skip to the end
        while cur_max_str > 0:
            cur_max_str -= 1

            # print(f"current maximum 1 = {cur_max_str}")
            continue

        # if the dna sequence matches the key and the is a continous repeatation, incrementing the cur_str
        if dna[i: i + len(key)] == key:
            while dna[i - len(key): i] == dna[i: i + len(key)]:
                cur_max_str += 1

                # print(f"current maximum 2 = {cur_max_str}")
                i += len(key)

        # comparing the cur_max_str and if it is higher than the max_str, setting it as the max_str
        if cur_max_str > max_str:
            max_str = cur_max_str

    # setting the max_str in the dictionary using the correspong key
    sequences[key] += max_str

# print(sequences)

# opening the CSV file again and iterating over it to compare the dna. if dna is matched, printing the corresponding name  if not printng no match
with open(argv[1]) as text_file:
    text_file_reader = csv.DictReader(text_file)
    for person in text_file_reader:
        match = 0

        # comparing the dna and if match is found, printing the name. if not priting "no match"
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        if match == len(sequences):
            print(person['name'])
            exit(0)
    print("No match")