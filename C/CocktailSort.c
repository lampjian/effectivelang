public static int[] cocktailSort(int[] src)
{
    for(int i = 0 ; i < src.length/2 ; i++)
    {
        for(int j = i ; j < src.length-i-1 ; j++)
        {
            if(src[j] < src[j+1])
            {
                int temp = src[j];
                src[j] = src[j+1];
                src[j+1] = temp;
            }
        }
        for(int j = src.length-1-(i+1); j > i ; j--)
        {
            if(src[j] > src[j-1])
            {
                int temp = src[j];
                src[j] = src[j-1];
                src[j-1] = temp;
            }
        }
    }
    return src;
}

