#include <stdio.h>
#include <locale.h>

void homework(void) 
{
    double x, y;
    printf("\n=== ДЗ (вариант 19): принадлежность точки области ===\n");
    printf("Введите x y: ");
    if (scanf("%lf %lf", &x, &y) != 2) {
        printf("Ошибка ввода!\n");
        return;
    }

    /* Контрольный пример:
       (0, 1)  -> внутри
       (0, 5)  -> снаружи (выше вершины)
       (-3,-1) -> на границе (засчитываем как внутри)
    */

    double left_top = (4.0 / 3.0) * x + 3.0;   /* сторона AB */
    double right_top = -(3.0 / 2.0) * x + 3.0;   /* сторона BC */
    double bottom_line = -(1.0 / 12.0) * x - 1.25; /* сторона AC */

    int inside = (y <= left_top) && (y <= right_top) && (y >= bottom_line);

    if (inside)
        printf("Точка (%.2f, %.2f) принадлежит области\n", x, y);
    else
        printf("Точка (%.2f, %.2f) НЕ принадлежит области\n", x, y);
}

/* ===================== MAIN ===================== */
int main(void) {
    setlocale(LC_ALL, "Russian");
    int choice;

    do {
        printf("\n=====================================\n");
        printf("  ДЗ 6, вариант 19\n");
        printf("=====================================\n");
        printf("1 - Проверить точку\n");
        printf("0 - Выход\n");
        printf("Выбор: ");

        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода!\n");
            break;
        }

        switch (choice) {
        case 1: homework(); break;
        case 0: printf("Выход.\n"); break;
        default: printf("Нет такого пункта.\n");
        }
    } while (choice != 0);

    return 0;
}