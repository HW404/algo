#include <stdio.h>
#include <windows.h> //system, sy 사용하게 해줌
#include <conio.h> //_getch 함수 사용하게 해줌

//#define 이름 값 -> 키보드 값 함수 
//키보드 키 값 정의
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4


//좌표값 받기
//커서를 지정항 좌표로 이동하는 함수
void gotoxy(int x, int y) //x, y 좌표 쓸 수 있게 해주는 함수 
{

    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//화면 클리어
void clsWin() {
	system("cls");
}

//키보드 입력 값 받아오기
int KeyControl()
{
    int key = _getch();

    if (key == 224)
    {
        int key = _getch();
        switch (key)
        {
        case 72:
            return UP;
        case 75:
            return LEFT;
        case 77:
            return RIGHT;
        case 80:
            return DOWN;
        }
    }

    else if (key == ' ') //스페이스바 (공백) 입력 받기
    {
        return SUBMIT;
    }
}

// 글자 색 변경 함수
void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
#define COLOR_DEFAULT 7 // 기본 흰색
#define COLOR_RED 12     // 빨강
#define COLOR_YELLOW 13     // 노랑
#define COLOR_BLUE 11     // 파랑


//메뉴 함수
int startMenuDraw() 
{
    int x = 70;
    int y = 20;
    gotoxy(x , y); //gotoxy(x좌표, y좌표) -> 적힌 좌표에 글씨 출력
    printf("> 시      작");
    gotoxy(x, y + 1);
    printf("  종      료");

    //무한반복하여 키 입력 처리
    while (1)
    {
        int n = KeyControl();
        switch (n) {

        case UP: {
            if (y > 20) {
                gotoxy(x , y);
                printf(" "); //원래 > 위치 지우기
                gotoxy(x , --y);
                printf(">"); //다시 그리기
            } 
            break;
        }

        case DOWN: {
            if (y < 21) {
                gotoxy(x , y);
                printf(" "); //원래 > 위치 지우기
                gotoxy(x , ++y);
                printf(">"); //다시 그리기
            }
            break;
        }

        case SUBMIT: {
            return y - 20; }

        }
    }
}

//시작화면
void start() {

    gotoxy(22, 10);
    printf("    :::     :::         ::::::::   ::::::::  :::::::::  ::::::::::: ::::::::::: :::    ::: ::::    :::::    \n");
    gotoxy(22, 11);
    printf("  :+: :+:   :+:        :+:    :+: :+:    :+: :+:    :+:     :+:         :+:     :+:    :+: +:+:+: :+:+:+    \n");
    gotoxy(22, 12);
    printf(" +:+   +:+  +:+        +:+        +:+    +:+ +:+    +:+     +:+         +:+     +:+    +:+ +:+ +:+:+ +:+    \n");
    gotoxy(22, 13);
    printf("+#++:++#++: +#+        :#:        +#+    +:+ +#++:++#:      +#+         +#+     +#++:++#++ +#+  +:+  +#+    \n");
    gotoxy(22, 14);
    printf("+#+     +#+ +#+        +#+   +#+# +#+    +#+ +#+    +#+     +#+         +#+     +#+    +#+ +#+       +#+    \n");
    gotoxy(22, 15);
    printf("#+#     #+# #+#        #+#    #+# #+#    #+# #+#    #+#     #+#         #+#     #+#    #+# #+#       #+#    \n");
    gotoxy(22, 16);
    printf("###     ### ##########  ########   ########  ###    ### ###########     ###     ###    ### ###       ###    \n");
}

//메뉴 함수
int goMenuDraw()
{
    int x = 110;
    int y = 30;
    gotoxy(x, y); //gotoxy(x좌표, y좌표) -> 적힌 좌표에 글씨 출력
    printf("> 뒤로가기");

    //무한반복하여 키 입력 처리
    while (1)
    {
        int n = KeyControl();
        switch (n) {
        case SUBMIT: {
            return y - 50; }

        }
    }
}

//알고리즘 선택 함수
int coiceAlgo0()
{
    gotoxy(5, 5);
    printf("알고싶은 알고리즘 카테고리를 선택하세요");
    gotoxy(5, 6);
    printf("방향키로 <위 아래> 키로 움직이고 <스페이스바> 키로 선택합니다.");

    int x = 30;
    int y = 20;
    gotoxy(x, y); //gotoxy(x좌표, y좌표) -> 적힌 좌표에 글씨 출력
    printf("> 정렬 알고리즘");
    gotoxy(x, y + 1);
    printf("  트리 알고리즘");
    gotoxy(x, y + 2);
    printf("  어쩌구 알고리즘");

    //무한반복
    //메뉴 선택과 관련된 처리
    while (1)
    {
        int n = KeyControl();
        switch (n) {

        case UP: {
            if (y > 20) {
                gotoxy(x, y);
                printf(" "); //원래 > 위치 지우기
                gotoxy(x, --y);
                printf(">"); //다시 그리기
            }
            break;
        }

        case DOWN: {
            if (y < 22) {
                gotoxy(x, y);
                printf(" "); //원래 > 위치 지우기
                gotoxy(x, ++y);
                printf(">"); //다시 그리기
            }
            break;
        }

        case SUBMIT: {
            return y - 20; }

        }
    }
}



//정렬알고리즘 선택 함수
int coiceAlgo1()
{
    gotoxy(5, 5);
    printf("알고싶은 정렬 알고리즘을 선택하세요");
    gotoxy(5, 6);
    printf("방향키로 <위 아래> 키로 움직이고 <스페이스바> 키로 선택합니다.");

    int x = 30;
    int y = 20;
    gotoxy(x, y); //gotoxy(x좌표, y좌표) -> 적힌 좌표에 글씨 출력
    printf("> 삽입정렬");
    gotoxy(x, y + 1);
    printf("  선택정렬");
    gotoxy(x, y + 2);
    printf("  버블정렬");
    gotoxy(x, y + 3);
    printf("  셀  정렬");
    gotoxy(x, y + 4);
    printf("  퀵  정렬");
    gotoxy(x, y + 5);
    printf("  힙  정렬");
    gotoxy(x, y + 6);
    printf("  합병정렬");
    gotoxy(x, y + 7);
    printf("  기수정렬");
    gotoxy(x, y + 8);
    printf("  계수정렬");
    gotoxy(x, y + 9);
    printf("  뒤로가기");

    //무한반복
    //메뉴 선택과 관련된 처리
    while (1)
    {
        int n = KeyControl();
        switch (n) {

        case UP: {
            if (y > 20) {
                gotoxy(x, y);
                printf(" "); //원래 > 위치 지우기
                gotoxy(x, --y);
                printf(">"); //다시 그리기
            }
            break;
        }

        case DOWN: {
            if (y < 29) {
                gotoxy(x, y);
                printf(" "); //원래 > 위치 지우기
                gotoxy(x, ++y);
                printf(">"); //다시 그리기
            }
            break;
        }

        case SUBMIT: {
            return y - 20; }

        }
    }
}

//트리알고리즘 선택 함수
int coiceAlgo2()
{
    gotoxy(5, 5);
    printf("알고싶은 정렬 알고리즘을 선택하세요");
    gotoxy(5, 6);
    printf("방향키로 <위 아래> 키로 움직이고 <스페이스바> 키로 선택합니다.");

    int x = 30;
    int y = 20;
    gotoxy(x, y); //gotoxy(x좌표, y좌표) -> 적힌 좌표에 글씨 출력
    printf("> 프림 알고리즘");
    gotoxy(x, y + 1);
    printf("  크루스칼 알고리즘");
    gotoxy(x, y + 2);
    printf("  뒤로가기");

    //무한반복
    //메뉴 선택과 관련된 처리
    while (1)
    {
        int n = KeyControl();
        switch (n) {

        case UP: {
            if (y > 20) {
                gotoxy(x, y);
                printf(" "); //원래 > 위치 지우기
                gotoxy(x, --y);
                printf(">"); //다시 그리기
            }
            break;
        }

        case DOWN: {
            if (y < 22) {
                gotoxy(x, y);
                printf(" "); //원래 > 위치 지우기
                gotoxy(x, ++y);
                printf(">"); //다시 그리기
            }
            break;
        }

        case SUBMIT: {
            return y - 20; }

        }
    }
}

//그래프알고리즘 선택 함수
int coiceAlgo3()
{
    gotoxy(5, 5);
    printf("알고싶은 정렬 알고리즘을 선택하세요");
    gotoxy(5, 6);
    printf("방향키로 <위 아래> 키로 움직이고 <스페이스바> 키로 선택합니다.");

    int x = 30;
    int y = 20;
    gotoxy(x, y); //gotoxy(x좌표, y좌표) -> 적힌 좌표에 글씨 출력
    printf(">  위상정렬");
    gotoxy(x, y + 1);
    printf("  최단경로");
    gotoxy(x, y + 2);
    printf("  뒤로가기");

    //무한반복
    //메뉴 선택과 관련된 처리
    while (1)
    {
        int n = KeyControl();
        switch (n) {

        case UP: {
            if (y > 20) {
                gotoxy(x, y);
                printf(" "); //원래 > 위치 지우기
                gotoxy(x, --y);
                printf(">"); //다시 그리기
            }
            break;
        }

        case DOWN: {
            if (y < 22) {
                gotoxy(x, y);
                printf(" "); //원래 > 위치 지우기
                gotoxy(x, ++y);
                printf(">"); //다시 그리기
            }
            break;
        }

        case SUBMIT: {
            return y - 20; }

        }
    }
}

// 삽입 정렬
void insertion_sort(int max, int list[]) {
    int key;

    //현재 배열 상태 출력
    gotoxy(10, 10);
    printf("현재 배열 : [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]");
    Sleep(1000);

    for (int i = 1; i < max; i++) {
        key = list[i];

        int j = i - 1;
        while (j >= 0 && list[j] > key) {
            list[j + 1] = list[j];
            j--;
        }

        list[j + 1] = key;

        //각 단계 출력
        gotoxy(10, 12 + i);
        printf("%d단계 : [ ", i);
        for (int j = 0; j < max; j++) {
            if (list[j]==key) {
                setTextColor(COLOR_RED); // 빨간색으로 변경
                printf("%d ", list[j]);
                setTextColor(COLOR_DEFAULT); // 원래색=하얀색으로 변경
            }
            else
                printf("%d ", list[j]);
        }
        printf("]");
        Sleep(1000); //시각화를 위해 잠시 대기
    }

    gotoxy(10, 10+max+3);
    printf("삽입 정렬된 배열 : [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]");
    //최종 정렬 결과 출력
    goMenuDraw();
    clsWin();
}
//선택 정렬
void selection_sort(int max, int list[]) {
    int k = 0;
    gotoxy(10, 10);
    printf("현재 배열 : [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]");
    Sleep(1000);

    for (int i = 0; i < max - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < max; j++) {
            if (list[j] < list[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            int temp = list[i];
            list[i] = list[min_index];
            list[min_index] = temp;
        }

        gotoxy(10, 12 + k);
        printf("%d단계 : [ ", k + 1);
        for (int j = 0; j < max; j++) {
            if (j == i || j == min_index) {
                setTextColor(COLOR_RED); // 빨간색으로 변경
                printf("%d ", list[j]);
                setTextColor(COLOR_DEFAULT); // 원래색=하얀색으로 변경
            }
            else
                printf("%d ", list[j]);
        }
        printf("]");
        k++;
        Sleep(1000);
    }


    //최종 정렬 결과 출력
    gotoxy(10, 10 + max + 3);
    printf("선택 정렬된 배열 : [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]");

    goMenuDraw();
    clsWin();
}
// 버블 정렬
void bubble_sort(int max, int list[]) {
    int k = 0;
    gotoxy(10, 10);
    printf("현재 배열 : [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]");
    Sleep(1000); 

    for (int i = max - 1; i > 0; i--) {
        int swapped = 0; // 교환이 발생했는지 여부를 나타내는 플래그
        int temp = 0;
        int a = 0;

        for (int j = 0; j < i; j++) {
            if (list[j] > list[j + 1]) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                swapped = 1; // 교환이 발생했음을 표시
            }

            if (swapped == 1)
            {
                gotoxy(10, 12 + k);
                printf("%d단계 : [ ", k + 1);
                for (int j = 0; j < max; j++) {
                    if (list[j] == temp) {
                        setTextColor(COLOR_RED); // 빨간색으로 변경
                        printf("%d ", list[j]);
                        setTextColor(COLOR_DEFAULT);
                    }
                    else if (list[j + 1] == temp) {
                        setTextColor(COLOR_RED); // 빨간색으로 변경
                        printf("%d ", list[j]);
                        setTextColor(COLOR_DEFAULT);
                    }
                    else {
                        printf("%d ", list[j]);
                    }
                }
                printf("]");
                k++;
                Sleep(1000);
            }
           
        }

        if (!swapped) {
            // 교환이 발생하지 않았으면 이미 정렬된 상태
            break;
        }
    }


    // 최종 정렬 결과 출력
    gotoxy(10, 10 + k + 3);
    printf("버블 정렬 (오름차순)된 배열 : [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]");

    goMenuDraw();
    clsWin();
}
//셀 정렬
void shell_sort(int max, int list[]) {
    int k = 0;
    int temp = 0;
    int a = 0;

    gotoxy(10, 10);
    printf("현재 배열 : [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]");
    Sleep(1000);

    int gap = max / 2; // 간격 초기값 설정

    while (gap > 0) {
        for (int i = gap; i < max; i++) {
            temp = list[i];
            int j = i;

            while (j >= gap && list[j - gap] > temp) {
                list[j] = list[j - gap];
                j -= gap;
            }

            list[j] = temp;
        }

        gotoxy(10, 12 + k);
        printf("%d번째 갭 : [ ", gap);
        for (int j = 0; j < max; j++) {
            if (list[j]==temp || list[j+ gap] == temp || list[j - gap] == temp) {
                setTextColor(COLOR_RED); // 빨간색으로 변경
                printf("%d ", list[j]);
                setTextColor(COLOR_DEFAULT); // 원래색=하얀색으로 변경
            }
            else if (list[j+1] == temp || list[j + gap +1] == temp || list[j - gap - 1 ] == temp) {
                setTextColor(COLOR_BLUE); // 빨간색으로 변경
                printf("%d ", list[j]);
                setTextColor(COLOR_DEFAULT); // 원래색=하얀색으로 변경
            }
            else if (list[j + 2] == temp || list[j + gap + 2] == temp || list[j - gap - 2] == temp) {
                setTextColor(COLOR_YELLOW); // 빨간색으로 변경
                printf("%d ", list[j]);
                setTextColor(COLOR_DEFAULT); // 원래색=하얀색으로 변경
            }
            else {
                printf("%d ", list[j]);
            }

        }
        printf("]");
        k++;
        Sleep(1000);

        gap /= 2; // 간격을 절반으로 줄임
    }

    // 최종 정렬 결과 출력
    gotoxy(10, 10 + k + 3);
    printf("셸 정렬 (오름차순)된 배열 : [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]");

    goMenuDraw();
    clsWin();
}
// 퀵 정렬
void quick(int list[], int low, int high) {
    if (low < high) {
        int pivot = list[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (list[j] <= pivot) {
                i++;
                // Swap list[i] and list[j]
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }

        // Swap list[i+1] and list[high] (pivot)
        int temp = list[i + 1];
        list[i + 1] = list[high];
        list[high] = temp;

        

        quick(list, low, i);      // 왼쪽 부분 배열에 대한 퀵 정렬
        quick(list, i + 2, high); // 오른쪽 부분 배열에 대한 퀵 정렬
    }
}
void quick_sort(int max, int list[]) {
    int i = 0;

    if (max > 1) {
        // 배열 출력
        gotoxy(10, 10);
        printf("현재 배열 : [ ");
        for (int j = 0; j < max; j++)
            printf("%d ", list[j]);
        printf("]");
        Sleep(1000);

        // 퀵 정렬 수행
        quick(list, 0, max - 1);

        // 결과 출력
        gotoxy(10, 12 + i);
        printf("%d단계 : [ ", i);
        for (int j = 0; j < max; j++) {
            printf("%d ", list[j]);
        }
        printf("]");
        Sleep(1000);

        i++;
    }

    // 최종 정렬 결과 출력
    gotoxy(10, 10 + max + 3);
    printf("퀵 정렬된 배열 : [ ");
    for (int j = 0; j < max; j++)
        printf("%d ", list[j]);
    printf("]");
    goMenuDraw();
    clsWin();
}
//힙 정렬
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heap_sort(int max, int list[]) {
    printf("현재 배열: [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]\n");

    // 힙 정렬
    for (int i = max / 2 - 1; i >= 0; i--)
        heapify(list, max, i);

    for (int i = max - 1; i > 0; i--) {
        swap(&list[0], &list[i]);
        heapify(list, i, 0);

        // 각 단계 출력
        printf("%d단계: [ ", max - i);
        for (int j = 0; j < max; j++) {
            if (j == 0 || j == i) {
                printf("%d ", list[j]);
            }
            else {
                printf("  ");
            }
        }
        printf("]\n");
    }

    // 최종 정렬 결과 출력
    printf("힙 정렬된 배열: [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]\n");
}
// 계수 정렬
void counting_sort(int list[], int size) {
    int max = list[0];
    int min = list[0];

    // 현재 배열 상태 출력
    gotoxy(10, 10);
    printf("현재 배열 : [ ");
    for (int j = 0; j < size; j++)
        printf("%d ", list[j]);
    printf("]");
    Sleep(1000);

    // 배열에서 최대값과 최소값 찾기
    for (int i = 1; i < size; i++) {
        if (list[i] > max)
            max = list[i];
        if (list[i] < min)
            min = list[i];
    }

    // 카운트 배열 초기화
    int range = max - min + 1;
    int* count = (int*)malloc(range * sizeof(int));
    int* output = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < range; i++)
        count[i] = 0;

    // 입력 배열의 각 원소를 세어 count 배열에 누적
    for (int i = 0; i < size; i++)
        count[list[i] - min]++;

    // count 배열을 누적합으로 업데이트
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // 입력 배열을 순회하며 정렬된 배열 생성
    for (int i = size - 1; i >= 0; i--) {
        output[count[list[i] - min] - 1] = list[i];
        count[list[i] - min]--;
    }

    // 정렬된 배열을 원래 배열에 복사
    for (int i = 0; i < size; i++)
        list[i] = output[i];

    free(count);
    free(output);

    gotoxy(10, 10 + size + 3);
    printf("계수 정렬된 배열 : [ ");
    for (int j = 0; j < size; j++)
        printf("%d ", list[j]);
    printf("]");
    // 최종 정렬 결과 출력
    goMenuDraw();
    clsWin();
}
// 기수 정렬
void radix_sort(int max, int list[]) {
    int maxNumber = max;
    int exp = 1;

    while (maxNumber / exp > 0) {
        int* output = (int*)malloc(max * sizeof(int));
        int count[10] = { 0 };

        for (int i = 0; i < max; i++)
            count[(list[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = max - 1; i >= 0; i--) {
            output[count[(list[i] / exp) % 10] - 1] = list[i];
            count[(list[i] / exp) % 10]--;
        }

        for (int i = 0; i < max; i++)
            list[i] = output[i];

        // 각 단계 출력
        gotoxy(10, 12);
        printf("%d단계 : [ ", exp);
        for (int j = 0; j < max; j++) {
            printf("%d ", list[j]);
        }
        printf("]");
        Sleep(1000);

        free(output);
        exp *= 10;
    }

    // 최종 정렬 결과 출력
    gotoxy(10, 12);
    printf("최종 정렬 결과 : [ ");
    for (int j = 0; j < max; j++) {
        printf("%d ", list[j]);
    }
    printf("]");
    Sleep(1000);
}
// 합병 정렬
void merge(int list[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = list[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = list[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            list[k] = L[i];
            i++;
        }
        else {
            list[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        list[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        list[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}
void merge_sort_recursive(int list[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // 왼쪽과 오른쪽 서브 배열을 나누어 각각 정렬
        merge_sort_recursive(list, left, mid);
        merge_sort_recursive(list, mid + 1, right);

        // 정렬된 서브 배열을 병합
        merge(list, left, mid, right);
    }
}
void merge_sort(int max, int list[]) {
    // 현재 배열 상태 출력
    gotoxy(10, 10);
    printf("현재 배열 : [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]");
    Sleep(1000);

    // 합병 정렬 수행
    merge_sort_recursive(list, 0, max - 1);

    // 최종 정렬 결과 출력
    gotoxy(10, 10 + max + 3);
    printf("합병 정렬된 배열 : [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]");
    // 최종 결과 출력
    goMenuDraw();
    clsWin();
}



int main() {

    system("mode con:cols=150 lines=40");
    //system("mode con cols=가로 lines=세로");

    int max;
    int list[100] = {0,};
    start();
    int startC = startMenuDraw();
    if (startC == 0) {

        while(true)
        {
            clsWin();

            int algoC = coiceAlgo0();
            //정렬 알고리즘
            if (algoC == 0) {
                clsWin();
                algoC = coiceAlgo1();

                //삽입정렬
                if (algoC == 0)
                {
                    clsWin();
                    gotoxy(10, 10);
                    printf("정렬할 배열의 크기를 입력하세요 (2이상 100이하) >> ");
                    scanf_s("%d", &max);

                    for (int i = 0; i < max; i++)
                    {
                        gotoxy(10, 12 + i);
                        printf("배열 %d번쨰 수를 입력하세요 : ", i);
                        scanf_s("%d", &list[i]);
                    }


                    Sleep(1000);
                    clsWin();
                    insertion_sort(max, list);
                }
                //선택정렬
                else if (algoC == 1)
                {
                    clsWin();
                    gotoxy(10, 10);
                    printf("정렬할 배열의 크기를 입력하세요 (2이상 100이하) >> ");
                    scanf_s("%d", &max);

                    for (int i = 0; i < max; i++)
                    {
                        gotoxy(10, 12 + i);
                        printf("배열 %d번쨰 수를 입력하세요 : ", i);
                        scanf_s("%d", &list[i]);
                    }


                    Sleep(1000);
                    clsWin();
                    selection_sort(max, list);
                }
                //버블정렬
                else if (algoC == 2)
                {
                    clsWin();
                    gotoxy(10, 10);
                    printf("정렬할 배열의 크기를 입력하세요 (2이상 100이하) >> ");
                    scanf_s("%d", &max);

                    for (int i = 0; i < max; i++)
                    {
                        gotoxy(10, 12 + i);
                        printf("배열 %d번쨰 수를 입력하세요 : ", i);
                        scanf_s("%d", &list[i]);
                    }


                    Sleep(1000);
                    clsWin();
                    bubble_sort(max, list);
                }
                //셀정렬
                else if (algoC == 3)
                {
                    clsWin();
                    gotoxy(10, 10);
                    printf("정렬할 배열의 크기를 입력하세요 (2이상 100이하) >> ");
                    scanf_s("%d", &max);

                    for (int i = 0; i < max; i++)
                    {
                        gotoxy(10, 12 + i);
                        printf("배열 %d번쨰 수를 입력하세요 : ", i);
                        scanf_s("%d", &list[i]);
                    }


                    Sleep(1000);
                    clsWin();
                    shell_sort(max, list);

                }
                //퀵정렬
                else if (algoC == 4)
                {
                    clsWin();
                    gotoxy(10, 10);
                    printf("정렬할 배열의 크기를 입력하세요 (2이상 100이하) >> ");
                    scanf_s("%d", &max);

                    for (int i = 0; i < max; i++)
                    {
                        gotoxy(10, 12 + i);
                        printf("배열 %d번쨰 수를 입력하세요 : ", i);
                        scanf_s("%d", &list[i]);
                    }


                    Sleep(1000);
                    clsWin();
                    quick_sort(max, list);

                }
                //힙 정렬
                else if (algoC == 5)
                {
                    clsWin();
                    gotoxy(10, 10);
                    printf("정렬할 배열의 크기를 입력하세요 (2이상 100이하) >> ");
                    scanf_s("%d", &max);

                    for (int i = 0; i < max; i++)
                    {
                        gotoxy(10, 12 + i);
                        printf("배열 %d번쨰 수를 입력하세요 : ", i);
                        scanf_s("%d", &list[i]);
                    }


                    Sleep(1000);
                    clsWin();
                    heap_sort(max, list);

                }
                //병합정렬
                else if (algoC == 6)
                {
                    clsWin();
                    gotoxy(10, 10);
                    printf("정렬할 배열의 크기를 입력하세요 (2이상 100이하) >> ");
                    scanf_s("%d", &max);

                    for (int i = 0; i < max; i++)
                    {
                        gotoxy(10, 12 + i);
                        printf("배열 %d번쨰 수를 입력하세요 : ", i);
                        scanf_s("%d", &list[i]);
                    }


                    Sleep(1000);
                    clsWin();
                    merge_sort(max, list);
                }
                //기수정렬
                else if (algoC == 7)
                {
                    clsWin();
                    gotoxy(10, 10);
                    printf("정렬할 배열의 크기를 입력하세요 (2이상 100이하) >> ");
                    scanf_s("%d", &max);

                    for (int i = 0; i < max; i++)
                    {
                        gotoxy(10, 12 + i);
                        printf("배열 %d번쨰 수를 입력하세요 : ", i);
                        scanf_s("%d", &list[i]);
                    }


                    Sleep(1000);
                    clsWin();
                    radix_sort(max, list);
                }
                //계수정렬3
                else if (algoC == 8)
                {
                    clsWin();
                    gotoxy(10, 10);
                    printf("정렬할 배열의 크기를 입력하세요 (2이상 100이하) >> ");
                    scanf_s("%d", &max);

                    for (int i = 0; i < max; i++)
                    {
                        gotoxy(10, 12 + i);
                        printf("배열 %d번쨰 수를 입력하세요 : ", i);
                        scanf_s("%d", &list[i]);
                    }


                    Sleep(1000);
                    clsWin();
                    counting_sort(list, max);
                }
                //뒤로가기
                else
                {

                }
            }
            //트리 알고리즘
            else if (algoC == 1) {
                clsWin();
                algoC = coiceAlgo2();
                if (algoC == 1) {

                }
                else if (algoC == 1) {

                }
                //뒤로가기
                else {

                }
            }
            //어쩌구 알고리즘
            else if (algoC == 2) {
                clsWin();
                algoC = coiceAlgo3();
                if (algoC == 1) {

                }
                else if (algoC == 1) {

                }
                //뒤로가기
                else {

                }
            }

            
        }

    }
    else if (startC == 1) {
        clsWin();
        printf("종료합니다...");
    }

    return 0;
}