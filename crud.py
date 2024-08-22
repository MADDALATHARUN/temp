file = "new_names.txt"
names = []
def load_data():
    global names 
    f = open(file, 'r')
    temp_string =f.read() 
    if temp_string != "":
        names = eval(temp_string)
    f.close()
def save_data():
    f = open(file, 'w')
    f.write(str(names))
    f.close()
def new_name():
    name = input("Enter the name: ")
    names.append(name)
def show_names():
    print(names)
def search_name():
    find = input("Enter the name to search: ")
    if find in names:
        return names.index(find)
    else:
        print("Data not found!")
def update_name():
    index = search_name()
    names[index] = input("Enter new name to update: ")
def delete_name():
    names.pop(search_name())
load_data()
while(1):
    print("1. New Name \n2. Show Names\n3. Upadte Name\n4. Delete Name\n5. Exit")
    choice = int(input("Enter your choice: "))
    if(choice == 1):
        new_name()
    elif(choice == 2):
        show_names()
    elif(choice == 3):
        update_name()
    elif(choice == 4):
        delete_name()
    else:
        break
    save_data()