int[] inputs = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
int arrayLength = inputs[0];
int queryNum = inputs[1];

int count = 0;
int result = -1;
bool allStop = false;
int[] temp = new int[arrayLength];

int[] intArray = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
mergeSort(intArray, 0, arrayLength - 1);

Console.WriteLine(result);

void mergeSort(int[] ints, int p, int r)
{
    if(p < r && !allStop)
    {
        int q = (p + r) / 2;
        mergeSort(ints, p, q);
        mergeSort(ints, q + 1, r);
        merge(ints, p, q, r);
    }
}

void merge(int[] ints, int p, int q, int r)
{
    if(allStop)
    {
        return;
    }

    int i = p;
    int j = q + 1;
    int tempIndex = 0;

    while(i <= q && j <= r)
    {
        if(ints[i] <= ints[j])
        {
            temp[tempIndex] = ints[i];
            tempIndex++;
            i++;
        }
        else
        {
            temp[tempIndex] = ints[j];
            tempIndex++;
            j++;
        }
    }

    while(i <= q)
    {
        temp[tempIndex] = ints[i];
        tempIndex++;
        i++;
    }
    while(j <= r)
    {
        temp[tempIndex] = ints[j];
        tempIndex++;
        j++;
    }

    i = p;
    tempIndex = 0;
    
    while(i <= r)
    {
        count++;
        if(count == queryNum)
        {
            result = temp[tempIndex];
            allStop = true;

            return;
        }
        ints[i] = temp[tempIndex];
        i++;
        tempIndex++;
    }
}