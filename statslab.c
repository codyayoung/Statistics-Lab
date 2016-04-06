// Statistics Lab
// Performs grade calcuations with given data sets.
// Palomar ID: 008372648
// Cody Young

#include <stdio.h>
#include <stdlib.h>
#define max 30

void formatarray(int scores[6][5]);
void freqchart(int scores[6][5]);
void failpass(int scores[6][5]);
void meanscores(int scores[6][5]);
void modescores(int scores[6][5]);
void medianscores(int scores[6][5]);
int compare(const void*a, const void*b);

int main(void) {

	int scores[6][5] = {					//Initial test score array
		{ 90,85,100,50,50 },
		{ 85,60,70,55,55 },
		{ 80,95,70,60,95 },
		{ 80,100,75,70,95 },
		{ 90,90,70,95,50 },
		{ 65,85,95,100,65 } 
	};
	

	printf("Grades\n");
	printf("%-5s", "------\n");
	qsort(scores, max, sizeof(int), compare);
	formatarray(scores);
	printf("\n");
	freqchart(scores);
	printf("\n");
	failpass(scores);
	printf("\n");
	meanscores(scores);
	printf("\n");
	modescores(scores);
	printf("\n");
	medianscores(scores);
	
	getchar();
	return 0;
}

void formatarray(int scores[6][5]) {	//Prints formatted array
	int i, j;
	for (i = 0; i < 6; ++i) {
		for (j = 0; j < 5; ++j)
		{
			printf("%-5i", scores[i][j]);
		}
		printf("\n");
	}
}

int compare(const void*a, const void*b) { //For qsort function
	if (*(int *)a < *(int *)b) {
		return -1;
	}
	return *(int *)a > *(int *)b;
}

void freqchart(int scores[6][5]) {	//Outputs frequency chart
	int i, j;
	int freqval[11] = { 100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50 }; // Bin values
	int freqct[11] = { 0 };		// Array for bin counts

	for (i = 0; i < 6; ++i) {	// Loop to count score frequencies
		for (j = 0; j < 5; ++j)
			if (scores[i][j] == 100) {
				freqct[0]++;
			}
			else if (scores[i][j] == 95) {
				freqct[1]++;
			}
			else if (scores[i][j] == 90) {
				freqct[2]++;
			}
			else if (scores[i][j] == 85) {
				freqct[3]++;
			}
			else if (scores[i][j] == 80) {
				freqct[4]++;
			}
			else if (scores[i][j] == 75) {
				freqct[5]++;
			}
			else if (scores[i][j] == 70) {
				freqct[6]++;
			}
			else if (scores[i][j] == 65) {
				freqct[7]++;
			}
			else if (scores[i][j] == 60) {
				freqct[8]++;
			}
			else if (scores[i][j] == 55) {
				freqct[9]++;
			}
			else if (scores[i][j] == 50) {
				freqct[10]++;
			}
	}
	printf("%-5s" "%20s", "Score", "Frequency\n");
	printf("%-5s" "%20s", "----", "---------\n");
	for (i = 0; i< 11; i++) {
		printf("%-5i" "%15i\n", freqval[i], freqct[i]);
	}
}
void failpass(int scores[6][5]) { //Outputs percentage of passing and failing scores
	int i, j;
	int totalscores = 30;
	double count_fail = 0, count_pass = 0;		//Variable to count scores
	double perpass = 0, perfail = 0;		//Percentage of fail/pass scores

	for (i = 0; i < 6; ++i) {
		for (j = 0; j < 5; ++j) {
			if (scores[i][j] < 60) {
				count_fail += 1;
			}
			else if (scores[i][j] > 60) {
				count_pass += 1;
			}
		}
	}
	perpass = count_pass / totalscores;
	perfail = count_fail / totalscores;
	printf("Percentage of passed scores: %.2lf\n", perpass);
	printf("Percentage of failed scores: %.2lf", perfail);

}

void meanscores(int scores[6][5]) {		//Outputs mean of test scores
	int i, j;
	int totalscores = 30;
	int sum = 0;
	double mean = 0;

	for (i = 0; i < 6; ++i) {
		for (j = 0; j < 5; ++j)
		{
			sum += scores[i][j];
		}
	}
	mean = sum / totalscores;
	printf("Mean: %.2lf", mean);
}

void modescores(int scores[6][5]) {		//Outputs most common test score
	int i, j;
	int num = scores[6][5];
	int mode = num;
	int count = 1;
	int countmode = 1;

	for (i = 0; i < 6; ++i) {
		for (j = 0; j < 5; ++j)
			if (scores[i][j] == 100) {
				count++;
			}
			else
			{
				if (countmode > count)
				{
					count = countmode;
					mode = num;
				}
				count = 1;
				num = scores[i][j];
			}
	}
		printf("Mode: %i", num);
}

void medianscores(int scores[6][5]) {	//Outputs middle value in array. Checks for even or odd # of array elements
	int i, j;
	int count = 0;	//Number of items in array
	int median = 0;
	for (i = 0; i < 6; ++i) {
		for (j = 0; j < 5; ++j) {
			count++;
		}
	}							//Need to fix this function
	if (count % 2 == 0) {		//If even number, median = sum of two middle numbers/2
		median = (scores[i / 2][j / 2] + scores[i / 2 + 1][j/2+1]) / 2;
	}
	else {						//If odd number, median = middle number
		median = scores[i / 2][j / 2] + 1;
	}
	printf("Median: %i", median);
}