
local skynet = require "skynet"
local maxclient = 4098
local cout = skynet.error
skynet.start(
	function()
		cout( "test start main service")
		skynet.newservice("debug_console",8000)
		local playergate = skynet.newservice("playergate")
		skynet.call(playergate,"lua","start",{
			port = 67889,
			maxclient = maxclient,
			nodelay = true,
		})
		cout("main id="..skynet.self())
		skynet.exit()
	end
)



