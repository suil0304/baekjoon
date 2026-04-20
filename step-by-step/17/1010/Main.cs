using System.Numerics;

int t = int.Parse(Console.ReadLine());
for(int i = 0; i < t; i++)
{
    BigInteger[] array = Console.ReadLine().Split().Select(BigInteger.Parse).ToArray();
    BigInteger west = array[0];
    BigInteger east = array[1];

    Console.WriteLine(factorial(east) / (factorial(west) * factorial(east - west)));
}

BigInteger factorial(in BigInteger n)
{
    BigInteger fact = 1;
    for(BigInteger i = 1; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}