local etcd = require "libetcd"

cb = {}

if not hive.init_flag then
    _G.cli = etcd.create_etcd_client("http://127.0.0.1:2379")
    hive.start_time = hive.start_time or hive.get_time_ms()
    hive.frame = hive.frame or 0

    hive.init_flag = true
end

token = cli.watch("/", true)
-- token = cli.watch("/test", true, index)
cb[token] = function(token, success, msg, action, index, key, value, values)
    print("--------------------watch-------------------")
    print(action)
    print(string.format("token: %d | is_ok: %s | msg: %s | action: %s | index : %s | key: %s | value: %s", token, tostring(success), msg, tostring(action), tostring(index), tostring(key), tostring(value)))
    print("--------------------values-------------------")
    if values ~= nil then
        for key, value in pairs(values) do
            print(key, value)
        end
    end
    print("----------------------end-------------------")
end

hive.run = function()
    hive.now = os.time()

    cli.wait_watch()
    local cost_time = hive.get_time_ms() - hive.start_time
    if 100 * hive.frame < cost_time then
        hive.frame = hive.frame + 1
        collectgarbage("collect")
    end

    hive.sleep_ms(5);
end

cli.on_watch_response = function(token, success, msg, action, index, key, value, values)
    callback = cb[token]

    if callback ~= nil then
        callback(token, success, msg, action, index, key, value, values)
    end
end
