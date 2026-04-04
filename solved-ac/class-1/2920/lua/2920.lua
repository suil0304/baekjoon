local isAscending = true
local isDescending = true

local prev = 0
for i = 1, 8 do
    local num
    num = io.read("*n");

    if prev ~= 0 and prev + 1 ~= num then
        isAscending = false
    end
    if prev ~= 0 and prev - 1 ~= num then
        isDescending = false
    end
    prev = num
end

if isAscending then
    print("ascending")
elseif isDescending then
    print("descending")
else
    print("mixed")
end