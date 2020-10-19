
local skynet = require "skynet"
local gate

local socket_cmd = {}
local game_cmd = {}
local link_list = {}

local print  = print

local function close_link(fd)
	local l = link_list[fd]
	link_list[l] = nil
	if l then 
		skynet.call(gate,"lua","kick,fd)
	end
	skynet.send(a,"lua","disconnect")
end


function socket_cmd.error(fd,msg)
	print("socket error",fd,msg)
	close_link(fd)
end


function socket_cmd.warning(fd,size)
	
	print("socket warning", fd ,size)

end

function socket_cmd.data(fd,msg)
	
	print("socket data", fd ,msg)
	
end

function game_cmd.start(conf)
	skynet.call(gate,"lua","open",conf)
end


function game_cmd.close(fd)
	close_link(fd)
end


local cout = skynet.error
skynet.start(
	function()
		cout("test start playergate service")
		skynet.dispatch("lua",function(session,source,cmd,subcmd,...)
			if cmd == "socket" then
				local f = socket_cmd[subcmd]
				f(...)
			else
				local f = game_cmd[cmd]
				if f then
					skynet.ret( skynet.pack( f(subcmd,...) ) )
				else
					skynet.ret(skynet.pack("no such cmd"..cmd));
				end
			end
		end)
		gate = skynet.newservice("gate")
	end
)



