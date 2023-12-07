#include <stdio.h>
#include <windows.h> //system, sy ����ϰ� ����
#include <conio.h> //_getch �Լ� ����ϰ� ����

//#define �̸� �� -> Ű���� �� �Լ� 
//Ű���� Ű �� ����
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4


//��ǥ�� �ޱ�
//Ŀ���� ������ ��ǥ�� �̵��ϴ� �Լ�
void gotoxy(int x, int y) //x, y ��ǥ �� �� �ְ� ���ִ� �Լ� 
{

    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//ȭ�� Ŭ����
void clsWin() {
	system("cls");
}

//Ű���� �Է� �� �޾ƿ���
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

    else if (key == ' ') //�����̽��� (����) �Է� �ޱ�
    {
        return SUBMIT;
    }
}

// ���� �� ���� �Լ�
void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
#define COLOR_DEFAULT 7 // �⺻ ���
#define COLOR_RED 12     // ����
#define COLOR_YELLOW 13     // ���
#define COLOR_BLUE 11     // �Ķ�


//�޴� �Լ�
int startMenuDraw() 
{
    int x = 70;
    int y = 20;
    gotoxy(x , y); //gotoxy(x��ǥ, y��ǥ) -> ���� ��ǥ�� �۾� ���
    printf("> ��      ��");
    gotoxy(x, y + 1);
    printf("  ��      ��");

    //���ѹݺ��Ͽ� Ű �Է� ó��
    while (1)
    {
        int n = KeyControl();
        switch (n) {

        case UP: {
            if (y > 20) {
                gotoxy(x , y);
                printf(" "); //���� > ��ġ �����
                gotoxy(x , --y);
                printf(">"); //�ٽ� �׸���
            } 
            break;
        }

        case DOWN: {
            if (y < 21) {
                gotoxy(x , y);
                printf(" "); //���� > ��ġ �����
                gotoxy(x , ++y);
                printf(">"); //�ٽ� �׸���
            }
            break;
        }

        case SUBMIT: {
            return y - 20; }

        }
    }
}

//����ȭ��
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

//�޴� �Լ�
int goMenuDraw()
{
    int x = 110;
    int y = 30;
    gotoxy(x, y); //gotoxy(x��ǥ, y��ǥ) -> ���� ��ǥ�� �۾� ���
    printf("> �ڷΰ���");

    //���ѹݺ��Ͽ� Ű �Է� ó��
    while (1)
    {
        int n = KeyControl();
        switch (n) {
        case SUBMIT: {
            return y - 50; }

        }
    }
}

//�˰��� ���� �Լ�
int coiceAlgo0()
{
    gotoxy(5, 5);
    printf("�˰���� �˰��� ī�װ��� �����ϼ���");
    gotoxy(5, 6);
    printf("����Ű�� <�� �Ʒ�> Ű�� �����̰� <�����̽���> Ű�� �����մϴ�.");

    int x = 30;
    int y = 20;
    gotoxy(x, y); //gotoxy(x��ǥ, y��ǥ) -> ���� ��ǥ�� �۾� ���
    printf("> ���� �˰���");
    gotoxy(x, y + 1);
    printf("  Ʈ�� �˰���");
    gotoxy(x, y + 2);
    printf("  ��¼�� �˰���");

    //���ѹݺ�
    //�޴� ���ð� ���õ� ó��
    while (1)
    {
        int n = KeyControl();
        switch (n) {

        case UP: {
            if (y > 20) {
                gotoxy(x, y);
                printf(" "); //���� > ��ġ �����
                gotoxy(x, --y);
                printf(">"); //�ٽ� �׸���
            }
            break;
        }

        case DOWN: {
            if (y < 22) {
                gotoxy(x, y);
                printf(" "); //���� > ��ġ �����
                gotoxy(x, ++y);
                printf(">"); //�ٽ� �׸���
            }
            break;
        }

        case SUBMIT: {
            return y - 20; }

        }
    }
}



//���ľ˰��� ���� �Լ�
int coiceAlgo1()
{
    gotoxy(5, 5);
    printf("�˰���� ���� �˰����� �����ϼ���");
    gotoxy(5, 6);
    printf("����Ű�� <�� �Ʒ�> Ű�� �����̰� <�����̽���> Ű�� �����մϴ�.");

    int x = 30;
    int y = 20;
    gotoxy(x, y); //gotoxy(x��ǥ, y��ǥ) -> ���� ��ǥ�� �۾� ���
    printf("> ��������");
    gotoxy(x, y + 1);
    printf("  ��������");
    gotoxy(x, y + 2);
    printf("  ��������");
    gotoxy(x, y + 3);
    printf("  ��  ����");
    gotoxy(x, y + 4);
    printf("  ��  ����");
    gotoxy(x, y + 5);
    printf("  ��  ����");
    gotoxy(x, y + 6);
    printf("  �պ�����");
    gotoxy(x, y + 7);
    printf("  �������");
    gotoxy(x, y + 8);
    printf("  �������");
    gotoxy(x, y + 9);
    printf("  �ڷΰ���");

    //���ѹݺ�
    //�޴� ���ð� ���õ� ó��
    while (1)
    {
        int n = KeyControl();
        switch (n) {

        case UP: {
            if (y > 20) {
                gotoxy(x, y);
                printf(" "); //���� > ��ġ �����
                gotoxy(x, --y);
                printf(">"); //�ٽ� �׸���
            }
            break;
        }

        case DOWN: {
            if (y < 29) {
                gotoxy(x, y);
                printf(" "); //���� > ��ġ �����
                gotoxy(x, ++y);
                printf(">"); //�ٽ� �׸���
            }
            break;
        }

        case SUBMIT: {
            return y - 20; }

        }
    }
}

//Ʈ���˰��� ���� �Լ�
int coiceAlgo2()
{
    gotoxy(5, 5);
    printf("�˰���� ���� �˰����� �����ϼ���");
    gotoxy(5, 6);
    printf("����Ű�� <�� �Ʒ�> Ű�� �����̰� <�����̽���> Ű�� �����մϴ�.");

    int x = 30;
    int y = 20;
    gotoxy(x, y); //gotoxy(x��ǥ, y��ǥ) -> ���� ��ǥ�� �۾� ���
    printf("> ���� �˰���");
    gotoxy(x, y + 1);
    printf("  ũ�罺Į �˰���");
    gotoxy(x, y + 2);
    printf("  �ڷΰ���");

    //���ѹݺ�
    //�޴� ���ð� ���õ� ó��
    while (1)
    {
        int n = KeyControl();
        switch (n) {

        case UP: {
            if (y > 20) {
                gotoxy(x, y);
                printf(" "); //���� > ��ġ �����
                gotoxy(x, --y);
                printf(">"); //�ٽ� �׸���
            }
            break;
        }

        case DOWN: {
            if (y < 22) {
                gotoxy(x, y);
                printf(" "); //���� > ��ġ �����
                gotoxy(x, ++y);
                printf(">"); //�ٽ� �׸���
            }
            break;
        }

        case SUBMIT: {
            return y - 20; }

        }
    }
}

//�׷����˰��� ���� �Լ�
int coiceAlgo3()
{
    gotoxy(5, 5);
    printf("�˰���� ���� �˰����� �����ϼ���");
    gotoxy(5, 6);
    printf("����Ű�� <�� �Ʒ�> Ű�� �����̰� <�����̽���> Ű�� �����մϴ�.");

    int x = 30;
    int y = 20;
    gotoxy(x, y); //gotoxy(x��ǥ, y��ǥ) -> ���� ��ǥ�� �۾� ���
    printf(">  ��������");
    gotoxy(x, y + 1);
    printf("  �ִܰ��");
    gotoxy(x, y + 2);
    printf("  �ڷΰ���");

    //���ѹݺ�
    //�޴� ���ð� ���õ� ó��
    while (1)
    {
        int n = KeyControl();
        switch (n) {

        case UP: {
            if (y > 20) {
                gotoxy(x, y);
                printf(" "); //���� > ��ġ �����
                gotoxy(x, --y);
                printf(">"); //�ٽ� �׸���
            }
            break;
        }

        case DOWN: {
            if (y < 22) {
                gotoxy(x, y);
                printf(" "); //���� > ��ġ �����
                gotoxy(x, ++y);
                printf(">"); //�ٽ� �׸���
            }
            break;
        }

        case SUBMIT: {
            return y - 20; }

        }
    }
}

// ���� ����
void insertion_sort(int max, int list[]) {
    int key;

    //���� �迭 ���� ���
    gotoxy(10, 10);
    printf("���� �迭 : [ ");
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

        //�� �ܰ� ���
        gotoxy(10, 12 + i);
        printf("%d�ܰ� : [ ", i);
        for (int j = 0; j < max; j++) {
            if (list[j]==key) {
                setTextColor(COLOR_RED); // ���������� ����
                printf("%d ", list[j]);
                setTextColor(COLOR_DEFAULT); // ������=�Ͼ������ ����
            }
            else
                printf("%d ", list[j]);
        }
        printf("]");
        Sleep(1000); //�ð�ȭ�� ���� ��� ���
    }

    gotoxy(10, 10+max+3);
    printf("���� ���ĵ� �迭 : [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]");
    //���� ���� ��� ���
    goMenuDraw();
    clsWin();
}
//���� ����
void selection_sort(int max, int list[]) {
    int k = 0;
    gotoxy(10, 10);
    printf("���� �迭 : [ ");
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
        printf("%d�ܰ� : [ ", k + 1);
        for (int j = 0; j < max; j++) {
            if (j == i || j == min_index) {
                setTextColor(COLOR_RED); // ���������� ����
                printf("%d ", list[j]);
                setTextColor(COLOR_DEFAULT); // ������=�Ͼ������ ����
            }
            else
                printf("%d ", list[j]);
        }
        printf("]");
        k++;
        Sleep(1000);
    }


    //���� ���� ��� ���
    gotoxy(10, 10 + max + 3);
    printf("���� ���ĵ� �迭 : [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]");

    goMenuDraw();
    clsWin();
}
// ���� ����
void bubble_sort(int max, int list[]) {
    int k = 0;
    gotoxy(10, 10);
    printf("���� �迭 : [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]");
    Sleep(1000); 

    for (int i = max - 1; i > 0; i--) {
        int swapped = 0; // ��ȯ�� �߻��ߴ��� ���θ� ��Ÿ���� �÷���
        int temp = 0;
        int a = 0;

        for (int j = 0; j < i; j++) {
            if (list[j] > list[j + 1]) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                swapped = 1; // ��ȯ�� �߻������� ǥ��
            }

            if (swapped == 1)
            {
                gotoxy(10, 12 + k);
                printf("%d�ܰ� : [ ", k + 1);
                for (int j = 0; j < max; j++) {
                    if (list[j] == temp) {
                        setTextColor(COLOR_RED); // ���������� ����
                        printf("%d ", list[j]);
                        setTextColor(COLOR_DEFAULT);
                    }
                    else if (list[j + 1] == temp) {
                        setTextColor(COLOR_RED); // ���������� ����
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
            // ��ȯ�� �߻����� �ʾ����� �̹� ���ĵ� ����
            break;
        }
    }


    // ���� ���� ��� ���
    gotoxy(10, 10 + k + 3);
    printf("���� ���� (��������)�� �迭 : [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]");

    goMenuDraw();
    clsWin();
}
//�� ����
void shell_sort(int max, int list[]) {
    int k = 0;
    int temp = 0;
    int a = 0;

    gotoxy(10, 10);
    printf("���� �迭 : [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]");
    Sleep(1000);

    int gap = max / 2; // ���� �ʱⰪ ����

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
        printf("%d��° �� : [ ", gap);
        for (int j = 0; j < max; j++) {
            if (list[j]==temp || list[j+ gap] == temp || list[j - gap] == temp) {
                setTextColor(COLOR_RED); // ���������� ����
                printf("%d ", list[j]);
                setTextColor(COLOR_DEFAULT); // ������=�Ͼ������ ����
            }
            else if (list[j+1] == temp || list[j + gap +1] == temp || list[j - gap - 1 ] == temp) {
                setTextColor(COLOR_BLUE); // ���������� ����
                printf("%d ", list[j]);
                setTextColor(COLOR_DEFAULT); // ������=�Ͼ������ ����
            }
            else if (list[j + 2] == temp || list[j + gap + 2] == temp || list[j - gap - 2] == temp) {
                setTextColor(COLOR_YELLOW); // ���������� ����
                printf("%d ", list[j]);
                setTextColor(COLOR_DEFAULT); // ������=�Ͼ������ ����
            }
            else {
                printf("%d ", list[j]);
            }

        }
        printf("]");
        k++;
        Sleep(1000);

        gap /= 2; // ������ �������� ����
    }

    // ���� ���� ��� ���
    gotoxy(10, 10 + k + 3);
    printf("�� ���� (��������)�� �迭 : [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]");

    goMenuDraw();
    clsWin();
}
// �� ����
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

        

        quick(list, low, i);      // ���� �κ� �迭�� ���� �� ����
        quick(list, i + 2, high); // ������ �κ� �迭�� ���� �� ����
    }
}
void quick_sort(int max, int list[]) {
    int i = 0;

    if (max > 1) {
        // �迭 ���
        gotoxy(10, 10);
        printf("���� �迭 : [ ");
        for (int j = 0; j < max; j++)
            printf("%d ", list[j]);
        printf("]");
        Sleep(1000);

        // �� ���� ����
        quick(list, 0, max - 1);

        // ��� ���
        gotoxy(10, 12 + i);
        printf("%d�ܰ� : [ ", i);
        for (int j = 0; j < max; j++) {
            printf("%d ", list[j]);
        }
        printf("]");
        Sleep(1000);

        i++;
    }

    // ���� ���� ��� ���
    gotoxy(10, 10 + max + 3);
    printf("�� ���ĵ� �迭 : [ ");
    for (int j = 0; j < max; j++)
        printf("%d ", list[j]);
    printf("]");
    goMenuDraw();
    clsWin();
}
//�� ����
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
    printf("���� �迭: [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]\n");

    // �� ����
    for (int i = max / 2 - 1; i >= 0; i--)
        heapify(list, max, i);

    for (int i = max - 1; i > 0; i--) {
        swap(&list[0], &list[i]);
        heapify(list, i, 0);

        // �� �ܰ� ���
        printf("%d�ܰ�: [ ", max - i);
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

    // ���� ���� ��� ���
    printf("�� ���ĵ� �迭: [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]\n");
}
// ��� ����
void counting_sort(int list[], int size) {
    int max = list[0];
    int min = list[0];

    // ���� �迭 ���� ���
    gotoxy(10, 10);
    printf("���� �迭 : [ ");
    for (int j = 0; j < size; j++)
        printf("%d ", list[j]);
    printf("]");
    Sleep(1000);

    // �迭���� �ִ밪�� �ּҰ� ã��
    for (int i = 1; i < size; i++) {
        if (list[i] > max)
            max = list[i];
        if (list[i] < min)
            min = list[i];
    }

    // ī��Ʈ �迭 �ʱ�ȭ
    int range = max - min + 1;
    int* count = (int*)malloc(range * sizeof(int));
    int* output = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < range; i++)
        count[i] = 0;

    // �Է� �迭�� �� ���Ҹ� ���� count �迭�� ����
    for (int i = 0; i < size; i++)
        count[list[i] - min]++;

    // count �迭�� ���������� ������Ʈ
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // �Է� �迭�� ��ȸ�ϸ� ���ĵ� �迭 ����
    for (int i = size - 1; i >= 0; i--) {
        output[count[list[i] - min] - 1] = list[i];
        count[list[i] - min]--;
    }

    // ���ĵ� �迭�� ���� �迭�� ����
    for (int i = 0; i < size; i++)
        list[i] = output[i];

    free(count);
    free(output);

    gotoxy(10, 10 + size + 3);
    printf("��� ���ĵ� �迭 : [ ");
    for (int j = 0; j < size; j++)
        printf("%d ", list[j]);
    printf("]");
    // ���� ���� ��� ���
    goMenuDraw();
    clsWin();
}
// ��� ����
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

        // �� �ܰ� ���
        gotoxy(10, 12);
        printf("%d�ܰ� : [ ", exp);
        for (int j = 0; j < max; j++) {
            printf("%d ", list[j]);
        }
        printf("]");
        Sleep(1000);

        free(output);
        exp *= 10;
    }

    // ���� ���� ��� ���
    gotoxy(10, 12);
    printf("���� ���� ��� : [ ");
    for (int j = 0; j < max; j++) {
        printf("%d ", list[j]);
    }
    printf("]");
    Sleep(1000);
}
// �պ� ����
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

        // ���ʰ� ������ ���� �迭�� ������ ���� ����
        merge_sort_recursive(list, left, mid);
        merge_sort_recursive(list, mid + 1, right);

        // ���ĵ� ���� �迭�� ����
        merge(list, left, mid, right);
    }
}
void merge_sort(int max, int list[]) {
    // ���� �迭 ���� ���
    gotoxy(10, 10);
    printf("���� �迭 : [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]");
    Sleep(1000);

    // �պ� ���� ����
    merge_sort_recursive(list, 0, max - 1);

    // ���� ���� ��� ���
    gotoxy(10, 10 + max + 3);
    printf("�պ� ���ĵ� �迭 : [ ");
    for (int i = 0; i < max; i++)
        printf("%d ", list[i]);
    printf("]");
    // ���� ��� ���
    goMenuDraw();
    clsWin();
}



int main() {

    system("mode con:cols=150 lines=40");
    //system("mode con cols=���� lines=����");

    int max;
    int list[100] = {0,};
    start();
    int startC = startMenuDraw();
    if (startC == 0) {

        while(true)
        {
            clsWin();

            int algoC = coiceAlgo0();
            //���� �˰���
            if (algoC == 0) {
                clsWin();
                algoC = coiceAlgo1();

                //��������
                if (algoC == 0)
                {
                    clsWin();
                    gotoxy(10, 10);
                    printf("������ �迭�� ũ�⸦ �Է��ϼ��� (2�̻� 100����) >> ");
                    scanf_s("%d", &max);

                    for (int i = 0; i < max; i++)
                    {
                        gotoxy(10, 12 + i);
                        printf("�迭 %d���� ���� �Է��ϼ��� : ", i);
                        scanf_s("%d", &list[i]);
                    }


                    Sleep(1000);
                    clsWin();
                    insertion_sort(max, list);
                }
                //��������
                else if (algoC == 1)
                {
                    clsWin();
                    gotoxy(10, 10);
                    printf("������ �迭�� ũ�⸦ �Է��ϼ��� (2�̻� 100����) >> ");
                    scanf_s("%d", &max);

                    for (int i = 0; i < max; i++)
                    {
                        gotoxy(10, 12 + i);
                        printf("�迭 %d���� ���� �Է��ϼ��� : ", i);
                        scanf_s("%d", &list[i]);
                    }


                    Sleep(1000);
                    clsWin();
                    selection_sort(max, list);
                }
                //��������
                else if (algoC == 2)
                {
                    clsWin();
                    gotoxy(10, 10);
                    printf("������ �迭�� ũ�⸦ �Է��ϼ��� (2�̻� 100����) >> ");
                    scanf_s("%d", &max);

                    for (int i = 0; i < max; i++)
                    {
                        gotoxy(10, 12 + i);
                        printf("�迭 %d���� ���� �Է��ϼ��� : ", i);
                        scanf_s("%d", &list[i]);
                    }


                    Sleep(1000);
                    clsWin();
                    bubble_sort(max, list);
                }
                //������
                else if (algoC == 3)
                {
                    clsWin();
                    gotoxy(10, 10);
                    printf("������ �迭�� ũ�⸦ �Է��ϼ��� (2�̻� 100����) >> ");
                    scanf_s("%d", &max);

                    for (int i = 0; i < max; i++)
                    {
                        gotoxy(10, 12 + i);
                        printf("�迭 %d���� ���� �Է��ϼ��� : ", i);
                        scanf_s("%d", &list[i]);
                    }


                    Sleep(1000);
                    clsWin();
                    shell_sort(max, list);

                }
                //������
                else if (algoC == 4)
                {
                    clsWin();
                    gotoxy(10, 10);
                    printf("������ �迭�� ũ�⸦ �Է��ϼ��� (2�̻� 100����) >> ");
                    scanf_s("%d", &max);

                    for (int i = 0; i < max; i++)
                    {
                        gotoxy(10, 12 + i);
                        printf("�迭 %d���� ���� �Է��ϼ��� : ", i);
                        scanf_s("%d", &list[i]);
                    }


                    Sleep(1000);
                    clsWin();
                    quick_sort(max, list);

                }
                //�� ����
                else if (algoC == 5)
                {
                    clsWin();
                    gotoxy(10, 10);
                    printf("������ �迭�� ũ�⸦ �Է��ϼ��� (2�̻� 100����) >> ");
                    scanf_s("%d", &max);

                    for (int i = 0; i < max; i++)
                    {
                        gotoxy(10, 12 + i);
                        printf("�迭 %d���� ���� �Է��ϼ��� : ", i);
                        scanf_s("%d", &list[i]);
                    }


                    Sleep(1000);
                    clsWin();
                    heap_sort(max, list);

                }
                //��������
                else if (algoC == 6)
                {
                    clsWin();
                    gotoxy(10, 10);
                    printf("������ �迭�� ũ�⸦ �Է��ϼ��� (2�̻� 100����) >> ");
                    scanf_s("%d", &max);

                    for (int i = 0; i < max; i++)
                    {
                        gotoxy(10, 12 + i);
                        printf("�迭 %d���� ���� �Է��ϼ��� : ", i);
                        scanf_s("%d", &list[i]);
                    }


                    Sleep(1000);
                    clsWin();
                    merge_sort(max, list);
                }
                //�������
                else if (algoC == 7)
                {
                    clsWin();
                    gotoxy(10, 10);
                    printf("������ �迭�� ũ�⸦ �Է��ϼ��� (2�̻� 100����) >> ");
                    scanf_s("%d", &max);

                    for (int i = 0; i < max; i++)
                    {
                        gotoxy(10, 12 + i);
                        printf("�迭 %d���� ���� �Է��ϼ��� : ", i);
                        scanf_s("%d", &list[i]);
                    }


                    Sleep(1000);
                    clsWin();
                    radix_sort(max, list);
                }
                //�������3
                else if (algoC == 8)
                {
                    clsWin();
                    gotoxy(10, 10);
                    printf("������ �迭�� ũ�⸦ �Է��ϼ��� (2�̻� 100����) >> ");
                    scanf_s("%d", &max);

                    for (int i = 0; i < max; i++)
                    {
                        gotoxy(10, 12 + i);
                        printf("�迭 %d���� ���� �Է��ϼ��� : ", i);
                        scanf_s("%d", &list[i]);
                    }


                    Sleep(1000);
                    clsWin();
                    counting_sort(list, max);
                }
                //�ڷΰ���
                else
                {

                }
            }
            //Ʈ�� �˰���
            else if (algoC == 1) {
                clsWin();
                algoC = coiceAlgo2();
                if (algoC == 1) {

                }
                else if (algoC == 1) {

                }
                //�ڷΰ���
                else {

                }
            }
            //��¼�� �˰���
            else if (algoC == 2) {
                clsWin();
                algoC = coiceAlgo3();
                if (algoC == 1) {

                }
                else if (algoC == 1) {

                }
                //�ڷΰ���
                else {

                }
            }

            
        }

    }
    else if (startC == 1) {
        clsWin();
        printf("�����մϴ�...");
    }

    return 0;
}