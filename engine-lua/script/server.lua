-- init


event_init()

-- create server
server = NetServer:new()
server.on_accept = function(conn)
	print("new connected")
	local pack = NetPacket:new()
	pack:pushString("msg 123456")
	conn:sendPacket(1, pack)
end

server.on_close = function(conn)
	print("close......")
end

server.on_msg = function(conn, msgtype, pack)
	local str = pack:getString()
	print("body=",str,  "msgId =", msgtype)
	conn:sendPacket(1, pack)
end

server:listen("127.0.0.1", 3002, false)

event_run()