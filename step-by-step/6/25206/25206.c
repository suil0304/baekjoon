#include <stdio.h>
#include <string.h>

float gradeScore(char* grade);

int main() {
    float sum = 0;
    float scoreAll = 0;
    for(int i = 0; i < 20; i++) {
        char subjectName[51];
        float subjectScore;
        char subjectGrade[3];
        scanf(" %s %f %s", subjectName, &subjectScore, subjectGrade);

        if(strcmp(subjectGrade, "P") == 0) {
            continue;
        }

        float curGradeScore;
        curGradeScore = gradeScore(subjectGrade);

        sum += subjectScore * curGradeScore;
        scoreAll += subjectScore;
    }

    printf("%f", sum / scoreAll);

    return 0;
}

float gradeScore(char* grade) {
    float score = 0;
    
    if(strcmp(grade, "A+") == 0) {
        score = 4.5;
    }
    else if(strcmp(grade, "A0") == 0) {
        score = 4.0;
    }
    else if(strcmp(grade, "B+") == 0) {
        score = 3.5;
    }
    else if(strcmp(grade, "B0") == 0) {
        score = 3.0;
    }
    else if(strcmp(grade, "C+") == 0) {
        score = 2.5;
    }
    else if(strcmp(grade, "C0") == 0) {
        score = 2.0;
    }
    else if(strcmp(grade, "D+") == 0) {
        score = 1.5;
    }
    else if(strcmp(grade, "D0") == 0) {
        score = 1.0;
    }

    return score;
}