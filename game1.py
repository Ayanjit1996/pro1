import random


def game(comp, you):
    if(comp == 'scissor'):
        if(you == 'paper'):
            return False
        elif (you == 'stone'):
            return True
        else:
            return None
    elif(comp == 'stone'):
        if(you == 'scissor'):
            return False
        elif (you == 'paper'):
            return True
        else:
            return None
    else:
        if(you == 'stone'):
            return False
        elif (you == 'scissor'):
            return True
        else:
            return None


print("Comp's turn to choose")
random_no = random.randint(1, 3)
if(random_no == 1):
    comp = 'stone'
elif (random_no == 2):
    comp = 'paper'
else:
    comp = 'scissor'

you = input(" Your turn, choose from- stone, paper, scissor ")
print(f"you choosed {you}")
print(f"comp choosed {comp}")
if (game(comp, you)==None):
    print(" Tie ")
elif(game(comp, you)):   
    print(" You won ")
else:
    print(" You lost")     
