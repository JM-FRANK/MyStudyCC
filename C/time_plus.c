#include <conio.h> // 用于 _kbhit() 和 _getch()
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int totalSeconds = 0;
    char input[100];
    int hours = 0, minutes = 0, seconds = 0;
    int valid_input = 1;

    printf("Time Accumulator - Press 'p' anytime to exit\n\n");

    while(1) {
        // 重置时间值
        hours = 0;
        minutes = 0;
        seconds = 0;
        valid_input = 1;

        // 输入提示
        printf("Enter time (Format: xxhxxmxxs) or press 'p' to exit: ");

        // 逐字符读取输入，允许中途退出
        int i = 0;
        char ch;
        while((ch = _getch()) != '\r') { // 按Enter键结束输入
            if(ch == 'p' || ch == 'P') {
                printf("\nExiting program...\n");
                goto exit_program;
            }

            // 回显输入字符
            printf("%c", ch);
            input[i++] = ch;

            if(i >= sizeof(input) - 1) {
                printf("\nInput too long! Please try again.\n");
                valid_input = 0;
                break;
            }
        }
        input[i] = '\0';
        printf("\n"); // 换行

        if(!valid_input)
            continue;

        // 解析输入字符串
        char *ptr = input;
        int value = 0;
        while(*ptr) {
            if(isdigit(*ptr)) {
                value = value * 10 + (*ptr - '0');
            } else if(*ptr == 'h' || *ptr == 'm' || *ptr == 's') {
                switch(*ptr) {
                case 'h':
                    hours = value;
                    break;
                case 'm':
                    minutes = value;
                    break;
                case 's':
                    seconds = value;
                    break;
                }
                value = 0;
            } else {
                valid_input = 0;
                break;
            }
            ptr++;
        }

        // 验证输入有效性
        if(!valid_input || value != 0) {
            printf("Invalid format! Please use xxhxxmxxs (e.g., 1h30m45s).\n");
            continue;
        }

        // 验证非负性
        if(hours < 0 || minutes < 0 || seconds < 0) {
            printf("Invalid time! Hours, minutes, and seconds must be "
                   "non-negative.\n");
            continue;
        }

        // 累加总秒数
        totalSeconds += hours * 3600 + minutes * 60 + seconds;

        // 显示当前累计结果
        int displayHours = totalSeconds / 3600;
        int displayMinutes = (totalSeconds % 3600) / 60;
        int displaySeconds = totalSeconds % 60;

        printf("Current Total: %02d:%02d:%02d\n\n", displayHours,
               displayMinutes, displaySeconds);
    }

exit_program:
    // 计算最终结果
    int finalHours = totalSeconds / 3600;
    int finalMinutes = (totalSeconds % 3600) / 60;
    int finalSeconds = totalSeconds % 60;

    // 输出最终结果
    printf("\nFinal Result:\n");
    printf("Total Hours: %d\n", finalHours);
    printf("Formatted Time: %02d:%02d:%02d\n", finalHours, finalMinutes,
           finalSeconds);

    system("pause");
    return 0;
}
