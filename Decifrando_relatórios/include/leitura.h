#ifndef leitura_h
#define leitura_h
#define MAX 7

typedef struct {
    char first_word[9];
    char second_word[9];
    char third_word[9];
} words;

void read_archive(const char *archive, words *leitura);
int validation_letters(words **leitura, char *unique_letters);

#endif