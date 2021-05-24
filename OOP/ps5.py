# 6.0001/6.00 Problem Set 5 - RSS Feed Filter
# Name:
# Collaborators:
# Time:

import feedparser
import string
import time
import threading
from project_util import translate_html
from datetime import datetime, timezone
import pytz


#-----------------------------------------------------------------------

#======================
# Code for retrieving and parsing
# Google and Yahoo News feeds
# Do not change this code
#======================

def process(url):
    """
    Fetches news items from the rss url and parses them.
    Returns a list of NewsStory-s.
    """
    feed = feedparser.parse(url)
    entries = feed.entries
    ret = []

    for entry in entries:
        guid = entry.guid
        title = translate_html(entry.title)
        link = entry.link
        description = ""
        try:
            description = translate_html(entry.description)
        except:
            description = translate_html(entry.title_detail)
        pubdate = translate_html(entry.published)

        try:
            pubdate = datetime.strptime(pubdate, "%a, %d %b %Y %H:%M:%S %Z")
            pubdate.replace(tzinfo=pytz.timezone("GMT"))
          #  pubdate = pubdate.astimezone(pytz.timezone('EST'))
          #  pubdate.replace(tzinfo=None)
        except ValueError:
            pubdate = datetime.strptime(pubdate, "%a, %d %b %Y %H:%M:%S %z")

        #newsStory = NewsStory(guid, title, description, link, pubdate)
        newsStory = NewsStory(guid, title, description, link, pubdate)
        ret.append(newsStory)
    return ret

#======================
# Data structure design
#======================

# Problem 1

class NewsStory(object):

    # deffining the data attribute for class NewsStory
    def __init__(self, guid, title, description, link, pubdate):
        self.guid = guid
        self.title = title
        self.description = description
        self.link = link
        self.pubdate = pubdate

    # creating different ways to manipulate the class NewsStory
    def get_guide(self):
        return self.guid

    def get_title(self):
        return self.title

    def get_description(self):
        return self.description

    def get_link(self):
        return self.link

    def get_pubdate(self):
        return self.pubdate
#======================
# Triggers
#======================

class Trigger(object):
    def evaluate(self, story):
        """
        Returns True if an alert should be generated
        for the given news item, or False otherwise.
        """
        # DO NOT CHANGE THIS!
        raise NotImplementedError

# PHRASE TRIGGERS

# Problem 2
# TODO: PhraseTrigger
class PhraseTrigger(Trigger):

    def __init__(self, phrase):
        self.phrase = phrase.upper()

    # returning true if the phrase exist in the string argument text, false otherwise
    def is_phrase_in(self, string_argument):

       # converting string_argument to upper for casse sensitive string_argument text. then splitting the word in the phrase with the space
        self.string_argument = string_argument.upper()
        phrase_split = self.phrase.split()
        word_list = ""

        # iterating through the string_argument text and if the char is withing the list of string.pronunciatio(!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~),
        # replacing that with space and if not in the list, just adding the char in the word_list
        # for char in string_argument:
        for char in self.string_argument:
            if char in string.punctuation:
                word_list += " "
            else:
                word_list += char

        # splitting the word_list with the space and iterating over word_list to remove the '' if any in the word_list
        word_list = word_list.split()
        while "" in word_list:
            word_list.remove("")

        # iterating over phrase_split and if words in the word_list and the phrase mathes, returning true else returning false
        for word in phrase_split:
            word_list_join = " ".join(word_list)
            if word in word_list and self.phrase in word_list_join:
                result = True
            else:
               result = False

        return result


# Problem 3
# TODO: TitleTrigger
# returning true if the title of the story contains a valid phrase, false otherwise
class TitleTrigger(PhraseTrigger):

    def __init__(self, phrase):
        PhraseTrigger.__init__(self, phrase)

    def evaluate(self, story):
        return self.is_phrase_in(story.get_title())


# Problem 4
# TODO: DescriptionTrigger
# returning true if the description of the story contains a valid phrase, false otherwise
class DescriptionTrigger(PhraseTrigger):

    def __init__(self, phrase):
        PhraseTrigger.__init__(self, phrase)

    def evaluate(self, story):
        return self.is_phrase_in(story.get_description())



# TIME TRIGGERS

# Problem 5
# TODO: TimeTrigger
# Constructor:
# Input: Time has to be in EST and in the format of "%d %b %Y %H:%M:%S".
# Convert time from string to a datetime before saving it as an attribute.
class TimeTrigger(Trigger):

    def __init__(self, time):
        time = datetime.strptime(time, "%d %b %Y %H:%M:%S")
        time = time.replace(tzinfo=pytz.timezone("EST"))
        self.time = time

# Problem 6
# TODO: BeforeTrigger and AfterTrigger
# BeforeTrigger fires when a story is published strictly before the trigger’s time,
class BeforeTrigger(TimeTrigger):

    def evaluate(self, story):
        pub_date = story.get_pubdate().replace(tzinfo=pytz.timezone("EST"))
        return self.time > pub_date

# AfterTrigger fires when a story is published strictly after the trigger’s time
class AfterTrigger(TimeTrigger):

    def evaluate(self, story):
        pub_date = story.get_pubdate().replace(tzinfo=pytz.timezone("EST"))
        return self.time < pub_date


# COMPOSITE TRIGGERS

# Problem 7
# TODO: NotTrigger
class NotTrigger(Trigger):

    # trigger should take this other trigger as an argument to its constructor
    def __init__(self, trigger):
        self.trigger = trigger

    #This trigger should produce its output by inverting the output of another trigger.
    def evaluate(self, story):
        return not self.trigger.evaluate(story)

# Problem 8
# TODO: AndTrigger
class AndTrigger(Trigger):

    #This trigger should take two triggers as arguments to its constructor
    def __init__(self, trigger_1, trigger_2):
        self.trigger1 = trigger_1
        self.trigger2 = trigger_2

    #should fire if either one (or both) of its inputted triggers would fire on that item.
    def evaluate(self, story):
        return self.trigger1.evaluate(story) and self.trigger2.evaluate(story)

# Problem 9
# TODO: OrTrigger
class OrTrigger(Trigger):

    #This trigger should take two triggers as arguments to its constructor
    def __init__(self, trigger_1, trigger_2):
        self.trigger1 = trigger_1
        self.trigger2 = trigger_2

    #should fire if either one (or both) of its inputted triggers would fire on that item
    def evaluate(self, story):
        return self.trigger1.evaluate(story) or self.trigger2.evaluate(story)

#======================
# Filtering
#======================

# Problem 10
#returning a list of only the stories for which a trigger fires.
def filter_stories(stories, triggerlist):
    """
    Takes in a list of NewsStory instances.

    Returns: a list of only the stories for which a trigger in triggerlist fires.
    """
    # TODO: Problem 10
    # This is a placeholder
    # (we're just returning all the stories, with no filtering)
    triggered_stories = []
    for story in stories:
        for trigger in triggerlist:
            if trigger.evaluate(story):
                if story not in triggered_stories:
                    triggered_stories.append(story)
    return triggered_stories



#======================
# User-Specified Triggers
#======================
# Problem 11
def read_trigger_config(filename):
    """
    filename: the name of a trigger configuration file

    Returns: a list of trigger objects specified by the trigger configuration
        file.
    """
    # We give you the code to read in the file and eliminate blank lines and
    # comments. You don't need to know how it works for now!
    trigger_file = open(filename, 'r')
    lines = []
    for line in trigger_file:
        line = line.rstrip()
        if not (len(line) == 0 or line.startswith('//')):
            lines.append(line)

    # TODO: Problem 11
    # line is the list of lines that you need to parse and for which you need
    # to build triggers

    print(lines) # for now, print it so you see what it contains!



SLEEPTIME = 120 #seconds -- how often we poll


if __name__ == '__main__':
    # A sample trigger list - you might need to change the phrases to correspond
    # to what is currently in the news
    try:
        #t1 = TitleTrigger("election")
        #t2 = DescriptionTrigger("Trump")
        #t3 = DescriptionTrigger("Biden")
        #t4 = AndTrigger(t2, t3)
        #triggerlist = [t1, t4]

        # Problem 11
        # TODO: After implementing read_trigger_config, uncomment this line
        #triggerlist = read_trigger_config('triggers.txt')s

        # HELPER CODE - you don't need to understand this!
        # Reads and writes Newsstories to stories.txt in specified format
        # Retrieves and filters the stories from the RSS feeds
        guidShown = []
        def get_cont(newstory):
            if newstory.get_guid() not in guidShown:
                guidShown.append(newstory.get_guid())

        while True:


            print("Polling . . .", end=' ')
            # Get stories from BBC's Top Stories RSS news feed
            stories = process("http://feeds.bbci.co.uk/news/rss.xml")

            # Get stories from Yahoo's Top Stories RSS news feed
            stories.extend(process("http://news.yahoo.com/rss/topstories"))

            stories = filter_stories(stories, triggerlist)


            #@ISMAMA
            file = open('stories.txt', 'w')
            for s in stories:
                file.write(s.title.strip())
                file.write("\n")
                for i in range(len(s.title)):
                    file.write("-")
                file.write("\n")
                file.write(s.description.strip())
                file.write("\n")
                file.write(s.link.strip())
                file.write("\n")
                file.write("_"*60)
                for s in range(2):
                    file.write("\n")
            file.close()

            #Do not uncomment these lines
            #Dlist(map(get_cont, stories))
            #Dscrollbar.config(command=cont.yview)


            print("Sleeping...")
            time.sleep(SLEEPTIME)

    except Exception as e:
        print(e)