from datetime import datetime
import pytz

A = ['Europe/Berlin', 'America/New_York', 'Europe/London', 'Asia/Shanghai', "Africa/Accra"]

def main():
    # defining datetime format and accessing the current date time in  date_time_format
    date_time_format = "%d/%m/%Y, %H:%M:%S"
    Now = datetime.utcnow()
    #print(Now.time())
    #print(Now.date())
    #now takes additional argument of TZinfo, we use the pytz module to access universal time zone
    #now = now.replace(tzinfo=pytz.utc)
    #print(now)
    #local = datetime.now()
    #convertig date intp string with strftime
    #print("Local :", local.strftime(date_time_format))
    print(f"Local : {Now.strftime(date_time_format)}")
    # astimezone -->Return a datetime object with new tzinfo attribute tz, adjusting the date and      time data so the result is the same UTC time as self, but in tz‘s local time.
    for cities in A:
        t =  Now.astimezone(pytz.timezone(cities))
        print(f"{cities} : {t.strftime(date_time_format)}")
    #ToDo
if __name__ == "__main__":
    main()
