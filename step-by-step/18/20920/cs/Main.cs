int[] arr = Console.ReadLine()!.Split().Select(int.Parse).ToArray();
int t = arr[0];
int maxLength = arr[1];

Dictionary<string, int> strs = new Dictionary<string, int>();
for(int i = 0; i < t; i++)
{
    string str = Console.ReadLine()!;
    if(str.Length >= maxLength)
    {
        strs[str] = strs.GetValueOrDefault(str, 0) + 1;
    }
}

var distStrs = strs.Distinct()
    .OrderByDescending(item => item.Value)
    .ThenByDescending(item => item.Key.Length)
    .ThenBy(item => item.Key)
    .ToList();

foreach(var str in distStrs)
{
    Console.WriteLine(str.Key);
}