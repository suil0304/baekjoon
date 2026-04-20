using System.Numerics;

int num = int.Parse(Console.ReadLine());

Console.WriteLine(factorial(num));

BigInteger Factorial(BigInteger n)
{
    BigInteger bigInteger = 1;
    for(BigInteger i = 1; i <= n; i++)
    {
        bigInteger *= i;
    }

    return bigInteger;
}