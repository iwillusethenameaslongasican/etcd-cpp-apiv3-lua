local etcd = require "libetcd"

cb = {}

if not hive.init_flag then
    _G.cli = etcd.create_etcd_client("http://127.0.0.1:2379")
    hive.start_time = hive.start_time or hive.get_time_ms()
    hive.frame = hive.frame or 0

    hive.init_flag = true
end

etcd_func = function(token, success, msg, action, index, key, value, values)
    print("--------------------etcd_func-------------------")
    print(action)
    print(string.format("token: %d | is_ok: %s | msg: %s | action: %s | index : %s | key: %s | value: %s", token, tostring(success), msg, tostring(action), tostring(index), tostring(key), tostring(value)))
    -- print("token: "..token.." | is_ok: "..success.. " | msg: ".. msg.. " | action: "..newaction.." | index: "..newindx.." | value: "..newvalue)
    print("--------------------values-------------------")
    if values ~= nil then
        for key, value in pairs(values) do
            print(key, value)
        end
    end
    print("----------------------end-------------------")
end

token = cli.set("/test/key", "43")
cb[token] = etcd_func
token = cli.set("/test/key", 1000)
cb[token] = etcd_func
token = cli.get("/test/key")
cb[token] = etcd_func
token = cli.add("/test/addkey", 100)
cb[token] = etcd_func
token = cli.add("/test/addkey", 50)
cb[token] = etcd_func
token = cli.add("/test/newaddkey", 80)
cb[token] = etcd_func
token = cli.modify("/test/newaddkey", 888)
cb[token] = etcd_func
token = cli.rm("/test/newaddkey")
cb[token] = etcd_func
token = cli.ls("/test")
cb[token] = etcd_func
token = cli.leasegrant(10)
cb[token] = etcd_func


hive.run = function()
    hive.now = os.time()

    cli.wait()
    local cost_time = hive.get_time_ms() - hive.start_time
    if 100 * hive.frame < cost_time then
        hive.frame = hive.frame + 1
        collectgarbage("collect")
    end

    hive.sleep_ms(5);
end

cli.on_response = function(token, success, msg, action, index, key, value, values)
    callback = cb[token]

    if callback ~= nil then
        callback(token, success, msg, action, index, key, value, values)
        cb[token] = nil
    end
end
