int n = int.Parse(Console.ReadLine());

Console.WriteLine(factorial(n));

long factorial(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    return factorial(n - 1) * n;
}