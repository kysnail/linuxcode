/*
 * =====================================================================================
 *
 *       Filename:  more01.c
 *
 *    Description:  read and print 24 lines then paus for a few special commands.
 *
 *        Version:  more01.c - version 0.1 of more
 *        Created:  08/29/2012 03:14:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define PAGELEN 24
#define LINELEN 512

void do_more(FILE *);
int see_more();

int main(int ac, char *av[])
{
        FILE *fp;
        if (ac == 1)                    // <--- 如果 ac 等于 1 ，表示需要从标准输入获取数据。
                do_more(stdin);         // <--- 然后在这里调用相应的显示方法。
        else
                while(--ac)             // <--- 这里 --ac 和 ++av 的配合相当华丽！ 赞一个！
                if((fp = fopen(*++av, "r")) != NULL)
                {
                        do_more(fp);
                        fclose(fp);
                }
                else
                        exit(1);
        return 0;
}

void do_more(FILE *fp)
/*
 * read PAGELEN lines, then call see_more() for further instructions
 */
{
        char line[LINELEN];
        int  num_of_lines = 0;
        int  see_more(), reply;
        while (fgets(line, LINELEN, fp)) {                              /* more input */
                if (num_of_lines == PAGELEN) {                          /* full screen? 第一次进入时，显然不会执行了。 */
                        reply = see_more();                             /* y: ask user */
                        if (reply == 0)                                 /* n: done */
                                break;
                        num_of_lines -= reply;                          /* reset count */
                        // <--- 如果让你设计这个计数量 num_of_lines ，你会怎样做呢？
                        // 我感觉这里的做法很好，num_of_lines 相当于一个游标，其满盈由 reply 变量
                        // 进行控制。
                }
                if (fputs(line, stdout) == EOF)                         /* show line */
                        exit(1);                                        /* or die */
                num_of_lines++;                                         /* count it */
                // <--- 看代码的方法，比如这里 num_of_lines 在 52 行看到时，可能还有些纳闷，因为在此之前没有地方
                // 会改变它的值。不要怀疑基本的逻辑，它一定会在后面的某个部位被修改，否则上面的这个条件永远无法
                // 进入。
        }
}

int see_more()
/*
 * print message, wait for response, return # of lines to advance
 * q means no, space means yes, CR means one line
 */
{
        int c;
        printf("\033[7m more? \033[m");                                 /* reverse on a vt100 */
        while ((c = getchar()) != EOF)                                  /* get response */
        {
                if (c == 'q')                                           /* q -> N */
                        return 0;
                if (c == ' ')                                           /* ' ' => next page */
                        return PAGELEN;                                 /* :w */
                if (c == '\n')                                          /* Enter key => 1 line */
                        return 1;
        }

        return 0;
}

