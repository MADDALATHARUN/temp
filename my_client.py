#Socket program - client

import socket

def client_program():
    #host = socket.gethostname()  
    host = "138.68.140.83"
    print(host)
    port = 5025 
    client_socket = socket.socket()  
    client_socket.connect((host, port))  
    message = input(" -> ") 

    while message.lower().strip() != 'bye':
        client_socket.send(message.encode())  
        data = client_socket.recv(1024).decode()  
        print('Received from server: ' + data)  

        message = input(" tharun-> ")  

    client_socket.close()  

client_program()