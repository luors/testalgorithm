


local function call(addr,msgtype,cmd,subcmd)
	
	print (addr ,type(addr))
	print (msgtype,type(msgtype))
	print (cmd,type(cmd))
	print (subcmd,type(subcmd))
end

local cmdline = [["adfa","ffff","bbbbb", "aaaaaa"]]
local args_func = load("return " .. cmdline, "debug console", "t", {})

local args = table.pack(args_func())
print (args)
print "----------11--------"
for k,v in pairs(args) do 
	print(k,v)
end
print "----------22--------"
print("????",args.n)
call(1111,table.unpack(args,2,args.n))
