import string
print (string.punctuation)
class PhraseTrigger(Trigger):
    def __init__(self, phrase):
        self.phrase = phrase.upper()

    # returning true if the phrase exist in the string argument text, false otherwise
    def is_phrase_in(self, string_argument):

       #converting string_argument to upper for casse sensitive string_argument text. then splitting the word in the phrase with the space
        self.string_argument = string_argument.upper()
        phrase_split = self.phrase.split()
        word_list = ""

        # iterating through the string_argument text and if the char is withing the list of string.pronunciatio(!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~),
        # replacing that with space and if not in the list, just adding the char in the word_list
        for char in self.string_argument:
            if char in string.punctuation:
                word_list += " "
            else:
                word_list += char

        # splitting the word split with the space and iterating over word_list to remove the '' if any in the word_list
        word_list = string_argument.split()
        while "" in word_list:
            word_list.remove("")

        # iterating over phrase_split and if words in the word_list and the phrase mathes, returning true else returning false
        for word in phrase_split:
            #word_list_join = " ".join(word_list)
            #if word in word_list and phrase in word_list_join:
            if word in word_list and phrase in " ".join(word_list):
                result = True
            else:
                return False
        return result




class PhraseTrigger(Trigger):
    def __init__(self, phrase):
        self.phrase = phrase
    def is_phrase_in(self, text):
        phrase = str.lower(self.phrase)
        phrase_elements = phrase.split(' ')
        clean_text = ''
        for char in str.lower(text):
            if char in string.punctuation:
                clean_text += ' '
            else:
               clean_text += char
        clean_text = clean_text.split(' ')
        while '' in clean_text:
            clean_text.remove('')
        for word in phrase_elements:
            if word in clean_text and phrase in ' '.join(clean_text):
                result = True
            else:
                return False
        return result

        class TitleTrigger(PhraseTrigger):
    def evaluate(self, story):
        return self.is_phrase_in(story.get_title())



class PhraseTrigger(Trigger):
    def __init__(self, phrase):
        self.phrase = phrase
    def is_phrase_in(self, text):
        phrase = str.lower(self.phrase)
        phrase_elements = phrase.split(' ')
        clean_text = ''
        for char in str.lower(text):
            if char in string.punctuation:
                clean_text += ' '
            else:
               clean_text += char
        clean_text = clean_text.split(' ')
        while '' in clean_text:
            clean_text.remove('')
        for word in phrase_elements:
            if word in clean_text and phrase in ' '.join(clean_text):
                result = True
            else:
                return False
        return result

class PhraseTrigger(Trigger):
    def __init__(self, phrase):
        self.phrase = phrase.upper()

    # returning true if the phrase exist in the string argument text, false otherwise
    def is_phrase_in(self, string_argument):

       #converting string_argument to upper for casse sensitive string_argument text. then splitting the word in the phrase with the space
       # string_argument = string_argument.upper()
        self.string_argument = string_argument.upper()
        #phrase = self.phrase
        #phrase_split = phrase.split()
        phrase_split = self.phrase.split()
        word_list = ""

        # iterating through the string_argument text and if the char is withing the list of string.pronunciatio(!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~),
        # replacing that with space and if not in the list, just adding the char in the word_list
        #for char in string_argument:
        for char in self.string_argument:
            if char in string.punctuation:
                word_list += " "
            else:
                word_list += char

        # splitting the word split with the space and iterating over word_list to remove the '' if any in the word_list
        word_list = word_list.split()
        while "" in word_list:
            word_list.remove("")

        # iterating over phrase_split and if words in the word_list and the phrase mathes, returning true else returning false
        for word in phrase_split:
            word_list_join = " ".join(word_list)
            if word in word_list and self.phrase in word_list_join:
                result = True
            else:
                return False
        return result

