# Socket program - Server

import threading
import socket

def handle_client(client_socket):
    while True:
        data = client_socket.recv(1024).decode()
        if not data:
            break
        print("from connected user: " + str(data))
        data = input(' -> ')
        client_socket.send(data.encode())  
    conn.close()  

def server_program():
	# host = socket.gethostname()
	host = "192.168.1.48"
	print(host)
	port = 5000  

	server_socket = socket.socket()  
	server_socket.bind((host, port))  

	server_socket.listen(14)
	client_sockets = []

	while True:
		# Accept incoming connections
		client_socket, address = server_socket.accept()
		print("Connection from: " + str(address))
		client_sockets.append(client_socket)
		threading.Thread(target=handle_client, args=(client_socket,)).start()

if __name__ == '__main__':
    server_program()
    
