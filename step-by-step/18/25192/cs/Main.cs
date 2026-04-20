Dictionary<string, bool> memberHello = new Dictionary<string, bool>();

int t = int.Parse(Console.ReadLine());
int count = 0;
for(int i = 0; i < t; i++)
{
    string str = Console.ReadLine();
    if(str.CompareTo("ENTER") == 0)
    {
        memberHello.Clear();
        continue;
    }
    
    bool boolean;
    memberHello.TryGetValue(str, out boolean);
    if(!boolean)
    {
        count++;
        memberHello[str] = true;
    }
}

Console.WriteLine(count);