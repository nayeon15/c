
#include <stdio.h>
#include<stdlib.h>

typedef struct {
	int sno;
	char name[20];
	int score;
	int amt;
}Student; 

void input_student(int n, Student* dsm_student) {
	int i = 0;

	while (i < n) {
		scanf("%d %s %d", &dsm_student[i].sno, &dsm_student[i].name, &dsm_student[i].score);
		i++;
	}
}
void input_amt(int n, Student* dsm_student) {
	int max = 0, count = 0;
	for (int i = 0; i < n; i++) {
		if (max < dsm_student[i].score) {
			max = dsm_student[i].score; count = i;
		}
		dsm_student[i].amt = 0;
	}
	dsm_student[count].amt = 100;
}
void print_student(int n, Student* dsm_student) {
	for (int i = 0; i < n; i++) {
		printf("%d %s %d %d\n", dsm_student[i].sno, dsm_student[i].name, dsm_student[i].score, dsm_student[i].amt);
	}
}

int main() {
	Student* dsm_student;
	int n;

	scanf("%d", &n);

	dsm_student = (Student*)malloc(sizeof(Student) * n);
	input_student(n, &dsm_student);
	input_amt(n, &dsm_student);
	print_student(n, &dsm_student);

	free(dsm_student);
}