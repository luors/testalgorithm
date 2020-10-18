
local skynet = require "skynet"
local gate

local cout = skynet.error
skynet.start(
	function()
		cout("test start playergate service")
		
		skynet.dispatch("lua",function(session,source,cmd,subcmd,...)
			
			--cout(session,source,cmd,subcmd,...)
			cout(cmd)
			cout (subcmd) 
			cout(...)
			skynet.ret(skynet.pack("test resp"));
		end)
		gate = skynet.newservice("gate")
	end
)



