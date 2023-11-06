#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/

    // Bubble sort
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            float p = (tr[j].a + tr[j].b + tr[j].c) / 2.0;
            float area = sqrt(p * (p - tr[j].a) * (p - tr[j].b) * (p - tr[j].c));
            float p1 = (tr[j+1].a + tr[j+1].b + tr[j+1].c) / 2.0;
            float area1 = sqrt(p1 * (p1 - tr[j+1].a) * (p1 - tr[j+1].b) * (p1 - tr[j+1].c));
            if (area > area1) {
                triangle temp = tr[j];
                tr[j] = tr[j+1];
                tr[j+1] = temp;
            }
        }
    }
    
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}