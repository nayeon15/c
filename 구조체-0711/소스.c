#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _bmi{
	char name[20];
	double height;
	double weight;
	double bmi;
}Bmi;

void calcBmi(Bmi *bmi) {
	bmi->bmi = bmi->weight / ((bmi->height/100) * (bmi->height/100));

}

int main()
{
	Bmi bmi;

	scanf("%s %lf %lf", &bmi.name, &bmi.height, &bmi.weight);
	calcBmi(&bmi);
	if (bmi.bmi < 25) printf("정상체중입니다");
	else if (bmi.bmi < 30) printf("과체중입니다");
	else printf("비만입니다");
}