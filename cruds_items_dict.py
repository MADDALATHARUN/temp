# CRUDS Program(items)(using dictionary of Lists)
import speech_recognition as sr

records = {}
file_name = "new_items.dat"
fields = ["item_id", "item_description", "item_price", "item_quantity"]
target =""

def save_data():
    file = open(file_name, 'w')
    file.write(str(records))
    file.close()

def load_data():
    file = open(file_name, 'r')
    global records
    file_data = file.read()
    if file_data != "":
        records= eval(file_data)

def add_new_record():
    record = []
    for field in fields:
        record.append(input("Enter the " + field +": "))
    records[record[0]] = record[1:]

def show_records():
    for temp_record in records.items():
        print(temp_record, end = '\n')

def search_record(task):
    global target 
    target = input("Enter Item ID to " + task + ": ")
    if target in records:
        return 1
    print("Record not Found!")
    return 0

def select_option(task):
    for field in fields[:]:
            print(fields.index(field) , ". " + field)
    return int(input("Enter your choice to "+ task +": "))

def update_record():
    if search_record("Update") == 1:
        choice = select_option("update")
        if choice > 0:
            records[target][choice-1] = input("Enter the new value: ")
        if choice == 0:
            temp = input("Enter the new value: ")
            records[temp] = records.pop(target)
        print("Record Updated!")

def delete_record():
    if search_record("Delete") == 1:
        records.pop(target)
        print("Record Deleted!")

def sort_records():
    choice = select_option("sort")
    if choice > 0:
        sorted_data = sorted(records.items(), key = lambda item:item[1][choice-1])
    else:
        sorted_data = sorted(records.items())
    for record in sorted_data:
        print(record, end = '\n')

def menu():
    print("1. Add New Record  \n2. Show Records\n3. Upadte Record\n4. Delete Record\n5. Sort Records\n6. Exit")
    #choice = int(input("Enter your choice: "))
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Start Talk")
        audio_text = r.listen(source)
        print("Time over!, thanks")
        try:
            text = r.recognize_google(audio_text)
        except:
            print("Sorry, I did not get that try again!")
    print(text)
    text = text.replace(" ","_")
    f = eval(text)
    f()
    save_data()
    menu()

load_data()
menu()

