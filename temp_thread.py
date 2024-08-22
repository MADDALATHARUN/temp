import threading

def print_odd_numbers(rang):
    for counter in range(rang,0,-1):
        if counter%2 != 0:
            print(counter)

def print_even_numbers(rang):
    for counter in range(1,rang):
        if counter%2 == 0:
            print(counter)

threading.Thread(target = print_odd_numbers, args=(20,)).start()
threading.Thread(target = print_even_numbers, args=(20,)).start()


#t1.join()
#t2.join()