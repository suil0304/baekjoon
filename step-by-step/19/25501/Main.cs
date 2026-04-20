int t = int.Parse(Console.ReadLine());

for(int i = 0; i < t; i++)
{
    string str = Console.ReadLine();
    int[] numArray = isPalindrome(str);
    Console.WriteLine($"{numArray[0]} {numArray[1]}");
}

int[] isPalindrome(in string s)
{
    return recursive(in s, 0, s.Length - 1, 0);
}

int[] recursive(in string s, int l, int r, int count)
{
    if(l >= r)
    {
        return new int[] {1, count + 1};
    }
    if(s[l] != s[r])
    {
        return new int[] {0, count + 1};
    }
    return recursive(in s, l + 1, r - 1, count + 1);
}