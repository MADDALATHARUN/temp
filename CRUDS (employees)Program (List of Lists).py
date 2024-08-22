# CRUDS (Employees)Program  (List of Lists)

records_data = []
file_name = "employees.dat"
fields = ["employee_id", "name", "gender", "designation", "salary"]
data_index = None

def save_data():
    file = open(file_name, 'w')
    file.write(str(records_data))
    file.close()

def load_data():
    file = open(file_name, 'r')
    global records_data
    file_content = file.read()
    if file_content != "":
        records_data = eval(file_content)
    else:
        records_data = []
    
def add_new_account():
    new_record = []
    for field in fields:
        data = input("Enter the " + field +": ")
        new_record.append(data)
    records_data.append(new_record)

def show_accounts():
    for record in records_data:
        for index, field in enumerate(fields):
            print(field + ": " + record)
    print()

def search_account(task):
    target = input("Enter Account Number to " + task + ": ")
    global data_index
    for index, record in enumerate(records_data):
        if record[0] == target:
            data_index = index
            return 1
    print("Record not Found!")
    return 0

def select_option(task):
    for index, field in enumerate(fields):
        print(index , ". " + field)
    return int(input("Enter your choice to "+ task +": "))   

def update_account():
    if search_account("Update") == 1:
        choice = select_option("update")
        print("The existing value to update is " + records_data[data_index][choice])
        records_data[data_index][choice] = input("Enter the new value: ")
        print("Updated!")
    
def delete_account():
    search_account("Delete")
    records_data.pop(data_index)
    print("Record Deleted!")
        
def sort_accounts():
    choice = select_option("sort")
    data_to_sort = records_data
    data_to_sort.sort(key = lambda x: x[choice])
    for record in data_to_sort:
        print(record)

def menu():
    print("1. Add New Account  \n2. Show all Accounts\n3. Upadte a Account\n4. Delete a Account\n5. sort\n6. Exit")
    choice = int(input("Enter your choice: "))
    menu_options.get(choice)
    save_data()
    menu()
menu_options = {
    1: lambda: add_new_account(),
    2: lambda: show_accounts(),
    3: lambda: update_account(),
    4: lambda: delete_account(),
    5: lambda: sort_accounts(),
    6: lambda: exit()
    }
load_data()
menu()
