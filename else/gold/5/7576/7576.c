// // shit

// #include <stdio.h>
// #include <stdlib.h>

// int** farm;
// int width, height;

// int main() {
//     scanf("%d %d", &width, &height);

//     farm = (int**) malloc(sizeof(int*) * height);
//     for(int i = 0; i < height; i++) {
//         farm[i] = (int*) malloc(sizeof(int) * width);
//     }

//     int notTomatoCount = 0;
//     for(int y = 0; y < height; y++) {
//         for(int x = 0; x < width; x++) {
//             int num;
//             scanf("%d", &num);

//             if(num == -1) {
//                 notTomatoCount++;
//             }
//             farm[y][x] = num;
//         }
//     }
//     int canFullTomatoCount = width * height - notTomatoCount;

//     printf("\n");
//     int requiredDay = 1;
//     while(1) {
//         int cantTomato = 1;
//         int goodTomatoCount = 0;
//         for(int y = 0; y < height; y++) {
//             for(int x = 0; x < width; x++) {
//                 if(farm[y][x] > 0) {
//                     goodTomatoCount++;
//                 }

//                 if(farm[y][x] >= requiredDay) {
//                     if(x > 0 && farm[y][x - 1] == 0) { // left
//                         farm[y][x - 1] = requiredDay + 1;
//                         cantTomato = 0;
//                     }
//                     if(y + 1 <= height - 1 && farm[y + 1][x] == 0) { // down
//                         farm[y + 1][x] = requiredDay + 1;
//                         cantTomato = 0;
//                     }
//                     if(y > 0 && farm[y - 1][x] == 0) { // up
//                         farm[y - 1][x] = requiredDay + 1;
//                         cantTomato = 0;
//                     }
//                     if(x + 1 <= width - 1 && farm[y][x + 1] == 0) { // right
//                         farm[y][x + 1] = requiredDay + 1;
//                         cantTomato = 0;
//                     }
//                 }
//                 printf("%d ", farm[y][x]);
//             }
//             printf("\n");
//         }
//         printf("%d\n\n", requiredDay);

//         if(goodTomatoCount >= canFullTomatoCount) {
//             break;
//         }
//         else if(cantTomato == 1) {
//             requiredDay = 0;
//             break;

//         }
//         requiredDay++;
//     }

//     printf("%d", requiredDay - 1);

//     for(int i = 0; i < height; i++) {
//         free(farm[i]);
//     }

//     free(farm);

//     return 0;
// }