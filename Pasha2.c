#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>

int main()
{
	double len1 = 0, len2 = 0, scal = 0;
	int ang = 0;

	scanf("%lf", &len1);
	scanf("%lf", &len2);
	scanf("%d", &ang);

	scal = abs(len1) * abs(len2) * cos(ang * 3.14 / 180);

	printf("%lf", scal);

	return 0;
}
