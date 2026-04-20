Dictionary<string, bool> meetPeople = new Dictionary<string, bool>();
meetPeople["ChongChong"] = true;

int t = int.Parse(Console.ReadLine());

for(int i = 0; i < t; i++)
{
    string[] strs = Console.ReadLine().Split();
    bool meetPerson1;
    meetPeople.TryGetValue(strs[0], out meetPerson1);
    bool meetPerson2;
    meetPeople.TryGetValue(strs[1], out meetPerson2);

    if(meetPerson1 || meetPerson2)
    {
        meetPeople[strs[0]] = true;
        meetPeople[strs[1]] = true;
    }
}

int count = meetPeople.Sum(item => item.Value ? 1 : 0);

Console.WriteLine(count);