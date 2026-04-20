int n = int.Parse(Console.ReadLine());

int[] nums = Console.ReadLine().Split().Select(int.Parse).ToArray();

int minNum = nums.Min();
int maxNum = nums.Max();

Console.WriteLine(maxNum * minNum);