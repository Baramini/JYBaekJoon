#include <windows.h>
#include <stdio.h>
#include <string.h> // string 함수 사용 라이브러리 추가

// 공백문자 X
int main()
{
    // 선언 '동시' 초기화 (1) → 원칙 X: 배열크기 ≤ 초기화 변수 갯수
    printf("---원칙 X---\n");
    char X[2] = {'A', 'B', 'C', 'D', '\0'};          // char X[2] = "ABCD\0";  
                                                     // 배열의 크기 2 ≤ 초기화 변수 갯수 4 + 1(\0=null 문자 생성 메모리박스 공간)
    printf("%s\n", X);                               // %s → 문자'열' 출력:  정상출력 X(예: AB 출력 X  AB쓰레기값 출력 O)
    printf("%c %c %c %c\n", X[0], X[1], X[2], X[3]); // 정상출력 X(예: A B 출력 X  A B 쓰레기값 출력 O)
    printf("%d\n", strlen(X));                       // %d → 문자'열' 길이(strlen = string length) 출력  → \0=null 문자 전까지 길이 출력
    printf("<%c>\n", X[5]);                          // \0=null 문자 앞까지 길이 출력

    // 선언 '동시' 초기화 (1) → 수정: 권장방식 X 
    printf("---수 정---\n");
    char Y[2] = {'A', 'B', 'C', 'D'};  // 배열의 크기 2 ≤ 초기화 변수 갯수 4 + 1(\0=null 문자 생성 메모리박스 공간)
    Y[2] = '\0';                       // 배열 2번째자리에 \0=null 문자 입력/저장 → 배열끝 강제 생성
    printf("%s\n", Y);                 // %s → 문자'열' 출력:  정상출력 O(예: AB 출력 O)
    printf("%c %c\n", Y[0], Y[1]);     // 정상 출력 O(예: A B 출력 O)
    printf("%d\n", strlen(Y));         // %d → 문자'열' 길이(strlen = string length) 출력  →  \0=null 문자 전까지 길이 출력
    printf("<%c>\n", Y[2]);            // \0=null 문자 앞까지 길이 출력

    // 선언 '후' 초기화 → 원칙 X: 배열크기 ≤ 초기화 변수 갯수
    printf("---원칙 X---\n");
    char Z[2];
    printf("---입력---\n");
    scanf("%s", &Z);                   // 예: ABCD 입력/저장  →  배열의 크기 2 ≤ 초기화 변수 갯수 4 + 1(\0=null 문자 생성 메모리박스 공간)
    printf("---출력---\n");
    printf("%s\n", Z);                 // %s → 문자'열' 출력:  정상출력처럼 보임 → 정상 출력 X:  ABCD 출력 
    printf("%c %c %c %c\n", Z[0], Z[1], Z[2], Z[3]); // 정상출력처럼 보임 → 정상 출력 X:  A B C D 출력 
    printf("%d\n", strlen(Z));         // %d → 문자'열' 길이(strlen = string length) 출력  → \0=null 문자 전까지 길이 출력
    printf("<%c>\n", Z[4]);            // \0=null 문자 생성 위치 
    
    system("pause");
    return 0;
}   
 