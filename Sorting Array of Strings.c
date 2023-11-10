#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    for (; *a && *b && *a == *b; ++a, ++b)
        ;
    return *a - *b;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    for (; *a && *b && *a == *b; ++a, ++b)
        ;
    return *b - *a;
}

int sort_by_length(const char* a, const char* b) {
    int n = strlen(a), m = strlen(b);
    if (n == m) return lexicographic_sort(a, b);
    return n - m;
}

int distinct_characters(const char* s) {
    char* d_str = (char *) malloc(1);
    d_str[0] = '\0';
    for (int ctr = 0, i = 0; s[i]; ++i) {
        if (strchr(d_str, s[i]) == NULL) {
            d_str = realloc(d_str, strlen(d_str) + 2);
            d_str[ctr] = s[i];
            d_str[++ctr] = '\0';
        }
    }
    int d_chars = strlen(d_str);
    free(d_str);
    return d_chars;
}

int sort_by_number_of_distinct_characters(const char* a, 
                                          const char* b) {
    int x = distinct_characters(a), y = distinct_characters(b);
    if (x == y) return lexicographic_sort(a, b);
    return x - y;
}

void string_sort(char** arr, const int len, 
                 int (*cmp_func)(const char* a, 
                                 const char* b)) {
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (cmp_func(arr[i], arr[j]) > 0) {
                char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}