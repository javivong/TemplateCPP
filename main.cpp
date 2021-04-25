#include <cstring> //string.h
#include <cstdio> //stdio.h
#include <cstdlib> //stdlib.h

#pragma region "Buffer Entrada"

static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof(stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount)
    {
        memmove(stdinBuffer, stdinPos, remaining);
        size_t sz = fread(stdinBuffer + remaining, 1, sizeof(stdinBuffer) - remaining, stdin);
        stdinPos = stdinBuffer;
        stdinDataEnd = stdinBuffer + remaining + sz;
        if (stdinDataEnd != stdinBuffer + sizeof(stdinBuffer))
            *stdinDataEnd = 0;
    }
}

#pragma endregion

#pragma region "Funciones de lectura"

long readLong()
{
    readAhead(16);

    long x = 0;
    bool neg = false;

    while (*stdinPos != 0 && *stdinPos != '-' && (*stdinPos < '0' || *stdinPos > '9'))
    {
        ++stdinPos;
    }

    if (*stdinPos == '-')
    {
        ++stdinPos;
        neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9')
    {
        x *= 10;
        x += *stdinPos - '0';
        ++stdinPos;
    }

    return neg ? -x : x;
}

int readInt()
{
    return (int)readLong();
}

float readFloat()
{
    readAhead(16);

    int entero = 0;
    float decimal = 0;
    bool neg = false;

    while (*stdinPos != 0 && *stdinPos != '-' && *stdinPos != '.' && (*stdinPos < '0' || *stdinPos > '9'))
    {
        ++stdinPos;
    }

    if (*stdinPos == '-')
    {
        ++stdinPos;
        neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9')
    {
        entero *= 10;
        entero += *stdinPos - '0';
        ++stdinPos;
    }
    if (*stdinPos == '.')
    {
        ++stdinPos;
        double factor = 1;
        while (*stdinPos >= '0' && *stdinPos <= '9')
        {
            factor /= 10.0;
            decimal += (*stdinPos - '0') * factor;
            ++stdinPos;
        }
    }
    return neg ? -(entero + decimal) : entero + decimal;
}

int readChar()
{
    readAhead(2);

    char res = *stdinPos;
    ++stdinPos;

    return res;
}

char* readString()
{
    char* string;
    int size = 0;
    readAhead(100);

    //Elimina posibles espacios al inicio
    while (*(stdinPos + size) == ' ' || *(stdinPos + size) == '\n')
    {
        stdinPos++;
    }

    while (*(stdinPos + size) != ' ' && *(stdinPos + size) != '\n')
    {
        size++;
    }

    string = (char*)malloc((size + 1) * sizeof(char));
    memcpy(string, stdinPos, size);
    *(string + size) = 0;
    stdinPos += size;

    return string;
}

#pragma endregion

int main()
{
    long num_casos = readLong();

    while (num_casos != 0)
    {
        printf("caso\n");
        num_casos--;
    }

    return 0;
}