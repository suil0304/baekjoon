local r = 31
local m = 1234567891

local length = io.read("*n")
io.read("*l") -- \n 자르기
local str = io.read("*a")

local sum = 0
local power = 1
for i = 1, length, 1 do
    sum = (sum + ((string.byte(str, i) - 97 + 1) * power)) % m
    power = (power * r) % m
end

print(sum)