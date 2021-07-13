from csv import reader, DictReader
from sys import argv

if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

# This is programmed to read the DNA sequence of a person from the file and form a list

with open(argv[1]) as pfile:
    people = reader(pfile)
    for row in people:
        dnaSequences = row
        dnaSequences.pop(0)
        break

with open(argv[2]) as DNAfile:
    dnareader = reader(DNAfile)
    for row in dnareader:
        dnalist = row


dna = dnalist[0]  # This is programmed to store the list in a string
sequences = {}
# This is programmed to store the list of sequences 

for item in dnaSequences:
    sequences[item] = 1

for key in sequences:
    x = len(key)
    temp = 0
    MAXtemp = 0

    for i in range(len(dna)):
        while temp > 0:
            temp -= 1
            continue  # This part is programmed to count the number of repetitions in the dna sequences
# This part also skips the DNA sequence after the sequence is counted to avoid repetition.

        if dna[i: i + x] == key:
            while dna[i - x: i] == dna[i: i + x]:
                temp += 1
                i += x

            if temp > MAXtemp:
                MAXtemp = temp  # This part is programmed to compare the certain value with other sequences and checks whether it's longer or not.

    sequences[key] += MAXtemp

# This part is programmed to store the long sequences using the key.

with open(argv[1], newline='') as pfile:
    people = DictReader(pfile)
    
    for person in people:
        match = 0
        
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        
        if match == len(sequences):
            print(person['name'])
            exit()

    print("No match\n")