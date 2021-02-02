import pymongo,socket,threading,smtplib,uuid
from email.message import EmailMessage



"""
similar to the local version server
with protection benefits
*(lacks ssl security)
*(implement ssl for actual remote use)

"""
class MongoManager:
	def __init__():
		self.client = pymongo.MongoClient("mongodb://localhost:27017/")
        self.db = self.client['persons']
        self.collection = self.db["profiles"] #main collection

class Router : 
	def __init__():
		self.mongo_manager = MongoManager()

class SessionManager:
	def __init__():
		self.active_tokens = set()
		self.addrs = []
	def add_session(addr,token):
		self.addrs.append(addr)
		self.active_tokens.add(token)
		print(addr +"has been authenticated..number of Users:"+
					str(len(addrs)))
	def remove_session(addr,token) :
		pass

class Server:
	def __init__(self):
		self.STATIC_CODE = 0 #used for authentication
		self.host = '127.0.0.1' #localhost
		self.port  = 54000
		self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.running = True
        self.session_manager = SessionManager()
        self.router = Router()

    def monitor_requests(self,client,addr,token):
    	running  = True
    	while  running:
    		request_action = client.recv(100).decode("ascii")
    		if request_action == "DISCONNECT_":
    			self.session_manager.remove_session(addr,token)
    		else:
    			#route request


    def client_thread(self,client,addr):
    	    code_size = int(str(client.recv(100).decode("ascii"))) 
            code = client.recv(data_size).decode("ascii")
            if code == STATIC_CODE:
            	token = uuid.uuid4()#unique id
            	self.session_manager.add_session(addr,token)
            	client.send("AUTHED".encode("ascii"))
            	self.monitor_requests(client,addr,token)
            else:
            	client.send("ERROR".encode("ascii"))
            	
      


    def start_server(self):
        self.server.bind((self.host,self.port))
        self.server.listen()
        while self.running == True:
            client , addr = self.server.accept()
            #start new thread to avoid blocking new connections!
            thread = threading.Thread(target =self.client_thread, args = (client,addr,))
            thread.start()
