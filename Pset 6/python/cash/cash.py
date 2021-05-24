from cs50 import get_float

def main():
    while True:
        change_owed = get_float("change owed: ")
        if change_owed > 0:
            break

    cents = round(change_owed * 100)
    
    no_of_coin = 0
    remaining_cents = 0
    
    while cents >= 25:
        no_of_coin += 1
        cents -= 25
    
    while cents >= 10:
        no_of_coin += 1
        cents -= 10
    
    while cents >= 5:
        no_of_coin += 1
        cents -= 5
    
    while cents >= 1:
        no_of_coin += 1
        cents -= 1
    
    print(no_of_coin)

main()