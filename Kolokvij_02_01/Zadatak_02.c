


#include <stdio.h>

int main()
{
    FILE *stream;
    unsigned char numbers[] = { 3, 5, 0, 7, 9 };
    unsigned char i, n;

    stream = fopen("stream", "w+");

    fwrite(numbers, sizeof(*numbers), 5, stream);


    fseek(stream,0, SEEK_SET);
    while (fread(&n, sizeof(n), 1, stream))
    {
        printf("%d ", n);
        fseek(stream, 1, SEEK_CUR);
    }
    putchar('\n');

    fseek(stream, 3, SEEK_SET);
    fread(numbers, sizeof(*numbers), 2, stream);
    for (i = 0; i < 5; i++)
    {
        printf("%d ", numbers[i]);
    }

    fclose(stream);
    return 0;
}
