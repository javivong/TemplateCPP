void interChange(int *replaced, int *replacer)
{
    int temp = *replaced;
    *replaced = *replacer;
    *replacer = temp;
}

void ascBubble(int array[], int size)
{
    int i, j;
    size = sizeof(array)/sizeof(array[0]);
    for (i = 0; i < size-1; i++)
        for (j = 0; j < size-i-1; j++)
        {
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
        }
}

void descBubble(int array[], int size)
{
    int i, j;
    size = sizeof(array)/sizeof(array[0]);
    for (i = 0; i < size-1; i++)
        for (j = 0; j < size-i-1; j++)
        {
            if (array[j] < array[j + 1])
                swap(&array[j], &array[j + 1]);
        }
}