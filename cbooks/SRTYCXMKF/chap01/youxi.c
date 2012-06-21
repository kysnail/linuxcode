//----------------------------------------------------------------------------------------------------
// Include Section
//----------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <graphics.h>               // 图形函数库

//----------------------------------------------------------------------------------------------------
// Key Code Section
//----------------------------------------------------------------------------------------------------
// 定义按键码
#define VK_LEFT     0x4b00
#define VK_RIGHT    0x4d00
#define VK_DOWN     0x5000
#define VK_UP       0x4800
#define VK_ESC      0x011b
#define TIMER       0x1c            // 设置中断号

//----------------------------------------------------------------------------------------------------
// Constant Variable Section
//----------------------------------------------------------------------------------------------------
// 定义常量
#define MAX_BOX 19                          // 总共有 19 种形态的方块
#define BSIZE 20                            // 方块的边长是 20 个像素
#define Sys_x 160                           // 显示方块界面的左上角 x 坐标
#define Sys_y 25                            // 显示方块界面的左上角 y 坐标
#define Horizontal_boxes 10                 // 水平的方向以方块为单位的长度
#define Vertical_boxes 15                   // 垂直的方向以方块为单位的长度，也就说长是 15 个方块
#define Begin_boxes_x Horizontal_boxes 2    // 产生第一个方块时出现的起始位置

#define FgColor 3                           // 前景颜色，如文字。2-green
#define BgColor 0                           // 背景颜色，0-black

#define LeftWin_x Sys_x + Horizontal * BSIZE + 46   // 右边状态栏的 x 坐标

#define false 0
#define true 1

// 移动的方向
#define MoveLeft    1
#define MoveRight   2
#define MoveDown    3
#define MoveRoll    4
// 以后坐标的每个方块都可以看作像素点是 BSIZE*BSIZE 的正方形

//----------------------------------------------------------------------------------------------------
// Data Structure Section
//----------------------------------------------------------------------------------------------------
struct BOARD        // 游戏底板结构，表示每个点所具有的属性。
{
    int var;        // 当前状态只有 0 和 1，1 表示此点已被占用。
    int color;      // 颜色，游戏底板的每个点可以拥有不同的颜色，增强美观性。
}Table_board[Vertical_boxs][Horizontal_boxs];

struct SHAPE
{
    /*
     * 一个字节是 8 位，用每 4 位表示游戏方块中的一行，
     * 例如 box[0]="0x88", box[1]="0xc0" 表示的是：
     * 1000
     * 1000
     * 1100
     * 0000
     */
    char box[2];
    int color;      // 每个方块的颜色
    int next;       // 下个方块的编号
};

// 初始化方块内容，即定义 MAX_BOX 个 SHAPE 类型的结构数组，并初始化。
struct SHAPE shapes[MAX_BOX] =
{
    /*
     *  □       □ □ □  □ □          □    
     *  □       □        □      □ □ □ 
     *  □□               □  
     */
    { 0x88, 0xc0,   CYAN,   1},
    { 0xe8, 0x0,    CYAN,   2},
    { 0xc4, 0x40,   CYAN,   3},
    { 0x2e, 0x0,    CYAN,   0},

    /*
     *    □             □ □  □ □ □    
     *    □    □        □        □ 
     *  □ □    □ □ □ □  □           
     */
    { 0x44, 0xc0,   MAGENTA,   5},
    { 0x8e, 0x0,    MAGENTA,   6},
    { 0xc8, 0x80,   MAGENTA,   7},
    { 0xe2, 0x0,    MAGENTA,   4},

    /*
     *    □          
     *    □ □      □ □
     *      □    □ □
     */
    { 0x8c, 0x40,   YELLOW,   9},
    { 0x8e, 0x0,    YELLOW,   8},

    /*
     *      □          
     *    □ □    □ □
     *    □        □ □
     */
    { 0x4c, 0x80,   BROWN,   11},
    { 0x6c, 0x0,    BROWN,   10},

    /*
     *         □    □ □ □     □    
     *    □    □ □    □     □ □
     *  □ □ □  □              □ 
     */
    { 0x4e, 0x0,     WHITE,   13},
    { 0x8c, 0x80,    WHITE,   14},
    { 0xe4, 0x0,     WHITE,   15},
    { 0x4c, 0x40,    WHITE,   12},

    /*     
     *    □
     *    □          
     *    □    □ □ □ □
     *    □             
     */
    { 0x88, 0x88,   RED,   17},
    { 0xf0, 0x0,    RED,   16},

    /*     
     *    □ □
     *    □ □            
     */
    { 0xcc, 0x0,    BLUE,   18}
};

//----------------------------------------------------------------------------------------------------
// Function Declaration
//----------------------------------------------------------------------------------------------------
void interrupt newtimer(void);
void SetTimer(void interrupt(*IntProc) (void));
void KillTimer();
void initialize(int x, int y, int m, int n);
void DelFullRow(int y);
void SetFullRow(int t_boardy);
int MkNextBox(int box_numb);
void EraseBox(int x, int y, int box_numb);
void show_box(int x, int y, int box_numb, int color);
int MoveAble(int x, int y, int box_numb, int direction);

