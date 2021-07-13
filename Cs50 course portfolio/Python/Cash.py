def main():
    owed = get_owed()
    coins = calc_coins(owed)
    print(f"{coins}")  # print the amoutn of coins


def get_owed():  # This is programmed to prompt the user for the change with the given input
    while True:
        try:
            owed = float(input("Change owed: "))
            if owed > 0:
                break
        except ValueError:  # This part is programmed to reject a non-numeric input given from the user
            None
           
    return owed


def calc_coins(owed):
    cents = round(owed * 100, 0)
    coins = 0

    while (cents > 0):
        if (cents >= 25):  # quarters
            cents -= 25
        
        elif (cents >= 10):  # dimes
            cents -= 10
        
        elif (cents >= 5):  # nickels
            cents -= 5
        
        else:
            cents -= 1  # pennies
        coins += 1
    
    return coins
    

if __name__ == "__main__":
    main()