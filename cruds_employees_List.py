# CRUDS (Employees)Program(List of Lists)

records_data = []
file_name = "employees.dat"
fields = ["employee_id", "name", "gender", "designation", "salary"]
menu_options = {
    1: lambda: add_new_employee(),
    2: lambda: show_employees(),
    3: lambda: update_employee_details(),
    4: lambda: delete_employee(),
    5: lambda: sort_employees(),
    6: lambda: exit()
}
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
    
def add_new_employee():
    new_record = []
    for field in fields:
        data = input("Enter the " + field +": ")
        new_record.append(data)
    records_data.append(new_record)

def show_employees():
    for record in records_data:
        for index, field in enumerate(fields):
            print(field, ":", record[index])
    print()

def search_employee(task):
    target = input("Enter Employee ID to " + task + ": ")
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

def update_employee_details():
    if search_employee("Update") == 1:
        choice = select_option("update")
        print("The existing value to update is " + records_data[data_index][choice])
        records_data[data_index][choice] = input("Enter the new value: ")
        print("Updated!")
    
def delete_employee():
    if search_employee("Delete") ==1:
        records_data.pop(data_index)
        print("Record Deleted!")
        
def sort_employees():
    choice = select_option("sort")
    data_to_sort = records_data
    data_to_sort.sort(key = lambda x: x[choice])
    for record in data_to_sort:
        print(record)

def menu():
    global menu_options
    print("1. Add New employee\n2. Show all employees details\n3. Upadate an employee details\n4. Delete an employee\n5. sort\n6. Exit")
    choice = int(input("Enter your choice: "))
    menu_options.get(choice)()
    save_data()
    menu()

load_data()
menu()