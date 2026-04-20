using System.Numerics;

BigInteger[] arr = Console.ReadLine()!.Split().Select(BigInteger.Parse).ToArray();

Console.WriteLine(arr[0] / arr[1]);
Console.WriteLine(arr[0] % arr[1]);