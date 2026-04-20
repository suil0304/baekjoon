string? str;
while((str = Console.ReadLine()) != null)
{
    int n = int.Parse(str);
    if(n == 0)
    {
        Console.WriteLine('-');
    }
}