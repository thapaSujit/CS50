import string

def main():
    with open ("silent_sea.txt", "r") as input_file:
        input_file_reader = input_file.read()
        print (input_file_reader)
        #split is going to separate everyhing on individual words
        #words = input_file_reader.split()
        #print(words)
        print(string.punctuation)
        list = []
        for ch in input_file_reader:
            if ch in string.punctuation:
                list.append("")
            else:
                list.append(ch)

        print(list)
        cleaned = "".join(list)
        print(cleaned)

        with open("silent_sea_clean.txt", "w") as output_file:
            output_file_writer = output_file.write(cleaned)
    # ToDo

if __name__== "__main__":
    main()
